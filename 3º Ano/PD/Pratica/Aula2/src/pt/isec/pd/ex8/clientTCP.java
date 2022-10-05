package pt.isec.pd.ex8;

import java.io.*;
import java.net.Socket;

public class clientTCP {
    private static final String HOST = "127.0.0.1";
    private static final int PORT = 9001;

    private static final String FILE = "isec.png";

    //private static final String FILE = "landscape.jpg";

    //private static final String FILE = "sample-text.txt";

    private static final int MAX_DATA = 4000;

    private static final String PATH = "./ClientFiles/";

    public static void main(String[] args) throws IOException {
        // localhost ou 127.0.0.1
        // podem-se utilizar ambos porque servidor e cliente se encontram na mesma maquina

        // 1) Criar o socket
        Socket clientSocket = new Socket(HOST,PORT);

        // 2) Definir o timeout
        clientSocket.setSoTimeout(2000);

        System.out.println("Connect to " + clientSocket.getInetAddress().getHostAddress() + ":"
                + clientSocket.getPort());

        // 3) Criar os streams de Input e Output
        InputStream is = clientSocket.getInputStream();
        OutputStream os = clientSocket.getOutputStream();

        // 4) Escreve para o servidor o nome do ficheiro que se pretende obter
        os.write(FILE.getBytes());

        System.out.println("Downloading file '" + FILE + "'...");

        // 5) Criar o ficheiro no pasta de destino
        File fileCopy = new File(PATH + FILE);
        FileOutputStream out = new FileOutputStream(fileCopy);

        // 6) Ler os bytes enviados pelo servidor
        byte[] msgBuffer;
        int nBytes;

        // 7) Permanecer em ciclo ate receber todos os bytes
        //    Neste caso, quando chegar a -1 significa que o ja nao existiam mais bytes a ser enviados
        do {
            msgBuffer = new byte[MAX_DATA];
            nBytes = is.read(msgBuffer);
            if (nBytes > -1)
                out.write(msgBuffer,0,nBytes);
        } while(nBytes > -1);

        System.out.println("Socket closed.");

        clientSocket.close();
    }
}
