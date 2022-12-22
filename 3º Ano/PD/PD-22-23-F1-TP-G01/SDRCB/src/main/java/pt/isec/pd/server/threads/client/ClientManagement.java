package pt.isec.pd.server.threads.client;

import pt.isec.pd.server.data.HeartBeatController;
import pt.isec.pd.server.data.HeartBeatList;
import pt.isec.pd.server.data.Server;
import pt.isec.pd.server.data.database.DBHandler;
import pt.isec.pd.shared_data.HeartBeat;
import pt.isec.pd.utils.Log;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class ClientManagement extends Thread {
    private final Log LOG = Log.getLogger(Server.class);
    private ServerSocket serverSocket;
    private ClientPingHandler pingHandler;
    private boolean isConnected = true;             // validate if the user is connected
    private DBHandler dbHandler;
    private Integer numConnections = 0;
    private HeartBeatController hbController;
    private List<ClientReceiveMessage> clientsThread = new ArrayList<>();
    private ArrayList<ClientReceiveMessage> viewingSeats = new ArrayList<>();

    public ClientManagement(int pingPort, DBHandler dataBaseHandler, HeartBeatList hbList, HeartBeatController hbController,String ip) {
        try {
            this.hbController = hbController;
            this.serverSocket = new ServerSocket(0);
            this.pingHandler = new ClientPingHandler(pingPort, hbList);
            this.dbHandler = dataBaseHandler;
            this.clientsThread = new ArrayList<>();
            this.viewingSeats = new ArrayList<>();
            hbList.add(new HeartBeat(serverSocket.getLocalPort(), true, dbHandler.getCurrentVersion(), 0, ip));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //Handles the connection of the clients and instantiates a new Thread for the client
    @Override
    public void run() {
        try {
            while (isConnected) {
                Socket socket = serverSocket.accept();
                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

                //Update db
                if((Integer) ois.readObject() == 0) {
                    int version = (Integer) ois.readObject();
                    Map<Integer,List<String>> versionQuerys = dbHandler.getListOfQuery(version,dbHandler.getCurrentVersion());
                    oos.writeObject(versionQuerys);
                } else {
                    incConnection();
                    LOG.log("New connection established: " + numConnections);

                    // Creates a thread for that client
                    ClientReceiveMessage clientRM = new ClientReceiveMessage(oos,ois, dbHandler, this,hbController);
                    clientRM.start();

                    hbController.sendHeartBeat();
                    clientsThread.add(clientRM);
                }
            }
        } catch (IOException | ClassNotFoundException | SQLException e ) {
            e.printStackTrace();
        }
    }

    public void startPingHandler() {
        pingHandler.start();
    }

    public int getServerPort() {
        return serverSocket.getLocalPort();
    }

    public int getNumConnections() {
        return numConnections;
    }

    public synchronized List<ClientReceiveMessage> getClientsThread() {
        return clientsThread;
    }

    public synchronized void incConnection() {
        numConnections++;
    }

    public synchronized void subConnection() {
        numConnections--;
    }
}
