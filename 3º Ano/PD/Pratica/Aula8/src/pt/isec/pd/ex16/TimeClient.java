package pt.isec.pd.ex16;

import java.io.IOException;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class TimeClient {
    public static void main(String[] args) throws NotBoundException, IOException {
        // Opcao 1  ============
        // recebe o url para o registry juntamente com o nome do objeto remoto
        // devolve a referencia remota
        //Remote remoteRef = Naming.lookup("rmi://127.0.0.1:1099/timeserver");

        // Opcao 2  ============
        Registry registry = LocateRegistry.getRegistry("127.0.0.1", Registry.REGISTRY_PORT);
        Remote remoteRef = registry.lookup("timeserver");

        RemoteTimeInterface remoteTimeInterface = (RemoteTimeInterface) remoteRef;
        System.out.println("Current Server Time: " + remoteTimeInterface.getHour());
    }
}
