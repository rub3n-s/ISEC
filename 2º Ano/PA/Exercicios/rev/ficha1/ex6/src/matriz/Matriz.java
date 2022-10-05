package matriz;

import java.util.Random;

public class Matriz {
    private int [][] mat;
    private int [][] transp;
    private int linhas, colunas;

    public Matriz(int lin, int col) {
        mat = new int[lin][col];
        linhas = lin; colunas = col;
        Random rnd = new Random();
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                mat[i][j] = rnd.nextInt(7);
    }

    public void transporMatriz() {
        transp = new int [colunas][linhas];
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                transp[j][i] = mat[i][i];
    }

    public void imprime() {
        System.out.println("Matriz Normal: ");
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                System.out.printf("%d ", mat[i][j]);

        System.out.println("\n\nMatriz Transposta: ");
        for (int i = 0; i < transp.length; i++)
            for (int j = 0; j < transp[i].length; j++)
                System.out.printf("%d ", transp[i][j]);
        System.out.println();
    }
}
