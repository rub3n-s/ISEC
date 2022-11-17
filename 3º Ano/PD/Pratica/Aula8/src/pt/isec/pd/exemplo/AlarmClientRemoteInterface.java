package pt.isec.pd.exemplo;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface AlarmClientRemoteInterface extends Remote
{
    void triggerAlarm() throws RemoteException;
}
