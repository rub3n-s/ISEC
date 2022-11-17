package pt.isec.pd.ex16;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RemoteTimeInterface extends Remote {
    Hour getHour() throws RemoteException;
}
