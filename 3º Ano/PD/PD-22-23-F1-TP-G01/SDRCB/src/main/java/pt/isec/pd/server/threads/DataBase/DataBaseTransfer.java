package pt.isec.pd.server.threads.DataBase;

import pt.isec.pd.utils.Constants;

import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;

public class DataBaseTransfer {
    private final Socket socket;
    private final String path;

    public DataBaseTransfer(String path, Socket socket) {
        this.socket = socket;
        this.path = path;
    }

    public void transfer() {
        try(FileOutputStream fileWriter = new FileOutputStream("databases/" + path)) {
            DataInputStream in = new DataInputStream(socket.getInputStream());

            byte[] bytes = new byte[Constants.MAX_BYTES];

            while(true) {
                int length = in.read(bytes);
                if (length <= 0) break;
                fileWriter.write(bytes,0,length);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
