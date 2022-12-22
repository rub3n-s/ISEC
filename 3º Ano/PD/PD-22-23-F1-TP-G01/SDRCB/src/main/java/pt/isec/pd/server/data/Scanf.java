package pt.isec.pd.server.data;

import java.util.Scanner;

public class Scanf extends Thread {
    @Override
    public void run() {
        Scanner sc = new Scanner(System.in);
        while(true) {
           if(sc.nextLine().equals("sair")) {
              System.exit(0);
           }
        }
    }
}
