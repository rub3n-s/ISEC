package pt.isec.pd.ex19;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class AlarmClient extends UnicastRemoteObject implements AlarmClientRemoteInterface
{
    File file;
    FileOutputStream fos;

    private static final String PATH = "./ClientFiles/";
    private static final String FILE = "isec.png";

    public AlarmClient() throws RemoteException, FileNotFoundException {
        this.file = new File(PATH + FILE);
        fos = new FileOutputStream(file);
    }

    @Override
    public void writeFileChunk(byte[] byteArray) throws IOException {
        if (byteArray == null) {
            fos.close();
            UnicastRemoteObject.unexportObject(this,true);
        } else
            fos.write(byteArray, 0, byteArray.length);
    }

    public static void main(String[] args) throws IOException, NotBoundException {
        if (args.length != 1) {
            System.out.println("The RMI Registry IP is missing from the command line arguments.");
            return;
        }

        Registry r = LocateRegistry.getRegistry(args[0], Registry.REGISTRY_PORT);
        AlarmServerRemoteInterface remoteRef = (AlarmServerRemoteInterface)
                r.lookup(AlarmServerRemoteInterface.REGISTRY_BIND_NAME);

        AlarmClient alarmClient = new AlarmClient();
        remoteRef.getFile(alarmClient,FILE);

        GetRemoteFileObserverInterface remoteObserverRef = (GetRemoteFileObserverInterface)
                r.lookup(GetRemoteFileObserverInterface.REGISTRY_BIND_NAME);
        remoteObserverRef.notifyNewOperationConcluded("Downloading '" + FILE + "'...");
    }
}
