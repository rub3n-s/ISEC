package pt.isec.pd.server;

import pt.isec.pd.server.data.Server;

import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        new Server(Integer.parseInt(args[0]),args[1]);
    }
}
