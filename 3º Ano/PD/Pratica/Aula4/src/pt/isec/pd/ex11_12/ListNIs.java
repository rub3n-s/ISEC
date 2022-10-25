package pt.isec.pd.ex11_12;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class ListNIs {
    public static void main(String[] args) throws SocketException {
        Enumeration<NetworkInterface> allNIs = NetworkInterface.getNetworkInterfaces();

        while(allNIs.hasMoreElements()){
            NetworkInterface ni = allNIs.nextElement();
            System.out.println(ni.getName());
            Enumeration<InetAddress> allIPs = ni.getInetAddresses();

            while(allIPs.hasMoreElements())
                System.out.println(allIPs.nextElement().getHostAddress() + "\n");
        }
    }
}
