package pt.isec.pd.ex9.ex8;

import pt.isec.pd.ex9.FicheiroByteArray;

import java.io.*;
import java.net.*;

public class serverTCP {
    private static final int PORT = 9001;

    private static final String PATH = "./ServerFiles/";

    private static final String FILE = "isec.png";
    //private static final String FILE = "landscape.jpg";
    //private static final String FILE = "sample-text.txt";

    private static final int MAX_DATA = 4000;

    private static void readChunksFromFile(String file, Socket socket, ObjectOutputStream oos) throws IOException {
        FileInputStream fis = new FileInputStream("./ServerFiles/" + file);
        FicheiroByteArray fba = new FicheiroByteArray();

        byte[] chunk = new byte[MAX_DATA];
        int nBytes;

        do {
            nBytes = fis.read(chunk);
            System.out.println("Bytes read: " + nBytes);

            fba.setArrayBytes(chunk,nBytes);

            if (nBytes == -1)
                fba.setComplete();

            oos.reset();
            oos.writeObject(fba);
        } while (!fba.isComplete());
    }

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

                // recebe a string com o nome do ficheiro
                String msgRec = (String)ois.readObject();

                // mostra mensagem recebida
                System.out.println("File requested: " + msgRec);

                // comparar a string recebida
                if (msgRec.equals(FILE))
                    readChunksFromFile(FILE,clientSocket,oos);
                else
                    keepGoing = false;

                clientSocket.close();
            }

            serverSocket.close();
        } catch (BindException e){
            System.out.println("Service already running at PORT: " + PORT);
        }
        catch (IOException e) {
            e.printStackTrace();
            System.out.println("I/O Error: " + e);
        }
    }
}
