import java.util.Scanner;

import aleatorio.*;

public class main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        numAleatorio num = new numAleatorio();
        int numero = 0;
        System.out.printf("Numero gerado [%d]\n",num.getNum());
        do {
            System.out.println("\nAdivinhe o número");
            numero = sc.nextInt();
            num.situacao(numero);
        } while(!num.verifica(numero));
    }
}
