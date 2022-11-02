package pt.isec.pd;

import pt.isec.pd.util.PiCalculator;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Worker {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // obter o porto atraves do argumento
        int port = Integer.parseInt(args[0]);
        System.out.println("My port: " + port);

        // conecta ao porto de servico
        ServerSocket serverSocket = new ServerSocket(port);

        // aguarda conexao
        Socket masterSocket = serverSocket.accept();

        System.out.println("Connected to " + masterSocket.getInetAddress().getHostAddress() + ":" + masterSocket.getPort());

        ObjectOutputStream oos = new ObjectOutputStream(masterSocket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(masterSocket.getInputStream());

        // le do servidor
        PiCalculator piCalculator = (PiCalculator)ois.readObject();

        // efetua o calculo
        Double result = piCalculator.getPartialPiValue(
                piCalculator.getMyId(),
                piCalculator.getNWorkers(),
                piCalculator.getIntervals()
        );

        // escreve para o servidor
         oos.writeObject(result);

        masterSocket.close();
    }
}