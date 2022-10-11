package pt.isec.pd.ex9.ex5;

import java.io.*;
import java.net.*;

public class ClientUDP {
    private static final String GET_TIME = "HORA";

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // 1) Criar o DatagramSocket e definir um TIME_OUT
        DatagramSocket ds = new DatagramSocket();
        ds.setSoTimeout(3000);

        // 2) Criar um array de bytes com a informacao a ser enviada
        //byte[] msgBytes = "HORA2".getBytes();


        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(GET_TIME);
        byte[] msgBytes = baos.toByteArray();

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

        // serializacao de objetos e feita a base de dois tipos: InputStream e OutputStream
        ByteArrayInputStream bais = new ByteArrayInputStream(dpRec.getData());

        ObjectInputStream ois = new ObjectInputStream(bais);

        // ois.readObject(): devolve uma referencia para Object, entao deve-se fazer o cast para o tipo pretentido
        //String msgRec = (String) ois.readObject();
        ServerCurrentTime msgRec = (ServerCurrentTime) ois.readObject();

        // 7) Mostrar a mensagem recebida
        //System.out.println("[" + dpRec.getAddress().getHostAddress()  + ":" + dpRec.getPort() + "] ServerTime: " + msgRec);
        System.out.println("[" + dpRec.getAddress().getHostAddress()  + ":" + dpRec.getPort() + "] ServerTime: " + msgRec);

        // 8) Fechar o socket
        ds.close();
    }
}
