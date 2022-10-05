package aleatorio;

import java.util.Random;

public class numAleatorio {
    private int numero;

    public numAleatorio() {
        Random rnd = new Random();
        numero = rnd.nextInt(101);
    }

    public int getNum() {
        return numero;
    }

    public boolean verifica(int num) {
        if (numero == num) {
            return true;
        }
        return false;
    }

    public void situacao(int num) {
        if (!verifica(num)) {
            if (num > numero) {
                System.out.println("O palpite foi acima do numero!");
            } else {
                System.out.println("O palpite foi abaixo do numero!");
            }
        } else {
            System.out.println("Parabens, acertou!");
        }
    }
}
