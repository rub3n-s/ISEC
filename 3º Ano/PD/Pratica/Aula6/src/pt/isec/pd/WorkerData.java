package pt.isec.pd;

import java.net.Socket;
public class WorkerData {
    static int counter = 0;
    int id;
    String address;
    int port;
    Socket socket;

    public WorkerData(String address, int port, Socket socket) {
        this.address = address;
        this.port = port;
        this.socket = socket;
        counter++;
        this.id = counter;
    }

    public int getId() { return id; }

    public String getAddress() { return address; }

    public int getPort() { return port; }

    public Socket getSocket() { return socket; }
}
