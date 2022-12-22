package pt.isec.pd.ex19;

import java.io.IOException;
import java.rmi.Remote;

public interface AlarmServerRemoteInterface extends Remote
{
    String REGISTRY_BIND_NAME = "alarmClockService";
    void getFile(AlarmClientRemoteInterface clientRef, String fileName) throws IOException;
}
