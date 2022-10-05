package com.company;

import java.util.Random;
import java.util.Scanner;


class ListaInteiros {
    private static final int TAM = 20;
    private int repetidos = 0;
    private int [] array = new int [20];

    public ListaInteiros() { array = new int[TAM]; }

    public void geraLista() {
        Random rnd = new Random();
        for (int i = 0; i < array.length; i++)
            array[i] = rnd.nextInt(101);
    }

    /* fazer a alteracao no resto das funcoes */
    public void listagem(int [] arr) {
        System.out.println("Lista de inteiros: \n");
        for (int i = 0; i < arr.length; i++)
            System.out.printf("[%d] ",arr[i]);
    }

    public int verificaRepetidos(int [] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++)
                if (arr[i] == arr[j] && i != j)
                    repetidos++;
        }
        return repetidos;
    }

    public void quaisRepetidos(int [] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++)
                if (arr[i] == arr[j] && i != j)
                    System.out.printf("[%d] ", arr[i]);
        }
    }
}

public class Main {

    public static void main(String[] args) {
        ListaInteiros list = new ListaInteiros();
        int []arr = new int[20];

        Scanner sc = new Scanner(System.in);
        Random rnd = new Random();

        for (int i = 0; i < arr.length; i++)
            arr[i] = rnd.nextInt(100) + 1;

        list.listagem(arr);

        System.out.printf("\n\nRepetidos [%d]\n",list.verificaRepetidos(arr));
        if (list.verificaRepetidos(arr) > 0) {
            System.out.println("Quais são? ");
            list.quaisRepetidos(arr);
        }
    }
}
