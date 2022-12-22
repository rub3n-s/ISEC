package pt.isec.pd.server.threads.client;

import pt.isec.pd.client.model.data.ClientData;
import pt.isec.pd.server.data.HeartBeatController;

import java.util.List;

public class QueueUpdate extends Thread {
    private final HeartBeatController controller;
    private final List<ClientData> queue;
    private final ClientReceiveMessage client;

    public QueueUpdate(HeartBeatController controller, List<ClientData> queue,ClientReceiveMessage client) {
        this.controller = controller;
        this.queue = queue;
        this.client = client;
    }

    @Override
    public void run() {
        while (true) {
            try {
                if (!controller.isUpdating() && !queue.isEmpty()) {
                    synchronized (queue) {
                        ClientData clientData = queue.remove(0);
                        client.handleClientRequest(clientData);
                    }
                }
                Thread.sleep(500);
            } catch (InterruptedException e ) {
                e.printStackTrace();
            }
        }
    }
}
