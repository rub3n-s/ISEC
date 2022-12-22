package pt.isec.pd.shared_data;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.ClientData;

import java.io.Serial;
import java.io.Serializable;
import java.util.List;

public class Prepare implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private int port;
    private String ip;
    private List<String> update;
    private ClientData data;
    private int nextVersion;

    public Prepare(int port,String ip, List<String> sqlCommand, ClientData data,int nextVersion) {
        this.port = port;
        this.data = data;
        this.ip = ip;
        this.update = sqlCommand;
        this.nextVersion = nextVersion;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }

    public List<String> getUpdate() {
        return update;
    }

    public void setUpdate(List<String> update) {
        this.update = update;
    }

    public int getNextVersion() {
        return nextVersion;
    }

    public String getIp() {
        return ip;
    }

    @Override
    public String toString() {
        return "port: " + port +
                ", sqlCommand: " + update;
    }

    public ClientData getData() {
        return data;
    }

    public void setData(ClientData data) {
        this.data = data;
    }
}
