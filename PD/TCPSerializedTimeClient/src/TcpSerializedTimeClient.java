import java.net.*;
import java.io.*;

public class TcpSerializedTimeClient {

    public static final int MAX_SIZE = 256;
    public static final String TIME_REQUEST = "TIME";
    public static final int TIMEOUT = 10; //segundos

    public static void main(String[] args) throws IOException
    {
        
        InetAddress serverAddr = null;
        int serverPort = -1;
        Socket socket = null;
        ObjectOutputStream out = null;
        ObjectInputStream in = null;
        Time response;
        
        if(args.length != 2){
            System.out.println("Sintaxe: java TcpTimeClient serverAddress serverUdpPort");
            return;
        }

        try{

            serverAddr = InetAddress.getByName(args[0]);
            serverPort = Integer.parseInt(args[1]);   
            socket = new Socket(serverAddr, serverPort);
            socket.setSoTimeout(TIMEOUT*1000);
            
            in = new ObjectInputStream(socket.getInputStream());
            out = new ObjectOutputStream(socket.getOutputStream());
            
            out.writeObject(TIME_REQUEST);
            out.flush();
            
            //A resposta deve terminar com uma mundança de linha.
            //Os caracteres de mudança de linha não são copiados para "response"
            response = (Time)in.readObject();
          
            System.out.println("Current time: " + response);
            
        }catch(UnknownHostException e){
             System.out.println("Destino desconhecido:\n\t"+e);
        }catch(NumberFormatException e){
            System.out.println("O porto do servidor deve ser um inteiro positivo.");
        }catch(SocketTimeoutException e){
            System.out.println("Nao foi recebida qualquer resposta:\n\t"+e);
        }catch(IOException e){
            System.out.println("Ocorreu um erro no acesso ao socket:\n\t"+e);
        }catch(ClassNotFoundException e){
             System.out.println("O objecto recebido nao e' do tipo esperado:\n\t"+e);
        }finally{
            if(socket != null){
                socket.close();
            }
        }
   }
  
}