package pt.isec.pd.ex9.ex7;

import pt.isec.pd.ex9.ex5.ServerCurrentTime;

import java.io.*;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Calendar;

public class serverTCP {
    private static final int PORT = 9001;

    public static void main(String[] args) throws ClassNotFoundException {
        boolean keepGoing = true;

        // comunicacao para varios clientes
        try {
            // conecta ao porto de servico
            ServerSocket serverSocket = new ServerSocket(PORT);

            while(keepGoing) {
                Socket clientSocket = serverSocket.accept();

                // Para nao haver deadlock o OjectOutputStream deve ser definido primeiro que o ObjectInputStream
                // O objeto input stream vai ficar bloqueado a espera de ler um header do ObjectOutputStream do outro lado
                // E do outro lado faz exatamente o mesmo
                // Ao criar primeiro o objectOutputStream nao vai ser preciso esperar pela criacao do ObjectInputStream
                ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
                ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());

                // mensagem a informar a recepcao
                System.out.println("Pedido recebido de " + clientSocket.getInetAddress().getHostAddress() + ":" + clientSocket.getPort());

                // recriar a string
                //String msgRec = new String(msgBuffer,0,nBytes);
                String msgRec = (String)ois.readObject();

                // mostra mensagem recebida
                System.out.println("Mensagem recebida: " + msgRec);

                // comparar a string recebida
                if (msgRec.equals("HORA")) {
                    Calendar cal = Calendar.getInstance();

                    ServerCurrentTime sct = new ServerCurrentTime(
                            cal.get(Calendar.HOUR_OF_DAY),
                            cal.get(Calendar.MINUTE),
                            cal.get(Calendar.SECOND));

                    oos.writeObject(sct);

                    // se pretender enviar informacao 2 vezes seguidas o resultado sera o mesmo devido
                    // a serializacao do objeto estar guardada em cache, para isso utiliza-se o reset
                    // acaba por servir com um flush()
                    sct.setHoras(-12);
                    oos.reset();
                    oos.writeObject(sct);

                    // ou entao, utilizar writeUnshared() em todos os envios de informacao
                    // evita o reset()
                    /* oos.writeUnshared(sct);
                       sct.setHoras(-12);
                       oos.writeUnshared(sct); */

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
