package matriz;

import java.util.Random;

public class Matriz {
    private int [][] mat;
    private int linhas, colunas;

    public Matriz (int lin, int col) {
        mat = new int[lin][col];
        linhas = lin; colunas = col;
        Random rnd = new Random();
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                mat[i][j] = rnd.nextInt(10);
    }

    public void imprime() {
        for (int i = 0 ; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++)
                System.out.printf("%d ", mat[i][j]);
            System.out.println();
        }
        System.out.println("\n");
    }

    public void soma() {
        int [] arrLin = new int[linhas];
        int [] arrCol = new int[colunas];
        int somaTotal = 0;
        System.out.println("\nSoma das linhas: ");
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++)
                arrLin[i] += mat[i][j];
        }

        for (int i = 0; i < arrLin.length; i++) {
            System.out.printf("[%d] ",arrLin[i]);
            somaTotal += arrLin[i];
        }
        
        System.out.println("\nSoma das colunas: ");
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                arrCol[j] += mat[i][j];
            }
        }

        for (int i = 0; i < arrCol.length; i++) {
            System.out.printf("[%d] ", arrCol[i]);
            somaTotal += arrCol[i];
        }

        System.out.printf("\nSoma total: %d\n", somaTotal);
    }
}
