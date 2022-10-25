package pt.isec.pd.ex10;

import pt.isec.pd.ex10.util.Log;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Calendar;

public class ThreadClient extends Thread {
    private Socket socket;
    private ArrayList<String> logs;
    private static final Log LOG = Log.getLogger(ServerTCP.class);

    public ThreadClient(Socket socket, ArrayList<String> logs) {
        this.socket = socket;
        this.logs = logs;
    }

    @Override
    public void run() {
        // Inicializar oos em primeiro lugar
        try {
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

            String msgRec = (String) ois.readObject();

            LOG.log("Client Message: " + msgRec);

            if (msgRec.equals("TIME")) {
                Calendar calendar = Calendar.getInstance();
                ServerCurrentTime slt = new ServerCurrentTime(calendar.get(Calendar.HOUR_OF_DAY),calendar.get(Calendar.MINUTE),calendar.get(Calendar.SECOND));

                try {
                    Thread.sleep(1000);
                } catch(InterruptedException e) {
                    throw new RuntimeException(e);
                }

                oos.writeUnshared(slt);

                synchronized (logs) {
                    logs.add("Sent message: " + slt);
                }
            }

            socket.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
