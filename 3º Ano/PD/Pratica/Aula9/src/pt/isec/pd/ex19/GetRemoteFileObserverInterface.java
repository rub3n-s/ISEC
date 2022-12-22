package pt.isec.pd.ex19;

import java.io.IOException;
import java.rmi.Remote;

public interface GetRemoteFileObserverInterface extends Remote {
    String REGISTRY_BIND_NAME = "observerService";
    void notifyNewOperationConcluded(String description) throws IOException;
}
