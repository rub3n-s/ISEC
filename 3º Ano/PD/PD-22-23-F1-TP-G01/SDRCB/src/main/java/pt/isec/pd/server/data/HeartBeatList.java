package pt.isec.pd.server.data;

import pt.isec.pd.shared_data.HeartBeat;
import pt.isec.pd.shared_data.ServerAddress;

import java.util.*;

public class HeartBeatList extends LinkedList<HeartBeat>{
    public synchronized boolean updateList(HeartBeat element) {
        // if returns true the heartbeat was changed or added
        element.addTimeStamp(new Date());

        int index = indexOf(element);
        if (index == -1) {
            add(element);
            return true;
        }

        HeartBeat old = remove(index);
        add(index,element);

        return old.isStatus() != element.isStatus() || old.getActiveConnections() != element.getActiveConnections();
    }

    public List<ServerAddress> getOrderList() {
        List<ServerAddress> servers = new ArrayList<>();
        List<HeartBeat> orderList = this;
        Collections.sort(orderList);

        for (HeartBeat event : orderList) {
            servers.add(new ServerAddress(event.getIp(),event.getPortTcp()));
        }

        return servers;
    }
}
