package pt.isec.pd.ex17;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Arrays;

public class TimeClient {
    private static final int MAX_BYTES = 4000;

    private static final String PATH = "./ClientFiles/";

    private static final String FILE = "isec.png";

    public static void main(String[] args) throws IOException, NotBoundException {
        int offset = 0;

        // Opcao 1  ============
        // recebe o url para o registry juntamente com o nome do objeto remoto
        // devolve a referencia remota
        //Remote remoteRef = Naming.lookup("rmi://127.0.0.1:1099/timeserver");

        // Opcao 2  ============
        Registry registry = LocateRegistry.getRegistry("127.0.0.1", Registry.REGISTRY_PORT);
        Remote remoteRef = registry.lookup("timeserver");

        RemoteTimeInterface remoteTimeInterface = (RemoteTimeInterface) remoteRef;

        // Criar o ficheiro e o FileOutputStream
        File file = new File(PATH + FILE);
        FileOutputStream out = new FileOutputStream(file);

        boolean stop = false;
        while (!stop) {
            byte[] received = remoteTimeInterface.getFileChunk(FILE, offset);

            if (received == null)
                stop = true;
            else {
                offset += received.length;
                out.write(received, 0, received.length);
            }
        }
        out.close();
    }
}
