package pt.isec.pd;

import pt.isec.pd.util.PiCalculator;

import java.io.*;
import java.net.*;
import java.sql.*;
import java.util.ArrayList;

public class Master {
    private static final int INTERVALS = 10000;

    // URL da BD
    private static final String DB_URL = "jdbc:sqlite:pd_db_jdbc.db";

    // credenciais
    private static final String USER = "username";
    private static final String PASSWORD = "password";

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
        ArrayList<WorkerData> workerData = new ArrayList<>(); // = readFromFile();

        // conectar a base de dados
        System.out.println("Connecting to database...");
        try {
            Connection connection = DriverManager.getConnection(DB_URL,USER,PASSWORD);

            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(
                    "SELECT name FROM users"
            );

            while (resultSet.next()) {
                /*int id = resultSet.getInt("id");
                String address = resultSet.getString("address");
                int port = resultSet.getInt("port");

                workerData.add(new WorkerData(address,port,new Socket(address,port)));

                System.out.println("Worker " + id + ": " + address + ":" + port);*/

                String name = resultSet.getString("name");
                System.out.println(name);
            }
        } catch (SQLException e) {
            System.out.println("Error connecting to database: " + e);
            return;
        }

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
