package pt.isec.pd.server.threads.client;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.ClientData;
import pt.isec.pd.server.data.HeartBeatController;
import pt.isec.pd.server.data.Server;
import pt.isec.pd.server.data.database.DBHandler;
import pt.isec.pd.shared_data.Responses.SubmitReservationResponse;
import pt.isec.pd.utils.Log;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.SyncFailedException;
import java.sql.SQLException;
import java.util.*;

public class ClientReceiveMessage extends Thread {
    private final Log LOG = Log.getLogger(Server.class);
    private final HeartBeatController hbController;
    private final DBHandler dbHandler;
    private ObjectOutputStream oos;
    private final ObjectInputStream ois;
    private final ClientManagement clientManagement;
    private final List<ClientData> queue = new ArrayList<>();
    private final QueueUpdate queueUpdate;
    private Timer t = new Timer();
    
    private List<Submission> submissions = new ArrayList<>();
    private ClientData clientData;

    public ClientReceiveMessage(ObjectOutputStream oos, ObjectInputStream ois, DBHandler dbHandler, ClientManagement clientManagement, HeartBeatController controller) {
        this.oos = oos;
        this.ois = ois;
        this.hbController = controller;
        this.dbHandler = dbHandler;
        this.clientManagement = clientManagement;
        queueUpdate = new QueueUpdate(controller,queue,this);
        queueUpdate.start();
    }

    @Override
    public synchronized void run() {
        while (true) {
            try {
                // Verifications for the clients actions
                clientData = (ClientData) ois.readObject();
                request(clientData);
            } catch (ClassNotFoundException e) {
                LOG.log("Unable to read client data: " + e);
            } catch (IOException e) {
                LOG.log("Client left");
                clientManagement.subConnection();
                clientManagement.getClientsThread().remove(this);
                oos = null;
                if (!(clientData.getAction() == ClientAction.DISCONNECTED)) {
                    clientData.setAction(ClientAction.DISCONNECTED);
                    request(clientData);
                }
                break;
            }
        }
    }

    public void request(ClientData clientData) {
        if (!hbController.isUpdating() && queue.isEmpty()) {
            handleClientRequest(clientData);
        } else {
            queue.add(new ClientData(clientData));
            LOG.log("The request " + clientData.getAction() +  " was added to the queue!");
        }
    }

    public void handleClientRequest(ClientData clientData) {
        LOG.log("Execution " + clientData.getAction());
        try {
            Pair<Object,List<String>> sqlCommands = switch(clientData.getAction()) {
                case REGISTER -> dbHandler.register(clientData);
                case LOGIN -> dbHandler.login(clientData);
                case EDIT_NAME,EDIT_USERNAME,EDIT_PASSWORD -> dbHandler.editClientData(clientData);
                case CONSULT_PAYMENTS_AWAITING -> dbHandler.consultPaymentsAwaiting(clientData);
                case CONSULT_PAYED_RESERVATIONS -> dbHandler.consultPayedReservations(clientData);
                case CONSULT_SHOWS_VISIBLE -> dbHandler.consultShows(clientData);
                case CONSULT_SHOWS_ALL -> dbHandler.consultShowsAdmin();
                case SELECT_SHOWS -> dbHandler.selectShows();
                case VIEW_SEATS_PRICES -> dbHandler.viewSeatsAndPrices(clientData);
                case VISIBLE_SHOW -> dbHandler.showVisible(clientData);
                case SUBMIT_RESERVATION -> dbHandler.submitReservation(clientData);
                case DELETE_UNPAID_RESERVATION -> dbHandler.deleteUnpaidReservation(clientData);
                case PAY_RESERVATION -> dbHandler.payReservation(clientData);
                case INSERT_SHOWS -> dbHandler.insertShows(clientData);
                case DELETE_SHOW -> dbHandler.deleteShow(clientData);
                case DISCONNECTED -> dbHandler.disconnect(clientData);

                default -> throw new IllegalArgumentException("Unexpected action value");
            };

            //If db was updated, init the process of updating other servers db
            update(sqlCommands,clientData);
        }  catch (IOException | ClassNotFoundException | SQLException e) {
            LOG.log("Unable to read client data: " + e);
        }
    }

    private void update(Pair<Object, List<String>> sqlCommands, ClientData clientData) {
        boolean result = true;
        if (sqlCommands.getValue() != null) {
            result = hbController.updateDataBase(sqlCommands,clientData);
        }

        if (oos != null && result) {
            LOG.log("Sending response");
            try {
                oos.writeObject(sqlCommands.getKey());

                //SUBMIT_RESERVATION
                switch (clientData.getAction()) {
                    case SUBMIT_RESERVATION -> {
                        if (((SubmitReservationResponse) sqlCommands.getKey()).isSuccess()) {
                            ClientData submission = new ClientData(clientData);
                            submission.setAction(ClientAction.DELETE_UNPAID_RESERVATION);

                            TimerTask tt = new TimerTask() {
                                @Override
                                public void run() {
                                    request(submissions.get(0).getSubmit());
                                }
                            };

                            submissions.add(new Submission(submission,tt));

                            Calendar calendar = Calendar.getInstance(); // gets a calendar using the default time zone and locale.
                            calendar.add(Calendar.SECOND, 10);
                            t.schedule(tt, calendar.getTime());
                        }
                    }
                    case PAY_RESERVATION,DELETE_UNPAID_RESERVATION -> {
                            for (Submission submission : submissions) {
                                if (submission.getSubmit().getData().equals(clientData.getData())) {
                                    submission.getTask().cancel();
                                    LOG.log("Timer was canceled for reservation " + submission.getSubmit().getData());
                                    submissions.remove(submission);
                                    break;
                                }
                            }
                    }
                    default -> {}
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else if (oos != null) {
            try {
                LOG.log("Sending problem response");
                oos.writeObject(new SyncFailedException("The request was denied due to communication problems"));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public ObjectOutputStream getOos() {
        return oos;
    }

    public Timer getT() {
        return t;
    }
}
