package array;

import java.util.Random;

public class Array {
    private static int [] arr;

    public Array(int elementos) {
        arr = new int[elementos];
        Random rnd = new Random();
        for (int i = 0; i < elementos; i++)
            arr[i] = rnd.nextInt(100);
    }

    public static void imprime() {
        System.out.println("[Array]");
        for (int i = 0; i < arr.length; i++)
            System.out.printf("[%d] ", arr[i]);
        System.out.println();
    }

    public static int getMaior() {
        int maior = arr[0];
        for (int i = 0; i < arr.length; i++)
            if (maior < arr[i])
                maior = arr[i];
        return maior;
    }

    public static int getMenor() {
        int menor = arr[0];
        for (int i = 0; i < arr.length; i++)
            if (menor > arr[i])
                menor = arr[i];
        return menor;
    }

    public static double getMedia() {
        int soma = 0;
        for (int i = 0; i < arr.length; i++)
            soma += arr[i];
        return soma/arr.length;
    }

    public static void inverter() {
        System.out.println("[Array invertido]");
        for (int i = arr.length - 1; i >= 0; i--)
            System.out.printf("[%d] ",arr[i]);
        System.out.println();
    }
}
