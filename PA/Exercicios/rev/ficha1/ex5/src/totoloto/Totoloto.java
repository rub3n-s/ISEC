package totoloto;

import java.util.Random;

public class Totoloto {
    private int [] num = new int [5];
    private int sorte;

    public Totoloto() {
        Random rnd = new Random();
        int random;
        for (int i = 0; i < num.length; i++) {
            random = rnd.nextInt(49) + 1;
            if (!repetido(random)) 
                num[i] = random;
            else {
                do {
                    random = rnd.nextInt(49) + 1;
                } while(repetido(random));
                num[i] = random;
            }
        }
        sorte = rnd.nextInt(13) + 1;
    }

    private boolean repetido(int numero) {
        for (int i = 0; i < num.length; i++)
            if (numero == num[i])
                return true;
        return false;
    }

    public void imprime() {
        System.out.println("[APOSTA]");
        for (int i = 0; i < num.length; i++)
            System.out.printf("[%d]", num[i]);
        System.out.printf("\nNumero da Sorte [%d]\n",sorte);
    }
}
