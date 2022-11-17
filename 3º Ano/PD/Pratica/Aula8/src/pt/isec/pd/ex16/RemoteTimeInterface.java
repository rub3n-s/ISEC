package pt.isec.pd.ex16;

import java.io.IOException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RemoteTimeInterface extends Remote {
    Hour getHour() throws IOException;
}
