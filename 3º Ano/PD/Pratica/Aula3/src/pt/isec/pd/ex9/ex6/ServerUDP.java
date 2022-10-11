package pt.isec.pd.ex9.ex6;

import pt.isec.pd.ex9.FicheiroByteArray;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServerUDP {
    private static final int PORT = 9001;

    private static final String PATH = "./ServerFiles/";

    private static final String FILE = "isec.png";
    //private static final String FILE = "landscape.jpg";
    //private static final String FILE = "sample-text.txt";

    private static final int MAX_DATA = 4000;

    private static void readChunksFromFile(InetAddress ipClient, int portClient, String file, DatagramSocket ds) throws IOException {
        FileInputStream fis = new FileInputStream("./ServerFiles/" + file);
        FicheiroByteArray fba = new FicheiroByteArray();

        byte[] chunk = new byte[MAX_DATA];
        int nBytes;

        do {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);

            nBytes = fis.read(chunk);
            System.out.println("Bytes read: " + nBytes);

            fba.setArrayBytes(chunk,nBytes);

            if (nBytes == -1)
                fba.setComplete();

            oos.writeObject(fba);

            byte[] arrayBytes = baos.toByteArray();

            DatagramPacket dp = new DatagramPacket(
                    arrayBytes,
                    arrayBytes.length,
                    ipClient,
                    portClient
            );

            ds.send(dp);
        } while (!fba.isComplete());
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        boolean keepGoing = true;

        // 1) Criar o DatagramSocket e lancar a excepcao no main
        DatagramSocket ds = new DatagramSocket(PORT);

        while (keepGoing) {
            // 2) Criar o Datagram Packet para receber informacao (2 argumentos)
            DatagramPacket dpRec = new DatagramPacket(new byte[256], 256);

            // 3) Receber a informacao e trocar a excepcao SocketException pela IOException
            ds.receive(dpRec);

            // 4) Criar os objectos para leitura
            ByteArrayInputStream bais = new ByteArrayInputStream(dpRec.getData());
            ObjectInputStream ois = new ObjectInputStream(bais);

            // 5) Converter a informacao recebida numa string
            // ois.readObject(): devolve uma referencia para Object, entao deve-se fazer o cast para o tipo pretentido
            String msgRec = (String) ois.readObject();

            // Apenas para efeito de Debug
            System.out.println("Download Request Received '" + msgRec + "' from " +  dpRec.getAddress().getHostAddress()
                    + ":" + dpRec.getPort());

            // 6) Comparar a mensagem recebida
            if (msgRec.equalsIgnoreCase(FILE)) {
                // 6) Obter o IP e Porto de origem da mensagem
                // getAddress(): devolve como InetAddress
                // getPort(): devolve como int
                InetAddress ipClient = dpRec.getAddress();
                int portClient = dpRec.getPort();

                // 7) Chama a funcao que le o ficheiro aos pedacos
                readChunksFromFile(ipClient,portClient,msgRec,ds);
            }
            else
                keepGoing = false;
        }

        // 12) Fechar o socket
        ds.close();
    }
}

