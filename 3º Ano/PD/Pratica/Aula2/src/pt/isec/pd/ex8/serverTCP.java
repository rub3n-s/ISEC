package pt.isec.pd.ex8;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.BindException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class serverTCP {
    private static final int PORT = 9001;

    private static final int MAX_DATA = 4000;

    private static final String FILE_1 = "landscape.jpg";

    private static final String FILE_2 = "isec.png";

    private static final String FILE_3 = "sample-text.txt";

    private static void readChunksFromFile(String file, Socket clientSocket) throws IOException {
        FileInputStream fis = new FileInputStream("./ServerFiles/" + file);

        OutputStream out = clientSocket.getOutputStream();

        byte[] chunk = new byte[MAX_DATA];
        int nBytes;

        do {
            nBytes = fis.read(chunk);
            System.out.println("Bytes read: " + nBytes);

            // Enquanto houverem bytes para enviar, envia para o cliente
            if (nBytes > -1) {
                out.write(chunk,0,nBytes);
            }
        } while (nBytes > -1);
    }

    public static void main(String[] args) {
        boolean keepGoing = true;

        // comunicacao para varios clientes
        try {
            // conecta ao porto de servico
            ServerSocket serverSocket = new ServerSocket(PORT);

            while(keepGoing) {
                Socket clientSocket = serverSocket.accept();
                InputStream is = clientSocket.getInputStream();
                OutputStream os = clientSocket.getOutputStream();

                // mensagem a informar a recepcao
                System.out.println("Download request received from " + clientSocket.getInetAddress().getHostAddress() + ":" + clientSocket.getPort());

                // ler o array de bytes
                byte[] msgBuffer = new byte[256];

                // obter o numero de bytes lidos
                int nBytes = is.read(msgBuffer);

                // recriar a string
                String msgRec = new String(msgBuffer,0,nBytes);

                // mostra mensagem recebida
                System.out.println("Received '" + msgRec + "'...");

                // comparar a string recebida
                if (msgRec.equals(FILE_1))
                    readChunksFromFile(FILE_1,clientSocket);
                if (msgRec.equals(FILE_2))
                    readChunksFromFile(FILE_2,clientSocket);
                if (msgRec.equals(FILE_3))
                    readChunksFromFile(FILE_3,clientSocket);
                else
                    keepGoing = false;

                clientSocket.close();
            }

            serverSocket.close();
        } catch (BindException e){
            System.out.println("Service already running on port " + PORT);
        }
        catch (IOException e) {
            e.printStackTrace();
            System.out.println("I/O Error: " + e);
        }
    }
}
