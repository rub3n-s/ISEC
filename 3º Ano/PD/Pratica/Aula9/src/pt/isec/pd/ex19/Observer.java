package pt.isec.pd.ex19;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Observer extends UnicastRemoteObject implements GetRemoteFileObserverInterface {
    public Observer() throws RemoteException { }

    @Override
    public void notifyNewOperationConcluded(String description) {
        System.out.println(description);
    }

    public static void main(String[] args) throws RemoteException {
        Registry r = LocateRegistry.createRegistry(Registry.REGISTRY_PORT);
        r.rebind(REGISTRY_BIND_NAME, new Observer());
    }
}
