/*Neste exemplo, a informacao e' trocada via um objecto
serializado que encapsula o "nickname" e a mensagem.*/

/*
   Multicast IPv4 em Mac OS
   Na lina de comando: -Djava.net.preferIPv4Stack=true
   No c�digo: System.setProperty("java.net.preferIPv4Stack", "true");
*/

import java.io.*;
import java.net.*;

class Msg
{	
	protected String nickname;
	protected String msg;
	
	public Msg(String nickname, String msg)
	{
		this.nickname = nickname;
        this.msg = msg;
	}

	public String getNickname(){ return nickname; }
	
	public String getMsg(){ return msg; }
        
}

public class MulticastChat_v2 extends Thread
{
    public static final String LIST = "LIST";
    public static String EXIT = "EXIT";
    public static int MAX_SIZE = 1000;
    
    protected String username;
    protected MulticastSocket s;
    protected boolean running;

    public MulticastChat_v2(String username, MulticastSocket s) 
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
        Msg msg;
        ByteArrayOutputStream bout;
        ObjectOutputStream oout;
        
        if(s == null || !running){
            return;
        }
        
        try{
            
            while(running){
                
                pkt = new DatagramPacket(new byte[MAX_SIZE], MAX_SIZE);
                s.receive(pkt);
                
                try{                    
                    
                    // "Deserializa" o objecto transportado no datagrama acabado de ser recebido
                               
                    ObjectInputStream oin = new ObjectInputStream(new ByteArrayInputStream(pkt.getData(),0,pkt.getLength()));

                    Object o = oin.readObject();

                    System.out.println();
                    System.out.print("(" + pkt.getAddress().getHostAddress() + ":" + pkt.getPort() + ") ");
                    
                    //Caso o objecto recebido seja uma instancia de Msg...
                    if(o instanceof Msg){
                        
                        msg = (Msg)o;
                        
                        if(msg.getMsg().toUpperCase().contains(LIST)){
                            
                            //Envia o username 'a origem sob a forma de um objecto do tipo String
                            bout = new ByteArrayOutputStream();
                            oout = new ObjectOutputStream(bout);

                            oout.writeObject(username);
                            oout.flush();

                            pkt.setData(bout.toByteArray());
                            pkt.setLength(bout.size());

                            s.send(pkt);

                            bout.close();
                            oout.close();

                            continue;
                        }
                        
                        //Mostra a mensagem recebida bem como a identificacao do emissor
                        System.out.println("Recebido \"" + msg.getMsg() + "\" de " + msg.nickname);
                         
                    //Caso o objecto recebido seja uma instancia de String...
                    }else if(o instanceof String){
                        
                        //Mostra a String
                        System.out.println(o);
                    }
                    
                    System.out.println(); System.out.print("> ");
                                          
                }catch(ClassNotFoundException e){
                    
                    System.out.println();
                    System.out.println("Mensagem recebida de tipo inesperado!");
                    //continue;
                    
                }catch(IOException e){
                    
                    System.out.println();
                    System.out.println("Impossibilidade de aceder ao conteudo da mensagem recebida!");
                    //continue;
                    
                }
                
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
    
    public static void main(String[] args) throws UnknownHostException, IOException {
     
        InetAddress group;
        int port;
        MulticastSocket socket = null;
        DatagramPacket dgram;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String msg;
        NetworkInterface nif;

        // para serializar sao preciso estes dois
        ByteArrayOutputStream bout;
        ObjectOutputStream oout;

        MulticastChat_v2 t = null;
        
        if(args.length != 4){
            System.out.println("Sintaxe: java MulticastChat <nickname> <groupo multicast> <porto> <interface de rede usada para multicast>");
            return;
        }
        
        try{
            group = InetAddress.getByName(args[1]);
            port = Integer.parseInt(args[2]);

            socket = new MulticastSocket(port);

            try{
                nif = NetworkInterface.getByInetAddress(InetAddress.getByName(args[3]));
            }catch (SocketException | NullPointerException | UnknownHostException | SecurityException ex){
                nif = NetworkInterface.getByName(args[3]); //e.g., eth0, wlan0, en0
            }            
            
            socket.joinGroup(new InetSocketAddress(group, port), nif);
            
            t = new MulticastChat_v2(args[0], socket);
            //t.setDaemon(true);
            t.start();
            
            System.out.print("> ");
            
            while(true){              
                
                msg = in.readLine();
                
                if(msg.equalsIgnoreCase(EXIT)){
                    break;
                }
                
                //Envia para o grupo de multicast e porto escolhidos uma instancia de Msg
                bout = new ByteArrayOutputStream();
                oout = new ObjectOutputStream(bout);

                oout.writeObject(new Msg(args[0],msg));    // sempre que aqui passa é um novo objeto

               // recebe nickname e mensagem
                dgram = new DatagramPacket( bout.toByteArray(), bout.size(), group, port);
                socket.send(dgram);

                bout.close();
                oout.close();
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
