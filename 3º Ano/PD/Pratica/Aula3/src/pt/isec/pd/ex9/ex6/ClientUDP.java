package pt.isec.pd.ex9.ex6;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ClientUDP {
    private static final String FILE = "isec.png";
    //private static final String FILE = "sample-text.txt";
    //private static final String FILE = "landscape.jpg";

    private static final int MAX_DATA = 5000;

    private static final String PATH = "./ClientFiles/";

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // 1) Criar o DatagramSocket e definir um TIME_OUT
        DatagramSocket ds = new DatagramSocket();
        ds.setSoTimeout(3000);

        // 2) Criar um array de bytes com a informacao a ser enviada
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(FILE);
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

        // 6) Mostrar a mensagem recebida
        System.out.println("Downloading file '" + FILE + "'");

        // 7) Criar o ficheiro e o OutputStream
        File file = new File(PATH + FILE);
        FileOutputStream out = new FileOutputStream(file);

        // 8) Receber a respota
        DatagramPacket dpRec = new DatagramPacket(new byte[MAX_DATA], MAX_DATA);

        boolean stop = false;
        while(!stop) {
            ds.receive(dpRec);

            ByteArrayInputStream bais = new ByteArrayInputStream(dpRec.getData());

            ObjectInputStream ois = new ObjectInputStream(bais);

            FicheiroByteArray arrayRec = (FicheiroByteArray) ois.readObject();

            System.out.println("Received " + arrayRec.getNBytes() + " bytes...");

            if (arrayRec.isComplete())
                stop = true;
            else
                out.write(arrayRec.getArray(),0, arrayRec.getNBytes());
        }

        // 9) Fechar o socket
        ds.close();
    }
}
