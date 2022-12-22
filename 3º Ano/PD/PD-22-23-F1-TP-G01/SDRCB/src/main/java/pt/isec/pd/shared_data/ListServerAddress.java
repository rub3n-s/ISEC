package pt.isec.pd.shared_data;

import java.io.Serializable;
import java.util.List;

public class ListServerAddress implements Serializable {
    List<ServerAddress> servers;

    public List<ServerAddress> getServers() {
        return servers;
    }

    public void setServers(List<ServerAddress> servers) {
        this.servers = servers;
    }
}
