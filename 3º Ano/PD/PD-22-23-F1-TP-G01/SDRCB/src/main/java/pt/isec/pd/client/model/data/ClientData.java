package pt.isec.pd.client.model.data;

import java.io.Serializable;

public class ClientData implements Serializable {
    private int id;
    private int showId;
    private boolean isAdmin;
    private ClientAction action;
    private Object data;

    public ClientData() {}

    public ClientData(ClientData clientData) {
        this.id = clientData.getId();
        this.showId = clientData.showId;
        this.isAdmin = clientData.isAdmin;
        this.action = clientData.action;
        this.data = clientData.data;
    }

    public int getId() { return id; }

    public void setId(int id) { this.id = id; }

    public void setAction(ClientAction action) { this.action = action; }

    public ClientAction getAction() { return action; }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public boolean isAdmin() {
        return isAdmin;
    }

    public void setAdmin(boolean admin) {
        isAdmin = admin;
    }

    public int getShowId() {
        return showId;
    }

    public void setShowId(int showId) {
        this.showId = showId;
    }
}
