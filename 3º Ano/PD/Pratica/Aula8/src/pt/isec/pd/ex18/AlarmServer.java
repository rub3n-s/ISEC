package pt.isec.pd.ex18;

import java.io.FileInputStream;
import java.io.IOException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Arrays;

//  -Djava.rmi.server.hostname=127.0.0.1
public class AlarmServer extends UnicastRemoteObject implements AlarmServerRemoteInterface
{
    private static final int MAX_BYTES = 512;
    private static final String PATH = "./ServerFiles/";

    public AlarmServer() throws RemoteException { }

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

    @Override
    public void getFile(AlarmClientRemoteInterface clientRef, String fileName) throws IOException {
        int offset = 0;
        boolean stop = false;

        while(!stop) {
            byte[] chunk = getFileChunk(fileName,offset);

            if (chunk == null) {
                clientRef.writeFileChunk(null);
                stop = true;
            }
            else {
                offset += chunk.length;
                clientRef.writeFileChunk(chunk);
            }
        }
    }

    public static void main(String[] args) throws RemoteException
    {
        Registry r = LocateRegistry.createRegistry(Registry.REGISTRY_PORT);
        r.rebind(REGISTRY_BIND_NAME, new AlarmServer());
    }
}
