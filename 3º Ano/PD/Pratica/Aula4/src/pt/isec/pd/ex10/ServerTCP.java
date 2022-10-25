package pt.isec.pd.ex10;

import pt.isec.pd.ex10.util.Log;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class ServerTCP {
    private static final int PORT = 9001;
    private static final Log LOG = Log.getLogger(ServerTCP.class);

    public static void main(String[] args) throws IOException, InterruptedException {
        boolean keepGoing = true;
        List<ThreadClient> clients = new ArrayList<>();
        ServerSocket serverSocket = new ServerSocket(PORT);
        ArrayList<String> logs = new ArrayList<>();

        LOG.log("Socket initialized...");

        while(keepGoing) {
            LOG.log("Waiting for client...");

            // aceitar o cliente que chegou
            Socket socket = serverSocket.accept();

            LOG.log("Client " + socket.getInetAddress().getHostAddress() +
                    ":" + socket.getPort() + " has joined...");

            // adicionar a thread à lista de thraeds de clientes
            clients.add(new ThreadClient(socket,logs));
            // iniciar a thread
            clients.get(clients.size() - 1).start();

            // RUNNABLE
            /*ThreadClientRunnable threadClientRunnable = new ThreadClientRunnable(socket);
            Thread thread = new Thread(threadClientRunnable);
            thread.start();*/
        }

        for (ThreadClient client : clients)
            client.join();

        serverSocket.close();
    }
}
