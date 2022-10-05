package numAleatorio;

import java.util.Random;

public class numAleatorio {
    private int numGerado;

    public numAleatorio() {
        Random rnd = new Random();
        numGerado = rnd.nextInt(101);
    }

    public int getNum() {
        return numGerado;
    }

    public void geraNovo() {
        Random rnd = new Random();
        numGerado = rnd.nextInt(101);
    }
}
