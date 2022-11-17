package pt.isec.pd.exemplo;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.Date;

public interface AlarmServerRemoteInterface extends Remote
{
    String REGISTRY_BIND_NAME = "alarmClockService";
    void createAlarmClock(AlarmClientRemoteInterface clientRef, Date alarmDate) throws RemoteException;
}
