package pt.isec.pd.ex10;

import pt.isec.pd.ex10.util.Log;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientTCP {
    private static final int PORT = 9001;
    private static final Log LOG = Log.getLogger(ClientTCP.class);

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket socket = new Socket("localhost",PORT);

        LOG.log("Connection Established");

        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

        // escreve no socket para o server
        oos.writeObject("TIME");

        // recebe do server
        ServerCurrentTime time = (ServerCurrentTime) ois.readObject();
        LOG.log("Received: " + time);

        socket.close();
    }
}
