package pt.isec.pd.ex7;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class clientTCP {
    private static final int PORT = 9001;

    public static void main(String[] args) throws IOException {
        // localhost ou 127.0.0.1
        // podem-se utilizar ambos porque servidor e cliente se encontram na mesma maquina
        Socket clientSocket = new Socket("127.0.0.1",PORT);
        clientSocket.setSoTimeout(2000);

        System.out.println("Conectou-se a " + clientSocket.getInetAddress().getHostAddress() + ":"
                + clientSocket.getPort());

        InputStream is = clientSocket.getInputStream();
        OutputStream os = clientSocket.getOutputStream();

        // escreve para o servidor
        os.write("HORA".getBytes());

        byte[] msgBuffer = new byte[256];
        int nBytes = is.read(msgBuffer);

        // se o socket for fechado (lado servidor), o read (lado cliente) desbloqueia e o nBytes lidos vai ser -1
        // ao implementar esta condicao evita-se erros de execucao
        if (nBytes > -1) {
            // converte o array de bytes para string
            String msgRec = new String(msgBuffer,0,nBytes);

            System.out.println("Hora atual do servidor: " + msgRec);
        } else {
            System.out.println("Socket esta fechado!");
        }

        clientSocket.close();
    }
}
