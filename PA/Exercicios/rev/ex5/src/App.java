import java.util.Scanner;

import aposta.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Aposta ap = new Aposta();
        int op = 0, num = 0;

        do {
            System.out.println("\n\n1 - Aposta Principal");
            System.out.println("2 - Número da Sorte");
            System.out.println("3 - Imprimir");
            System.out.println("4 - Preenche Automaticamente");
            System.out.println("0 - Sair");

            System.out.print("\nOpção: ");
            op = sc.nextInt();

            switch(op) {
                case 1: 
                    System.out.print("\nNumero: ");
                    num = sc.nextInt();
                    ap.preenche(num, true);
                    break;
                case 2:
                    System.out.print("\nNumero: ");
                    num = sc.nextInt();
                    ap.preenche(num, false);
                    break;
                case 3:
                    ap.imprime();
                    break;
                case 4:
                    ap.preencheAuto();
                    break;
                default:
                    System.out.println("Opção inválida!\n");
            }
        } while(op != 0);
    }
}
