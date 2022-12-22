package pt.isec.pd.server.threads.DataBase;

import pt.isec.pd.utils.Constants;

import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;

public class DataBaseSender {
    private final Socket socket;
    private final String path;

    public DataBaseSender(String path, Socket socket) {
        this.socket = socket;
        this.path = path;
    }

    public void send() {
        try(FileInputStream fileReader = new FileInputStream("databases/" + path)) {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());

            byte[] bytes = new byte[Constants.MAX_BYTES];

            int length;
            while((length = fileReader.read(bytes)) != -1) {
                out.write(bytes,0,length);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
