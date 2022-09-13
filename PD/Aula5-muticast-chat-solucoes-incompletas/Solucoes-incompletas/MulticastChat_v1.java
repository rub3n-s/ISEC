/*Neste exemplo, a informacao trocada e' apenas uma cadeia de caracteres*/

/*
   Multicast IPv4 em Mac OS
   Na lina de comando: -Djava.net.preferIPv4Stack=true
   No código: System.setProperty("java.net.preferIPv4Stack", "true");
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.net.UnknownHostException;
//import java.util.Enumeration;

public class MulticastChat_v1 extends Thread
{
    public static final String LIST = "LIST";
    public static final String EXIT = "EXIT";
    public static final int MAX_SIZE = 1000;
    
    protected String username;
    protected MulticastSocket s = null;
    protected boolean running = false;

    public MulticastChat_v1(String username, MulticastSocket s) 
    {
        this.username = username;
        this.s = s;
        running = true;
    }
    
    public void terminate()
    {                
        running = false;
    }
            
    @Override
    public void run()
    {
        DatagramPacket pkt;
        String msg;
        
        if(s == null || !running){
            return;
        }
        
        try{
            
            while(running){
                
                /** 
                 * Aguarda pela recepcao de um datagrama no scket s.                 
                 */
                
                pkt = /*...*/
                /*...*/
                
                msg = new String(pkt.getData(), 0, pkt.getLength());
                
                if(msg.toUpperCase().contains(LIST)){
                    
                    /**
                     * Reenvia o username 'a origem do datagrama recebido
                     */
                    
                    /*...*/
                     
                    //continue;
                }
                
                System.out.println();
                System.out.println("(" + pkt.getAddress().getHostAddress() + ":" + 
                        pkt.getPort() + ") " + msg);
                System.out.println(); System.out.print("> ");
                
            }
            
        }catch(IOException e){
            
            if(running){
                System.out.println(e);
            }
            
            if(!s.isClosed()){                
                s.close();
            }
            
        }                
    }
    
    public static void main(String[] args) throws UnknownHostException, IOException, InterruptedException {
     
        InetAddress group;
        int port;
        MulticastSocket socket = null;
        DatagramPacket dgram;
        String msg, msgToSend;        
        MulticastChat_v1 t = null;
        
        //System.setProperty("java.net.preferIPv4Stack", "true"); //Mac OS
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        if(args.length != 4){
            System.out.println("Sintaxe: java MulticastChat <nickname> <groupo multicast> <porto> <NIC multicast>");
            return;
        }
        
        try{
            group = InetAddress.getByName(args[1]);
            port = Integer.parseInt(args[2]);

            socket = /*...*/
            
            /*Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();
            while(interfaces.hasMoreElements()){
                NetworkInterface interf = interfaces.nextElement();
                System.out.print(interf.getName());
                try{
                    System.out.println(" : " + interf.getInetAddresses().nextElement().getHostAddress());
                }catch(Exception ex){
                    System.out.println();
                }
            }*/
            
                        
            try{
                socket.setNetworkInterface(NetworkInterface.getByInetAddress(InetAddress.getByName(args[3])));
            }catch (SocketException | NullPointerException | UnknownHostException | SecurityException ex){
                socket.setNetworkInterface(NetworkInterface.getByName(args[3])); //e.g., eth0, wlan0, en0
            }
            
            /**
             * Associa o socket ao grupo de multicast/IP de classe D pretendido (args[1])
             */
            
            /*...*/
            
            /**
             * Inicia a thread que vai ficar continuamente 'a espera de datagramas no socket
             */
            
            /*...*/
            
            System.out.print("> ");
            
            /* A thread principal entre num ciclo em que vai aguardando por mensagens em System.in
               e envia-as para o grupo de multicast*/
            
            while(true){
                
                msg = in.readLine();
                
                if(msg.equalsIgnoreCase(EXIT)){
                    break;
                }
                             
                msgToSend = args[0] + ": " + msg;
                       
                /**
                 * Envia a mensagem para o grupo de multicast
                 */
                
                /*...*/ 
                
            }
            
        }finally{
            
            if(t != null){
                t.terminate();
            }
            
            if(socket != null){
                socket.close();
            }
            
            //t.join(); //Para esperar que a thread termine caso esteja em modo daemon
            
        }

    }
}
