package pt.isec.pd;

import pt.isec.pd.util.PiCalculator;

import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class Master {
    private static final int INTERVALS = 10000;

    public static boolean isInteger(String input) {
        try {
            Integer.parseInt(input);
            return true;
        }
        catch(NumberFormatException e) {
            return false;
        }
    }

    private static ArrayList<WorkerData> readFromFile() throws IOException {
        ArrayList<WorkerData> workerData = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader("workers.txt"));
        String currentLine;
        int port;

        while((currentLine = br.readLine()) != null) {
            // catch empty lines with white spaces
            if (currentLine.trim().length() > 0) {
                String[] parts = currentLine.split(" ");
                if (parts.length < 2)
                    continue;
                if (!parts[0].equalsIgnoreCase("localhost") && !parts[0].equalsIgnoreCase("127.0.0.1"))
                    continue;
                if (isInteger(parts[1])) {
                    port = Integer.parseInt(parts[1]);  // converte string para int
                    if (port == 5001 || port == 5002 || port == 5003) {
                        WorkerData worker = new WorkerData(parts[0], port, new Socket(parts[0], port));
                        workerData.add(worker);
                    }
                }
            }
        }
        return workerData;
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // ler do ficheiro workers.txt
        ArrayList<WorkerData> workerData = readFromFile();

        // output dos workers lidos do ficheiro
        System.out.println("Workers found:");
        for (var w : workerData)
            System.out.println("Worker " + w.getId() + ": " + w.getAddress() + ":" + w.getPort());

        // 1) escreve para os workers do ficheiro
        for (var w : workerData) {
            ObjectOutputStream oos = new ObjectOutputStream(w.getSocket().getOutputStream());
            //ois = new ObjectInputStream(w.getSocket().getInputStream());

            PiCalculator piCalculator = new PiCalculator(w.getId(),workerData.size(),INTERVALS);
            oos.writeObject(piCalculator);
        }

        // 2) le a info enviada pelos workers
        System.out.println("\nReceived calcs:");
        for (var w : workerData) {
            ObjectInputStream ois = new ObjectInputStream(w.getSocket().getInputStream());

            // recebe resultado do worker 'x'
            Double result = (Double)ois.readObject();

            System.out.println("Worker " + w.getId() + " = " + result);

            w.getSocket().close();
        }

    }
}
