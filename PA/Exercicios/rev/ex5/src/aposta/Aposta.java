package aposta;

import java.util.Random;

public class Aposta {
    private static final int MAX = 5;
    private int [] arr = new int [MAX];
    private int numSorte = 0;
    private int contador = 0;
    
    public Aposta() { }

    public boolean preenche(int num, boolean principal) {
        boolean repetido = false;

        if (principal) { // aposta principal
            if (num < 1 || num > 49) {
                System.out.println("Número fora dos limites permitidos [1 - 49]");
                return false;
            }
            if (contador > 0) {
                for (int i = 0; i < contador; i++)
                    if (num == arr[i])
                        repetido = true;
                if (repetido) {
                    System.out.printf("[%d] é repetido, inserir outro número!",num);
                    return false;
                }
            } else if (contador == MAX) {
                System.out.println("Aposta principal já está completa!");
                return false;
            }
            System.out.printf("[%d] adicionado com sucesso!\n",num);
            arr[contador] = num;
            contador++;  
        } else { // numero da sorte 
                if (num < 1 || num > 13) {
                    System.out.println("Número fora dos limites permitidos [1 - 13]");
                    return false;
                }                    
                if (numSorte != 0) {
                    System.out.println("Número da sorte já está preenchido!");
                    return false;
                }
                System.out.printf("[%d] adicionado com sucesso!\n",num);
                numSorte = num;
        }
        return true;
    }

    public void imprime() {
        System.out.print("Aposta principal: ");
        for (int i = 0; i < contador; i++)
            System.out.printf("[%d]",arr[i]);
        System.out.printf("\nNúmero de sorte: [%d]",numSorte);
    }

    public void preencheAuto() {
        reset(); // faz reset aos valores existentes
        Random rnd = new Random();
        for (int i = 0; i < MAX; i++)
            arr[i] = rnd.nextInt(49) + 1;
        numSorte = rnd.nextInt(13) + 1;
        imprime();
    }

    public boolean completa() {
        if (contador == MAX && numSorte != 0)
            return true;
        return false;
    }

    public void reset() {
        for (int i = 0; i < MAX; i++)
            arr[i] = 0;
        numSorte = 0;
    }
}
