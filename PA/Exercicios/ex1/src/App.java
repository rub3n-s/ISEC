import java.util.Random;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Random rnd = new Random();
        boolean flg = false; // default é false
        int tentativas = 1, op = 0;
        int random = rnd.nextInt(100) + 1;
        //double random = (Math.random() % 100) + 1;

        System.out.printf("[%d]\n",random);

        do {
            System.out.printf("\nTentativa[%d]\nAdivinha: ",tentativas);
            try {
                if (sc.hasNextInt())
                    op = sc.nextInt();

                if (op == random) {
                    System.out.printf("Acertou em [%d] tentativas!\n",tentativas);
                    flg = true;
                } else {
                    if (op > random) {
                        System.out.println("[Errou] Número é menor!");
                    } else {
                        System.out.println("[Errou] Número é maior!");
                    }
                    tentativas++;
                }
            } catch(IllegalStateException ex) {
                System.out.println("Deve ser introduzido um inteiro!");
            }
        } while(!flg);
    }
}
