package pt.isec.pd.ex11_12;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.MulticastSocket;

public class ReceiveMessages extends Thread {
    private MulticastSocket ms;

    public ReceiveMessages(MulticastSocket ms) {
        this.ms = ms;
    }

    @Override
    public void run() {
        try {
            while(true) {
                DatagramPacket dp = new DatagramPacket(new byte[256],256);
                ms.receive(dp);

                ByteArrayInputStream bais = new ByteArrayInputStream(dp.getData());
                ObjectInputStream ois = new ObjectInputStream(bais);
                try {
                    Object object  = ois.readObject();
                    if (object instanceof String msgStr) {
                        System.out.println("String class: " + msgStr);
                    } else {
                        Msg msg = (Msg) object;
                        System.out.println("Msg Class: " + msg.toString());
                    }
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
