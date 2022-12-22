package pt.isec.pd.client.model.data.threads;

import javafx.application.Platform;
import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.ClientData;
import pt.isec.pd.shared_data.ListServerAddress;
import pt.isec.pd.shared_data.Responses.*;
import pt.isec.pd.shared_data.ServerAddress;
import pt.isec.pd.shared_data.UpdateServerList;
import pt.isec.pd.utils.Exceptions.NoServerFound;
import pt.isec.pd.utils.Log;

import java.beans.PropertyChangeSupport;
import java.io.IOException;
import java.io.SyncFailedException;
import java.util.List;

public class ResponseHandler extends Thread {
    private final Log LOG = Log.getLogger(Client.class);
    private final CommunicationHandler ch;
    private final PropertyChangeSupport pcs;
    private Object data;
    private final ClientData clientData;
    private boolean isConnected = true;
    public ResponseHandler(CommunicationHandler ch, PropertyChangeSupport pcs, ClientData clientData) {
        this.pcs = pcs;
        this.ch = ch;
        this.clientData = clientData;
    }

    @Override
    public void run() {
        while (isConnected) {
            try {
                Object object = ch.getOis().readObject();
                data = object;
                LOG.log("Response received: " + data.getClass().getSimpleName().toUpperCase());

                if(object instanceof RegisterResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.REGISTER.toString(),null,null));
                }
                else if (object instanceof LoginResponse loginResponse) {
                    Platform.runLater(() -> {
                        //Sets the id and admin parameters
                        synchronized (clientData) {
                            clientData.setId(loginResponse.getId());
                            clientData.setAdmin(loginResponse.isAdmin());
                        }
                        pcs.firePropertyChange(ClientAction.LOGIN.toString(),null,null);
                    });
                }
                else if (object instanceof EditResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.EDIT_DATA.toString(),null,null));
                }
                else if (object instanceof ShowsResponse showsResponse) {
                    if (showsResponse.getAction() == ClientAction.SELECT_SHOWS) {
                        Platform.runLater(() -> pcs.firePropertyChange(ClientAction.SELECT_SHOWS.toString(),null,null));
                    } else if (showsResponse.getAction() == ClientAction.CONSULT_SHOWS_ALL) {
                        Platform.runLater(() -> pcs.firePropertyChange(ClientAction.CONSULT_SHOWS_ALL.toString(),null,null));
                    }
                }
                else if (object instanceof SeatsResponse seatsResponse) {
                    Platform.runLater(() -> {
                        if (clientData.getShowId() == seatsResponse.getShowId()) {
                            pcs.firePropertyChange(ClientAction.VIEW_SEATS_PRICES.toString(),null,null);
                        }
                    });
                }
                else if (object instanceof InsertShowResponse insertShowResponse) {
                    if (insertShowResponse.isSuccess()) {
                        Platform.runLater(() -> ch.writeToSocket(ClientAction.CONSULT_SHOWS_ALL,null));
                    } else {
                        Platform.runLater(() -> pcs.firePropertyChange(ClientAction.INSERT_SHOWS.toString(),null,null));
                    }
                }
                else if (object instanceof DeleteResponse deleteResponse) {
                    if (deleteResponse.isSuccess()) {
                        Platform.runLater(() -> ch.writeToSocket(ClientAction.CONSULT_SHOWS_ALL,null));
                    } else {
                        Platform.runLater(() -> pcs.firePropertyChange(ClientAction.DELETE_SHOW.toString(),null,null));
                    }
                }
                else if (object instanceof HandleVisibleShowResponse handleVisibleShowResponse) {
                    if (handleVisibleShowResponse.isSuccess()) {
                        Platform.runLater(() -> ch.writeToSocket(ClientAction.CONSULT_SHOWS_ALL,null));
                    } else {
                        Platform.runLater(() -> pcs.firePropertyChange(ClientAction.VISIBLE_SHOW.toString(),null,null));
                    }
                }
                else if (object instanceof SubmitReservationResponse submitReservationResponse) {
                    if (submitReservationResponse.isSuccess()) {
                        Platform.runLater(() -> {
                            pcs.firePropertyChange(ClientAction.SUBMIT_RESERVATION.toString(),null,null);
                            ch.writeToSocket(ClientAction.VIEW_SEATS_PRICES,null);
                        });
                    } else {
                        Platform.runLater(() -> {
                            pcs.firePropertyChange(ClientAction.SUBMIT_RESERVATION.toString(),null,null);
                        });
                    }
                }
                else if (object instanceof DeleteReservationResponse) {
                    Platform.runLater(() -> {
                        pcs.firePropertyChange(ClientAction.DELETE_UNPAID_RESERVATION.toString(),null,null);
                        ch.writeToSocket(ClientAction.CONSULT_PAYMENTS_AWAITING,null);
                    });
                }
                else if (object instanceof PayReservationResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.PAY_RESERVATION.toString(),null,null));
                }
                else if (object instanceof DisconnectResponse) {
                    LOG.log("Disconnecting");
                    isConnected = false;
                    break;
                }
                else if (object instanceof ConsultPayedReservationResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.CONSULT_PAYED_RESERVATIONS.toString(),null,null));
                }
                else if (object instanceof ConsultUnpayedReservationResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.CONSULT_PAYMENTS_AWAITING.toString(),null,null));
                }
                else if (object instanceof ConsultShowsFilterResponse) {
                    Platform.runLater(() -> pcs.firePropertyChange(ClientAction.CONSULT_SHOWS_VISIBLE.toString(),null,null));
                }
                else if (object instanceof ListServerAddress list) {
                    try {
                        LOG.log("Establishing connection to a new server");
                        ch.establishingTcpConn(list.getServers());
                    } catch (NoServerFound e) {
                        e.printStackTrace();
                    }
                }
                else if (object instanceof SyncFailedException) {
                    Platform.runLater(() ->pcs.firePropertyChange("notify",null,null));
                }
                else if (object instanceof UpdateServerList updateServerList) {
                    ch.setServerList(updateServerList.getServerAddressList());
                }
            } catch (IOException e) {
                if (isConnected) {
                    LOG.log("There was a problem with the server we are trying to fix it " + e);
                    ch.sendPing();
                }
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized Object getResponse() {
        return data;
    }
}
