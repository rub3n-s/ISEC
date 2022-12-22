package pt.isec.pd.server.data;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.ClientData;
import pt.isec.pd.server.data.database.DBHandler;
import pt.isec.pd.server.threads.client.ClientReceiveMessage;
import pt.isec.pd.server.threads.heart_beat.HeartBeatLifeTime;
import pt.isec.pd.server.threads.heart_beat.HeartBeatReceiver;
import pt.isec.pd.server.threads.heart_beat.HeartBeatSender;
import pt.isec.pd.shared_data.*;
import pt.isec.pd.utils.Constants;
import pt.isec.pd.utils.Log;
import pt.isec.pd.utils.Utils;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class HeartBeatController {
    private final Log LOG = Log.getLogger(HeartBeatController.class);
    private final Server server;
    private final DBHandler dbHandler;

    private HeartBeat hbEvent;
    private final HeartBeatReceiver receiver;
    private final HeartBeatSender sender;
    private final HeartBeatLifeTime lifeTimeChecker;
    private final HeartBeatList hbList;
    private Boolean updater = false;
    private Boolean updating = false;
    private boolean available = true;
    private boolean endOfStartup = false;

    private MulticastSocket ms;

    public HeartBeatController(HeartBeatList hbList, Server server) {
        joinGroup();

        this.server = server;
        this.dbHandler = server.getDbHandler();
        this.hbList = hbList;
        receiver = new HeartBeatReceiver(this,server.getDbHandler(),server);
        sender = new HeartBeatSender(this);
        lifeTimeChecker = new HeartBeatLifeTime(hbList,this);
    }

    private void joinGroup() {
        try {
            ms = new MulticastSocket(Constants.PORT_MULTICAST);
            InetAddress ipGroup = InetAddress.getByName(Constants.IP_MULTICAST);
            SocketAddress sa = new InetSocketAddress(ipGroup,Constants.PORT_MULTICAST);
            NetworkInterface ni = NetworkInterface.getByName("en0");
            ms.joinGroup(sa,ni);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        LOG.log("Joined the group");
    }

    public void start() {
        receiver.start();
        lifeTimeChecker.start();

        try {
            Thread.sleep(Constants.STARTUP * Constants.TO_SECONDS);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        List<HeartBeat> hbDbVersion = new ArrayList<>(List.copyOf(hbList));
        hbDbVersion.sort(new CompareDbVersionHeartBeat());

        if (!hbDbVersion.isEmpty()) {
            try {
                int myVersion = dbHandler.getCurrentVersion();
                HeartBeat hbNew = hbDbVersion.get(hbDbVersion.size() - 1);

                if (myVersion < hbDbVersion.get(hbDbVersion.size() - 1).getDbVersion()) {
                    LOG.log("Updating the server to the most recent version");
                    Socket socket = new Socket(hbNew.getIp(), hbNew.getPortTcp());

                    ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                    ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

                    oos.writeObject(0);
                    oos.writeObject(myVersion);
                    Map<Integer,List<String>> versionQuerys = (Map<Integer,List<String>>) ois.readObject();

                    dbHandler.updateToNewVersion(versionQuerys);

                    byte[] bytes = Utils.serializeObject(updateHeartBeat());
                    DatagramPacket dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                    ms.send(dp);
                }
            }
            catch (SQLException | IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        endOfStartup = true;
        sender.start();
    }

    public synchronized void sendUpdateServerList() {
        for (ClientReceiveMessage client : getClients()) {
            UpdateServerList serverList = new UpdateServerList();
            serverList.setServerAddressList(hbList.getOrderList());
            try {
                client.getOos().writeObject(serverList);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized boolean isAvailable() {
        return available;
    }

    public synchronized void setAvailable(boolean available) {
        this.available = available;
    }

    public synchronized HeartBeat updateHeartBeat() {
        hbEvent = new HeartBeat(server.getServerPort(),isAvailable(), server.getDBVersion(), server.getActiveConnections(),server.getIp());
        return hbEvent;
    }

    public synchronized HeartBeat getHb() {
        return hbEvent;
    }

    // Only called when a request from client updated the database
    public synchronized boolean updateDataBase(Pair<Object, List<String>> sqlCommand, ClientData clientData) {
        setUpdater(true);
        boolean r = false;

        if (sqlCommand.getValue().isEmpty()){
            return true;
        }

        try {
            DatagramPacket dp;

            DatagramSocket ds = new DatagramSocket();
            ds.setSoTimeout(1000);

            // 1. Send the 'prepare' object to the multicast
            Prepare prepare = new Prepare(ds.getLocalPort(),server.getIp(),sqlCommand.getValue(),clientData,dbHandler.getCurrentVersion() + 1);
            LOG.log("Action: " + clientData.getAction() + " SqlCommands: " + sqlCommand.getValue().size() + " port: " + ds.getLocalPort());
            byte[] prepareBytes = Utils.serializeObject(prepare);

            dp = new DatagramPacket(prepareBytes,prepareBytes.length,InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
            ms.send(dp);

            // 2. Wait for the servers to send the signal (timeout 1000 ms)
            int servers = 0;
            int attempts = 0;

            DatagramPacket dpReceive = new DatagramPacket(new byte[Constants.MAX_BYTES],Constants.MAX_BYTES);
            while (true) {
                try {
                    ds.receive(dpReceive);
                    servers++;
                    LOG.log("Ping " + servers + "/" + hbList.size());

                } catch (SocketTimeoutException e) {
                    if (servers != hbList.size()) {
                        if (attempts == 1) {
                            break;
                        }
                        prepare = new Prepare(ds.getLocalPort(),server.getIp(),sqlCommand.getValue(),clientData,dbHandler.getCurrentVersion() + 1);
                        LOG.log("Action: " + clientData.getAction() + " SqlCommands: " + sqlCommand.getValue().size());
                        prepareBytes = Utils.serializeObject(prepare);

                        dp = new DatagramPacket(prepareBytes,prepareBytes.length,InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                        ms.send(dp);
                        LOG.log("Not all servers sent a confirmation trying again");
                        attempts++;
                        servers = 0;
                    } else {
                        break;
                    }
                }
            }

            if (attempts <= 0) {
                // 3. Send a 'commit' to start the updating
                Commit commit = new Commit(prepare.getNextVersion());
                byte[] commitBytes = Utils.serializeObject(commit);
                dp = new DatagramPacket(commitBytes,commitBytes.length,InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                ms.send(dp);
                r = true;
            } else {
                Abort abort = new Abort(prepare.getNextVersion());
                byte[] commitBytes = Utils.serializeObject(abort);
                dp = new DatagramPacket(commitBytes,commitBytes.length,InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                ms.send(dp);
                return false;
            }

            wait();
            setUpdater(false);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }

        return r;
    }


    public void setUpdater(Boolean updater) {
        this.updater = updater;
    }

    public Boolean imUpdating() {
        return updater;
    }

    public Boolean isUpdating() {
        return updating;
    }

    public void setUpdating(Boolean updating) {
        this.updating = updating;
    }

    public synchronized HeartBeatList getHbList() {
        return hbList;
    }

    public synchronized MulticastSocket getMs() {
        return ms;
    }

    public List<ClientReceiveMessage> getClients() {
        return server.getClients();
    }

    public synchronized boolean isEndOfStartup() {
        return endOfStartup;
    }

    public void sendHeartBeat() {
        try {
            byte[] bytes = Utils.serializeObject(updateHeartBeat());
            DatagramPacket dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
            ms.send(dp);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
