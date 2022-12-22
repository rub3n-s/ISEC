package pt.isec.pd.ex19;

import java.io.IOException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface AlarmClientRemoteInterface extends Remote
{
    void writeFileChunk(byte[] byteArray) throws IOException;
}
