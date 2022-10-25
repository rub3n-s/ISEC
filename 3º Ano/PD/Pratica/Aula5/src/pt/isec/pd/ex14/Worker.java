package pt.isec.pd.ex14;

import pt.isec.pd.ex14.util.PiCalculator;

import java.io.*;
import java.net.Socket;

public class Worker {
    private static int PORT;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // obter o porto atraves do argumento
        PORT = Integer.parseInt(args[0]);

        try {
            Socket clientSocket = new Socket("127.0.0.1",PORT);
            clientSocket.setSoTimeout(2000);

            System.out.println("Connected to " + clientSocket.getInetAddress().getHostAddress() + ":"
                    + clientSocket.getPort());

            ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());

            PiCalculator calculo = (PiCalculator) ois.readObject();

            Double partialCalc = calculo.getPartialPiValue();

            // escreve para o servidor
            oos.writeObject(partialCalc);

            clientSocket.close();
        } catch (EOFException e) {
            System.out.println("Socket is closed: " + e);
        }
    }
}
