import java.util.Random;
import java.util.Scanner;

public class ex2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int op = 0, tenta = 1;
        boolean flg = false;
        String palavra;
        String [] adivinha = {"adivinha", "sol", "terra", "mar"};
        //int random = (int)(Math.random() * 100) + 1;

        Random rnd = new Random();
        //int random = rnd.nextInt(4);
        int random = rnd.nextInt(100) + 1;

        System.out.printf("Número Aleatório [%d]\n\n",random);
        //System.out.printf("Palavra aleatória escolhida [%s]\n",adivinha[random]);

        do {
            System.out.printf("\nTentativa [%d]",tenta);

            System.out.print("\nAdivinhe o inteiro: ");
            if (sc.hasNextInt())
                op = sc.nextInt();
            else
                System.out.println("[Erro] Deve ser introduzido um número inteiro.\n");

            if (op == random) {
                System.out.printf("\nAcertou em [%d] tentativas!!!",tenta);
                flg = true;
            } else if (op < random)
                System.out.println("\nNúmero inserido é menor!");
            else
                System.out.println("\nNúmero inserido é maior!");

            /*System.out.print("\nAdivinhe a palavra: ");
            palavra = sc.nextLine();

            if (palavra.equals(adivinha[random])) {
                System.out.printf("\nAcertou em [%d] tentativas!!!",tenta);
                flg = true;
            } else {
                System.out.println("\nErrou!");
            }*/

            tenta++;
        } while(!flg);
    }
}
