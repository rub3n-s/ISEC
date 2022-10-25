package pt.isec.pd.ex10;

import pt.isec.pd.ex10.util.Log;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Calendar;

public class ThreadClientRunnable implements Runnable {
    private Socket socket;
    private static final Log LOG = Log.getLogger(ServerTCP.class);

    public ThreadClientRunnable(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        //Initialize oos in first place
        try {
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois  = new ObjectInputStream(socket.getInputStream());

            String msgRec = (String) ois.readObject();

            LOG.log("Client message: " + msgRec);

            if (msgRec.equals("TIME")) {
                Calendar calendar = Calendar.getInstance();
                ServerCurrentTime slt = new ServerCurrentTime(calendar.get(Calendar.HOUR_OF_DAY),calendar.get(Calendar.MINUTE),calendar.get(Calendar.SECOND));

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            socket.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
