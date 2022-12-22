package pt.isec.pd.server.threads.heart_beat;

import pt.isec.pd.server.data.HeartBeatController;
import pt.isec.pd.utils.Constants;
import pt.isec.pd.utils.Utils;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class HeartBeatSender extends Thread {
    private final MulticastSocket ms;
    private final HeartBeatController controller;

    public HeartBeatSender(HeartBeatController controller) {
        this.ms = controller.getMs();
        this.controller = controller;
    }

    @Override
    public void run() {
        send();
    }

    public void send() {
        while(true) {
            try {
                byte[] bytes = Utils.serializeObject(controller.updateHeartBeat());

                DatagramPacket dp = new DatagramPacket(bytes,bytes.length, InetAddress.getByName(Constants.IP_MULTICAST),Constants.PORT_MULTICAST);
                ms.send(dp);

                Thread.sleep(Constants.SEND_HEARTBEAT * Constants.TO_SECONDS);
            } catch (InterruptedException | IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
