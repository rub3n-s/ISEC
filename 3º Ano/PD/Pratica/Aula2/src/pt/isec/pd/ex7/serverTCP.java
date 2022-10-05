package pt.isec.pd.ex7;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class serverTCP {
    private static final int PORT = 9001;

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
                System.out.println("Pedido recebido de " + clientSocket.getInetAddress().getHostAddress() + ":" + clientSocket.getPort());

                // ler o array de bytes
                byte[] msgBuffer = new byte[256];

                // obter o numero de bytes lidos
                int nBytes = is.read(msgBuffer);

                // recriar a string
                String msgRec = new String(msgBuffer,0,nBytes);

                // mostra mensagem recebida
                System.out.println("Mensagem recebida: " + msgRec);

                // comparar a string recebida
                if (msgRec.equals("HORA")) {
                    SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
                    String curTime = sdf.format(new Date());

                    // transformar a string num array de bytes
                    byte[] curTimeBuffer = curTime.getBytes();

                    // so faz sentido usar este 'write' quando se pretende enviar a totalidade
                    // do array de bytes
                    os.write(curTimeBuffer);
                } else
                    keepGoing = false;

                clientSocket.close();
            }

            serverSocket.close();

            /*
            // aceita em loop os clientes
            for(;;) {
                // apanha o proximo cliente TCP
                Socket newClient = serverSocket.accept();

                // mensagem a informar a recepcao
                System.out.println("Pedido recebido de " + newClient.getInetAddress() + ":" + newClient.getLocalPort());

                // objetos utilizados para fazer a escrita para o cliente
                OutputStream out = newClient.getOutputStream();
                PrintStream pout = new PrintStream(out);

                // escreve para o cliente
                pout.println(new Date());

                // limpa os bytes
                pout.flush();

                // encerra a conexao
                newClient.close();
            }*/
        } catch (BindException e){
            System.out.println("O servico ja se encontra a correr no porto " + PORT);
        }
        catch (IOException e) {
            e.printStackTrace();
            System.out.println("Erro no I/O: " + e);
        }
    }
}
