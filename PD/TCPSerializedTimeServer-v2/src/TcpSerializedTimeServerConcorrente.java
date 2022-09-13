import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Calendar;
import java.util.GregorianCalendar;

class ProcessClientThread implements Runnable {

    Socket toClientSocket;
    ProcessClientThread(Socket toClientSocket) {
        this.toClientSocket = toClientSocket;
    }

    @Override
    public void run() {
        ObjectInputStream oin;
        ObjectOutputStream oout;

        String request;
        Calendar calendar;

        try{
            oout = new ObjectOutputStream(toClientSocket.getOutputStream());
            oin = new ObjectInputStream(toClientSocket.getInputStream());

            request = (String)oin.readObject();

            if(request == null){ //EOF      /    cliente nao enviou nada
                return; //to next client request / saiu do block try catch
            }

            System.out.println("Recebido \"" + request.trim() + "\" de " +
                    toClientSocket.getInetAddress().getHostAddress() + ":" +
                    toClientSocket.getPort());

            if(!request.equalsIgnoreCase(TcpSerializedTimeServerConcorrente.TIME_REQUEST)){
                System.out.println("Unexpected request");
                return;   //saiu do block try catch
            }
            try{
                //simula processamento de dez segundos
                Thread.sleep(10000);
            } catch (InterruptedException ex) { }


            calendar = GregorianCalendar.getInstance();

            // ou oout.writeUnshared caso o obj seja alterado multiplas vezes
            oout.writeObject(new Time(calendar.get(GregorianCalendar.HOUR_OF_DAY),
                    calendar.get(GregorianCalendar.MINUTE),
                    calendar.get(GregorianCalendar.SECOND)));

            oout.flush();

            System.out.println("I'm thread " + Thread.currentThread() + "and I sent a response to a cliente at ip: "
                            + toClientSocket.getInetAddress().getHostName() + " port: " + toClientSocket.getPort());

            }catch(IOException | ClassNotFoundException e){
                System.out.println("Problema na comunicacao com o cliente " +
                        toClientSocket.getInetAddress().getHostAddress() + ":" +
                        toClientSocket.getPort()+"\n\t" + e);
            } finally{
                try{
                    toClientSocket.close();
                }catch(IOException e){}
            }
        }
}

public class TcpSerializedTimeServerConcorrente extends Thread{

    public static final String TIME_REQUEST = "TIME";
    public static final int TIMEOUT = 5000; // msec
    
    public static void main(String args[])
    {
        ServerSocket socket;       
        int listeningPort;        
        socket = null;
        Socket toClientSocket;
        
        if(args.length != 1){
            System.out.println("Sintaxe: java TcpSerializedTimeServerIncomplete listeningPort");
            return;
        }
        
        try{
            listeningPort = Integer.parseInt(args[0]);
            socket = new ServerSocket(listeningPort); //nao possui outputStream e inputStream

            System.out.println("TCP Time Server iniciado no porto " + socket.getLocalPort() + " ...");

            while(true){
                toClientSocket = socket.accept();        
                toClientSocket.setSoTimeout(TIMEOUT);

                Thread t = new Thread(new ProcessClientThread(toClientSocket));
                t.start();
            }
            
        }catch(NumberFormatException e){
            System.out.println("O porto de escuta deve ser um inteiro positivo.");
        }catch(IOException e){
            System.out.println("Ocorreu um erro ao nivel do socket de escuta:\n\t"+e);
        }finally{
            if(socket!=null){
                try {
                    socket.close();
                } catch (IOException ex) {}
            }
        }
    }
           
}