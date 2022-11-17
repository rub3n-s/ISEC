package pt.isec.pd.ex16;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Calendar;

public class TimeServer extends UnicastRemoteObject implements RemoteTimeInterface {
    public TimeServer() throws RemoteException { }

    @Override
    public Hour getHour() throws RemoteException {
        Calendar cal = Calendar.getInstance();
        return new Hour(
                cal.get(Calendar.HOUR_OF_DAY),
                cal.get(Calendar.MINUTE),
                cal.get(Calendar.SECOND)
        );
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
