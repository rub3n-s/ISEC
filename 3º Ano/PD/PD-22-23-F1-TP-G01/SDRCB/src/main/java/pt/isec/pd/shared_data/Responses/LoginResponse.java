package pt.isec.pd.shared_data.Responses;

import java.io.Serializable;

public class LoginResponse extends Response {
    private int id;
    private boolean isAdmin;


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public boolean isAdmin() {
        return isAdmin;
    }

    public void setAdmin(boolean admin) {
        isAdmin = admin;
    }
}
