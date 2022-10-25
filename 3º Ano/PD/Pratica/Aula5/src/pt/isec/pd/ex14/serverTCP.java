package pt.isec.pd.ex14;

import pt.isec.pd.ex14.util.PiCalculator;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.HashMap;

public class serverTCP {
    private static final int PORT = 9001;
    private static final long INTERVALS = 10000;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        boolean keepGoing = true;
        ArrayList<Socket> clientSockets = new ArrayList<>();
        HashMap<String,Integer> workers = new HashMap<>();
        int numWorkers = 0;
        double sum = 0;

        // conecta ao porto de servico
        ServerSocket serverSocket = new ServerSocket(PORT);

        BufferedReader br = new BufferedReader(new FileReader("workers.txt"));
        while(br.readLine() != null) {
            String[] parts = br.readLine().split(" ");
            if (parts.length < 2)
                continue;
            int port = Integer.parseInt(parts[1]);  // converte string para int
            if (port == 5001 || port == 5002 || port == 5003) {
                workers.put(parts[0], port);
                numWorkers++;
                clientSockets.add(new Socket());
                System.out.println("Worker " + workers.size() + " = " + parts[0] + ":" + port);
            }
        }

        int id = 0;
        for (var w : workers.entrySet()) {
            id++;
            if (w.getKey().equalsIgnoreCase(clientSocket.getInetAddress().getHostAddress())
                    && w.getValue() == clientSocket.getPort()) {
                ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
                PiCalculator calculator = new PiCalculator(id,numWorkers,INTERVALS);
                oos.writeObject(calculator);

                System.out.println("Worker '" + id + "' " + w.getKey() + ":" + w.getValue() + "has connected...");
            }
        }

        while(keepGoing) {
            Socket clientSocket = serverSocket.accept();

            int id = 0;
            for (var w : workers.entrySet()) {
                id++;
                if (w.getKey().equalsIgnoreCase(clientSocket.getInetAddress().getHostAddress())
                        && w.getValue() == clientSocket.getPort()) {
                    ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
                    PiCalculator calculator = new PiCalculator(id,numWorkers,INTERVALS);
                    oos.writeObject(calculator);

                    System.out.println("Worker '" + id + "' " + w.getKey() + ":" + w.getValue() + "has connected...");
                }
            }

            //ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream());

            // recebe a parte do calculo
            Double calcPart = (Double)ois.readObject();

            // mensagem a informar a recepcao
            System.out.println("Received from " + clientSocket.getInetAddress().getHostAddress() + ":" + clientSocket.getPort()
            + " = " + calcPart);

            sum += calcPart;

            clientSocket.close();
        }

    }
}
