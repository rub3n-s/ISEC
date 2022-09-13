import java.util.Scanner;

import array.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int nElementos = 0;

        System.out.print("Qual o número de elementos? ");
        nElementos = sc.nextInt();

        Array arr = new Array(nElementos);
        arr.imprime();
        arr.media();
        arr.preenche();
        arr.imprime();
        System.out.printf("\nMédia [%.1f]",arr.media());
        System.out.printf("\nMaior [%d]",arr.maior());
        System.out.printf("\nMenor [%d]\n",arr.menor());
    }
}
