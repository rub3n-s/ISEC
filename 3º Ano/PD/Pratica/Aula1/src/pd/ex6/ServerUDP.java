package pd.ex6;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServerUDP {
    private static final String PATH = "./ServerFiles/";

    private static final String file1 = "isec.png";

    private static final String file2 = "landscape.jpg";

    private static final String file3 = "sample-text.txt";

    private static final int MAX_DATA = 4000;

    private static void readChunksFromFile(InetAddress ipClient, int portClient, String file, DatagramSocket ds) throws IOException {
        FileInputStream fis = new FileInputStream("./ServerFiles/" + file);

        byte[] chunk = new byte[MAX_DATA];
        int nBytes;

        do {
            nBytes = fis.read(chunk);
            System.out.println("Bytes read: " + nBytes);

            // Enquanto houverem bytes para enviar, envia para o cliente
            if (nBytes > -1) {
                DatagramPacket dp = new DatagramPacket(
                        chunk, nBytes,ipClient,portClient
                );

                ds.send(dp);
            }
        } while (nBytes > -1);

        // Envia um DatagramPacket com 0 bytes
        DatagramPacket dpZero = new DatagramPacket(
                chunk, 0,ipClient,portClient
        );

        ds.send(dpZero);
    }

    public static void main(String[] args) throws IOException {
        boolean keepGoing = true;

        // 1) Criar o DatagramSocket e lancar a excepcao no main
        DatagramSocket ds = new DatagramSocket(9001);

        while (keepGoing) {
            // 2) Criar o Datagram Packet para receber informacao (2 argumentos)
            DatagramPacket dpRec = new DatagramPacket(new byte[256], 256);

            // 3) Receber a informacao e trocar a excepcao SocketException pela IOException
            ds.receive(dpRec);

            // 4) Converter a informacao recebida numa string
            //    dpRec.getData() -> Recebe o array de bytes preenchido
            String msgRec = new String(dpRec.getData(), 0, dpRec.getLength());

            // Apenas para efeito de Debug
            System.out.println("Download Request Received '" + msgRec + "' from " +  dpRec.getAddress().getHostAddress()
                    + ":" + dpRec.getPort());

            // 5) Comparar a mensagem recebida
            if (msgRec.equalsIgnoreCase(file1) || msgRec.equalsIgnoreCase(file2) || msgRec.equalsIgnoreCase(file3)) {
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

