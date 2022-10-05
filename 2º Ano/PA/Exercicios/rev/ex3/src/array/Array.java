package array;

import java.util.Random;

public class Array {
    static int [] array;
    static boolean preenche = false;

    public Array(int nEle) {
        array = new int[nEle];
        System.out.printf("Array criado com [%d] elementos!\n",nEle);
    }

    public static void imprime() {
        for (int i = 0; i < array.length; i++)
            System.out.printf("[%d] ",array[i]);
        System.out.println();
    }

    public static void preenche() {
        Random rnd = new Random();
        for (int i = 0; i < array.length; i++)
            array[i] = rnd.nextInt(100) + 1;
        preenche = true;
    }
    public static int maior() {
        if (preenche) {
            int maior = array[0];
            for (int i = 0; i <  array.length; i++)
                if (maior < array[i])
                    maior = array[i];
            return maior;
        } else {
            System.out.println("Deve preencher o array primeiro!");
            return 0;
        }
    }

    public static int menor() {
        if (preenche) {
            int menor = array[0];
            for (int i = 0; i < array.length; i++) 
                if (menor > array[i])
                    menor = array[i];
            return menor;
        } else {
            System.out.println("Deve preencher o array primeiro!");
            return 0;
        }
    }

    public static double media() {
        if (preenche) {
            double media = 0;
            int soma = 0;
            for (int i = 0; i < array.length; i++)
                soma += array[i];
            media = soma/array.length;
            return media;
        } else {
            System.out.println("Deve preencher o array primeiro!");
            return 0.0;
        }   
    }
}
