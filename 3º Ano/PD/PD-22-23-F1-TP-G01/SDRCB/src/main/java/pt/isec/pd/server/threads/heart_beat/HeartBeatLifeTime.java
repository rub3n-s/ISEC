package pt.isec.pd.server.threads.heart_beat;

import pt.isec.pd.server.data.HeartBeatController;
import pt.isec.pd.server.data.HeartBeatList;
import pt.isec.pd.server.data.Server;
import pt.isec.pd.server.threads.client.ClientReceiveMessage;
import pt.isec.pd.shared_data.UpdateServerList;
import pt.isec.pd.utils.Constants;
import pt.isec.pd.utils.Log;

import java.io.IOException;
import java.util.Date;

public class HeartBeatLifeTime extends Thread{
    private final Log LOG = Log.getLogger(Server.class);
    private final HeartBeatList hbList;
    private final HeartBeatController controller;

    public HeartBeatLifeTime(HeartBeatList hbList,HeartBeatController controller) {
        this.hbList = hbList;
        this.controller = controller;
    }

    @Override
    public void run() {
        while (true) {
            Date date = new Date();
            synchronized (hbList) {
                if(hbList.removeIf(n -> (n.getTimeout().compareTo(date) < 0 || !n.isStatus()))) {
                    LOG.log("heartbeats were removed");
                    LOG.log("Current active servers: " + hbList.size());
                    controller.sendUpdateServerList();
                }
            }

            try {
                Thread.sleep(Constants.TO_SECONDS);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
