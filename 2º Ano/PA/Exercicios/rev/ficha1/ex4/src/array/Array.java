package array;

import java.util.Random;

public class Array {
    private int [] arr;
    private int [] arrDup;
    private int duplicados;

    public Array(int elementos) {
        arr = new int[elementos];
        arrDup = new int[elementos];
        Random rnd = new Random();
        int random;
        for (int i = 0; i < arr.length; i++) {
            do {
                random = rnd.nextInt(101);
                if (!repetido(random))
                    arr[i] = rnd.nextInt(101);
                else {
                    arrDup[duplicados] = random;
                    duplicados++;
                } 
            } while(repetido(random));
        }
    }

    private boolean repetido(int numero) {
        if (arr[0] != 0) {
            for (int i = 0; i < arr.length; i++)
                if (arr[i] == numero)
                    return true;
        }
        return false;
    }

    public void imprime() {
        System.out.println("[Normal]");
        for (int i = 0; i < arr.length; i++)
            System.out.printf("[%d] ", arr[i]);
        System.out.println();
    }

    public void getDuplicados() {
        System.out.println("[Duplicados]");
        if (duplicados > 0) {
            for (int i = 0; i < duplicados; i++)
                System.out.printf("[%d] ", arrDup[i]);
            System.out.println();
        } else {
            System.out.println("Não foram gerados números duplicados\n");
        }
    }
}
