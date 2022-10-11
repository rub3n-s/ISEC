package pt.isec.pd.ex9.ex5;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Calendar;

// Enviar e receber os objetos do tipo String e nao os bytes

public class ServerUDP {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        boolean keepGoing = true;

        // 1) Criar o DatagramSocket e lancar a excepcao no main
        DatagramSocket ds = new DatagramSocket(9001);

        while (keepGoing) {
            // 2) Criar o Datagram Packet para receber informacao (2 argumentos)
            DatagramPacket dpRec = new DatagramPacket(new byte[256], 256);

            // 3) Receber a informacao e trocar a excepcao SocketException pela IOException
            ds.receive(dpRec);

            // 4) Serializar os objetos
            // serializacao de objetos e feita a base de dois tipos: InputStream e OutputStream
            ByteArrayInputStream bais = new ByteArrayInputStream(dpRec.getData());

            ObjectInputStream ois = new ObjectInputStream(bais);

            // ois.readObject(): devolve uma referencia para Object, entao deve-se fazer o cast para o tipo pretentido
            String msgRec = (String) ois.readObject();

            // Apenas para efeito de Debug
            System.out.println("Received '" + msgRec + "' from " +  dpRec.getAddress().getHostAddress()
                    + ":" + dpRec.getPort());

            // 5) Comparar a mensagem recebida
            if (msgRec.equalsIgnoreCase("HORA")) {
                // 6) Obter a hora do sistema
                //SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");

                // 7) Recebe um objeto do tipo Date e devolve como string
                //String curTime = sdf.format(new Date());

                Calendar cal = Calendar.getInstance();

                ServerCurrentTime sct = new ServerCurrentTime(
                            cal.get(Calendar.HOUR_OF_DAY),
                            cal.get(Calendar.MINUTE),
                            cal.get(Calendar.SECOND));

                // 8) Tranforma a String num array de bytes
                //byte[] curTimeBytes = curTime.getBytes();

                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                ObjectOutputStream oos = new ObjectOutputStream(baos);
                //oos.writeObject((String) curTime);
                oos.writeObject(sct);

                // passar do oos para o byte array
                byte[] curTimeBytes = baos.toByteArray();

                // 9) Obter o IP e Porto de origem da mensagem:
                // getAddress(): devolve como InetAddress
                // getPort(): devolve como int
                InetAddress ipClient = dpRec.getAddress();
                int portClient = dpRec.getPort();

                // 10) Tendo a informacao toda, criar um DatagramPacket para envio
                DatagramPacket dpSend = new DatagramPacket(
                        curTimeBytes, curTimeBytes.length,
                        ipClient, portClient);

                // 11) Enviar a informacao
                ds.send(dpSend);
            }
            else
                keepGoing = false;
        }

        // 12) Fechar o socket
        ds.close();
    }
}

