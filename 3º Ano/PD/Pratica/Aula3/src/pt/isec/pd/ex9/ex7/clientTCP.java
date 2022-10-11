package pt.isec.pd.ex9.ex7;

import pt.isec.pd.ex9.ex5.ServerCurrentTime;

import java.io.*;
import java.net.Socket;

public class clientTCP {
    private static final int PORT = 9001;

    private static final String GET_TIME = "HORA";

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // localhost ou 127.0.0.1
        // podem-se utilizar ambos porque servidor e cliente se encontram na mesma maquina
        Socket clientSocket = new Socket("127.0.0.1",PORT);
        //clientSocket.setSoTimeout(2000);

        System.out.println("Conectou-se a " + clientSocket.getInetAddress().getHostAddress() + ":"
                + clientSocket.getPort());

        // Para nao haver deadlock o OjectOutputStream deve ser definido primeiro que o ObjectInputStream
        // O objeto input stream vai ficar bloqueado a espera de ler um header do ObjectOutputStream do outro lado
        // E do outro lado faz exatamente o mesmo
        // Ao criar primeiro o objectOutputStream nao vai ser preciso esperar pela criacao do ObjectInputStream
        ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());

        // escreve para o servidor
        oos.writeObject(GET_TIME);

        try {
            ServerCurrentTime msgRec = (ServerCurrentTime) ois.readObject();

            System.out.println("Hora atual do servidor: " + msgRec);
        } catch (EOFException e) {
            System.out.println("Socket esta fechado: " + e);
        }

        clientSocket.close();
    }
}
