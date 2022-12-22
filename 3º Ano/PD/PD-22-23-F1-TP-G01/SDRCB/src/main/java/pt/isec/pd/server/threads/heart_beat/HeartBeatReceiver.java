package pt.isec.pd.server.threads.heart_beat;

import pt.isec.pd.server.data.*;
import pt.isec.pd.server.data.database.DBHandler;
import pt.isec.pd.server.threads.client.ClientReceiveMessage;
import pt.isec.pd.shared_data.*;
import pt.isec.pd.shared_data.Responses.ShowsResponse;
import pt.isec.pd.utils.Constants;
import pt.isec.pd.utils.Log;
import pt.isec.pd.utils.Utils;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Map;

public class HeartBeatReceiver extends Thread{
    private final Log LOG = Log.getLogger(HeartBeatReceiver.class);
    private final MulticastSocket ms;
    private final HeartBeatList hbList;
    private final HeartBeatController controller;
    private final DBHandler dbHandler;
    private Prepare prepare;
    private Commit commit;
    private final Server server;
    private Date datePrepare;
    private Date dateCommit;

    public HeartBeatReceiver(HeartBeatController controller, DBHandler dbHandler,Server server) {
        this.ms = controller.getMs();
        this.hbList = controller.getHbList();
        this.controller = controller;
        this.dbHandler = dbHandler;
        this.server = server;
    }

    @Override
    public void run() {
        try {
            while(true) {
                DatagramPacket dp = new DatagramPacket(new byte[Constants.MAX_BYTES],Constants.MAX_BYTES);
                ms.receive(dp);
                Object object = Utils.deserializeObject(dp.getData());

                if (object instanceof HeartBeat hbEvent) {
                    boolean updated = hbList.updateList(hbEvent);
                    List<HeartBeat> hbDbVersion = new ArrayList<>(List.copyOf(hbList));
                    hbDbVersion.sort(new CompareDbVersionHeartBeat());

                    try {
                        if (!hbList.isEmpty() && controller.isEndOfStartup() && !controller.isUpdating()) {
                            HeartBeat highest = hbDbVersion.get(hbDbVersion.size() - 1);
                            if (controller.getHb().getDbVersion() < highest.getDbVersion()) {
                                controller.setAvailable(false);

                                //Update the list
                                hbList.removeIf(n -> (!n.isStatus()));

                                ListServerAddress list = new ListServerAddress();
                                list.setServers(hbList.getOrderList());

                                for (ClientReceiveMessage client : server.getClients()) {
                                    client.getOos().writeObject(list);
                                }

                                //Sends the heartBeat
                                byte[] bytes = Utils.serializeObject(controller.updateHeartBeat());
                                dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                                ms.send(dp);

                                int myVersion = dbHandler.getCurrentVersion();
                                HeartBeat hbNew = hbDbVersion.get(hbDbVersion.size() - 1);

                                LOG.log("Updating the server to the most recent version");
                                Socket socket = new Socket(hbNew.getIp(), hbNew.getPortTcp());

                                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

                                oos.writeObject(0);
                                oos.writeObject(myVersion);
                                Map<Integer,List<String>> update = (Map<Integer,List<String>>) ois.readObject();

                                dbHandler.updateToNewVersion(update);
                                controller.setAvailable(true);

                                bytes = Utils.serializeObject(controller.updateHeartBeat());
                                dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                                ms.send(dp);
                            }
                        }
                    } catch (SQLException | ClassNotFoundException e) {
                        e.printStackTrace();
                    }

                    if (updated) {
                        controller.sendUpdateServerList();
                    }
                }
                else if(object instanceof Prepare prepare) {
                    Date currentDate = new Date();
                    if (this.prepare == null || prepare.getNextVersion() != this.prepare.getNextVersion() || datePrepare.compareTo(currentDate) != 0) {
                        this.prepare = prepare;
                        datePrepare = currentDate;
                        controller.setUpdating(true);
                        LOG.log("Prepare receive action: " + prepare.getData().getAction() +  " version: " + prepare.getNextVersion() + " ip: " + prepare.getIp());

                        // 1. An update is needed
                        DatagramSocket ds = new DatagramSocket();
                        byte[] databaseVersion = Utils.serializeObject(prepare.getNextVersion());
                        DatagramPacket dpSend = new DatagramPacket(databaseVersion,0,databaseVersion.length, InetAddress.getByName(prepare.getIp()),prepare.getPort());
                        ds.send(dpSend);
                   }
                }
                else if(object instanceof Commit commit) {
                    Date currentDate = new Date();
                    if (this.commit == null || commit.getNextVersion() != this.commit.getNextVersion()  || dateCommit.compareTo(currentDate) != 0) {
                        this.commit = commit;
                        dateCommit = currentDate;
                        LOG.log("Commit receive: " + prepare.getData().getAction() + " version: " + commit.getNextVersion());
                        // 2. Update the database
                        dbHandler.updateDataBase(prepare.getUpdate());

                        switch (prepare.getData().getAction()) {
                            case SUBMIT_RESERVATION,DELETE_UNPAID_RESERVATION -> {
                                for (ClientReceiveMessage client : controller.getClients()) {
                                    client.getOos().writeObject(dbHandler.viewSeatsAndPrices(prepare.getData()).getKey());
                                }
                            }
                            case INSERT_SHOWS,VISIBLE_SHOW,DELETE_SHOW ->  {
                                for (ClientReceiveMessage client : controller.getClients()) {
                                    ShowsResponse response = (ShowsResponse) dbHandler.selectShows().getKey();
                                    response.setShowId(prepare.getData().getShowId());
                                    client.getOos().writeObject(response);
                                }
                            }
                        }

                        synchronized (controller) {
                            if (controller.imUpdating())
                                controller.notify();
                        }

                        byte[] bytes = Utils.serializeObject(controller.updateHeartBeat());
                        dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                        ms.send(dp);

                        controller.setUpdating(false);
                    }
                } else if (object instanceof Abort) {
                    LOG.log("Abort receive: " + prepare.getData().getAction());
                    synchronized (controller) {
                        if (controller.imUpdating())
                            controller.notify();
                    }
                    controller.setUpdating(false);
                }

            }

        } catch (IOException/* | SQLException | ClassNotFoundException*/ e) {
            throw new RuntimeException(e);
        }
    }
}
