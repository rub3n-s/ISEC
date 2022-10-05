package pd.ex5;

import java.io.IOException;
import java.net.*;

public class ClientUDP {
    public static void main(String[] args) throws IOException {
        // 1) Criar o DatagramSocket e definir um TIME_OUT
        DatagramSocket ds = new DatagramSocket();
        ds.setSoTimeout(3000);

        // 2) Criar um array de bytes com a informacao a ser enviada
        byte[] msgBytes = "HORA2".getBytes();

        // 3) Obter o IP e o Porto
        InetAddress ipServer = InetAddress.getByName("127.0.0.1");
        int portServer = 9001;

        // 4) Criar um DatagramPacket para enviar a informacao ao servidor (4 parametros)
        DatagramPacket dpSend = new DatagramPacket(
                msgBytes, msgBytes.length,
                ipServer, portServer
        );

        // 5) Enviar o packet
        ds.send(dpSend);

        // 6) Receber a respota
        DatagramPacket dpRec = new DatagramPacket(new byte[256], 256);
        ds.receive(dpRec);
        String msgRec = new String(dpRec.getData(),0, dpRec.getLength());

        // 7) Mostrar a mensagem recebida
        System.out.println("[" + dpRec.getAddress().getHostAddress()  + ":"
        + dpRec.getPort() + "] ServerTime: " + msgRec);

        // 8) Fechar o socket
        ds.close();
    }
}
