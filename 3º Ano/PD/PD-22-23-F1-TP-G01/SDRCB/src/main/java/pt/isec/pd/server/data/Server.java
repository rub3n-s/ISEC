package pt.isec.pd.server.data;

import pt.isec.pd.server.data.database.CreateDataBase;
import pt.isec.pd.server.data.database.DBHandler;
import pt.isec.pd.server.threads.client.ClientManagement;
import pt.isec.pd.server.threads.client.ClientReceiveMessage;
import pt.isec.pd.utils.Log;

import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.sql.SQLException;
import java.util.List;

public class Server {
    private final Log LOG = Log.getLogger(Server.class);
    private HeartBeatList hbList;
    private String ip;
    private ClientManagement cm;
    private final String dbPath;
    private HeartBeatController hbController;
    private DBHandler dbHandler;
    private Scanf scanf;

    public Server(int pingPort,String dbPath) {
        this.dbPath = dbPath;
        scanf = new Scanf();
        scanf.start();

        try {
            ip = InetAddress.getLocalHost().getHostAddress();
            System.out.println("Device ip: " + ip);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        init(pingPort);
        start();
    }

    public String getIp() {
        return ip;
    }

    public void init(int pingPort) {
        hbList = new HeartBeatList();

        File f = new File(dbPath);
        if(!f.exists() && !f.isDirectory()) {
            LOG.log("Data base create: " + dbPath);
            new CreateDataBase(dbPath);
        }

        dbHandler = new DBHandler(dbPath);

        hbController = new HeartBeatController(hbList,this);
        cm = new ClientManagement(pingPort, dbHandler,hbList, hbController,ip);
    }

    public void start() {
        hbController.start();

        cm.startPingHandler();
        cm.start();
    }

    public int getServerPort() {
        return cm.getServerPort();
    }

    public int getDBVersion() {
        return dbHandler.getCurrentVersion();
    }

    public synchronized int getActiveConnections() {
        return cm.getNumConnections();
    }

    public synchronized DBHandler getDbHandler() {
        return dbHandler;
    }

    public synchronized List<ClientReceiveMessage> getClients() {
        return cm.getClientsThread();
    }
}
