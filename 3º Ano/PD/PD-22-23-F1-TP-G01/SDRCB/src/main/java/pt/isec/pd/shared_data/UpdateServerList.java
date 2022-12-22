package pt.isec.pd.shared_data;

import java.io.Serializable;
import java.util.List;

public class UpdateServerList implements Serializable {
    List<ServerAddress> serverAddressList;

    public List<ServerAddress> getServerAddressList() {
        return serverAddressList;
    }

    public void setServerAddressList(List<ServerAddress> serverAddressList) {
        this.serverAddressList = serverAddressList;
    }
}
