package pt.isec.pd.ex17;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.MalformedURLException;
import java.nio.file.FileStore;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Arrays;
import java.util.Calendar;

public class TimeServer extends UnicastRemoteObject implements RemoteTimeInterface {
    private static final int MAX_BYTES = 512;
    private static final String PATH = "./ServerFiles/";

    public TimeServer() throws RemoteException { }

    @Override
    public byte[] getFileChunk(String fileName, long offset) throws IOException {
        FileInputStream fis = new FileInputStream(PATH + fileName);

        byte[] chunk = new byte[MAX_BYTES];
        int nBytes;

        fis.skip(offset);

        nBytes = fis.read(chunk);
        fis.close();
        System.out.println("Bytes read: " + nBytes);

        if (nBytes == -1)
            return null;

        if (nBytes < MAX_BYTES)
            chunk = Arrays.copyOf(chunk,nBytes);

        return chunk;
    }

    public static void main(String[] args) throws RemoteException, MalformedURLException {
        TimeServer ts = new TimeServer();

        // Opcao 1  ============
        //Naming.rebind("rmi://127.0.0.1:1099/timeserver",ts);    // de preferencia utilizar sempre o url completo

        // Opcao 2  ============
        Registry registry = LocateRegistry.createRegistry(Registry.REGISTRY_PORT);
        registry.rebind("timeserver",ts);   // como o registry ja foi definido nao e necessario usar o url completo
    }
}
