package pt.isec.pd.ex9.ex8;

import pt.isec.pd.ex9.FicheiroByteArray;
import pt.isec.pd.ex9.ex5.ServerCurrentTime;

import java.io.*;
import java.net.Socket;

public class clientTCP {
    private static final int PORT = 9001;

    private static final String PATH = "./ClientFiles/";

    private static final String FILE = "isec.png";
    //private static final String FILE = "landscape.jpg";
    //private static final String FILE = "sample-text.txt";

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        try {
            Socket clientSocket = new Socket("127.0.0.1",PORT);
            clientSocket.setSoTimeout(2000);

            System.out.println("Connected to " + clientSocket.getInetAddress().getHostAddress() + ":"
                    + clientSocket.getPort());

            // Para nao haver deadlock o OjectOutputStream deve ser definido primeiro que o ObjectInputStream
            // O objeto input stream vai ficar bloqueado a espera de ler um header do ObjectOutputStream do outro lado
            // E do outro lado faz exatamente o mesmo
            // Ao criar primeiro o objectOutputStream nao vai ser preciso esperar pela criacao do ObjectInputStream
            ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());

            // escreve para o servidor
            oos.writeObject(FILE);

            System.out.println("Downloading file '" + FILE + "'");

            // Criar o ficheiro e o FileOutputStream
            File file = new File(PATH + FILE);
            FileOutputStream out = new FileOutputStream(file);

            boolean stop = false;
            while(!stop) {
                FicheiroByteArray fba = (FicheiroByteArray) ois.readObject();

                System.out.println("Received " + fba.getNBytes() + " bytes...");

                if (fba.isComplete())
                    stop = true;
                else
                    out.write(fba.getArray(),0, fba.getNBytes());
            }

            clientSocket.close();
        } catch (EOFException e) {
            System.out.println("Socket is closed: " + e);
        }
    }
}
