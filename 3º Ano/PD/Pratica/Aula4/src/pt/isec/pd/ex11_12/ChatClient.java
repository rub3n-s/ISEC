package pt.isec.pd.ex11_12;

// ip classe D
// 224.0.0 a 239.255.255.255

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.*;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class ChatClient {
    public static int PORT = 9001;

    void startChat() throws IOException, InterruptedException {
        MulticastSocket ms = new MulticastSocket(PORT);
        InetAddress ipGroup = InetAddress.getByName("224.1.2.3");
        SocketAddress sa = new InetSocketAddress(ipGroup,PORT);
        NetworkInterface ni = NetworkInterface.getByName("en0");
        ms.joinGroup(sa,ni);

        System.out.println("Welcome to the chat");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insert your username: ");
        String username = scanner.nextLine();

        ReceiveMessages rs = new ReceiveMessages(ms);
        rs.start();

        boolean keepGoing = true;

        while(keepGoing) {
            DatagramPacket datagramPacket;
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oss = new ObjectOutputStream(baos);

            System.out.println("Write a message:");
            String msg = scanner.nextLine();

            System.out.println("Write 0 (to use the string class) or 1 (to use the Msg class) : ");
            if (handleOption(scanner) == 0) {
                msg = username + " " + msg;
                oss.writeObject(msg);
            } else {
                oss.writeObject(new Msg(username,msg));
            }

            datagramPacket = new DatagramPacket(baos.toByteArray(),baos.toByteArray().length,ipGroup,PORT);
            ms.send(datagramPacket);
        }

        ms.leaveGroup(sa,ni);
        ms.close();
        rs.join();
    }

    int handleOption(Scanner scanner) {
        while (true) {
            try {
                int option = Integer.parseInt(scanner.nextLine());
                if (option == 0 || option == 1){
                    return option;
                }
                System.out.println("Write 0 (to use the string class) or 1 (to use the Msg class) : ");
            } catch (NumberFormatException e) {
                System.out.println("Write 0 (to use the string class) or 1 (to use the Msg class) : ");
            }
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        ChatClient client = new ChatClient();
        client.startChat();
    }
}
