package matriz;

import java.util.Random;

public class Matriz {
    private int [][] mat;
    private int linhas, colunas;

    public Matriz(int lin, int col) {
        mat = new int [lin][col];
        linhas = lin;
        colunas = col;
        Random rnd = new Random();
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                mat[i][j] = rnd.nextInt(10);
    }

    public void imprime() {
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++)
                System.out.printf("%d ", mat[i][j]);
            System.out.println();
        }
    }

    public void soma(Matriz sum) {
        for (int i = 0; i < sum.getLinhas(); i++)
            for (int j = 0; j < sum.getColunas(); j++)
                mat[i][j] += sum.mat[i][j];
    }

    public static Matriz soma_v2(Matriz m1, Matriz m2) {
        Matriz m = new Matriz(m1.getLinhas(),m1.getColunas());
        for (int i = 0; i < m1.getLinhas(); i++)
            for (int j = 0; j < m1.getColunas(); j++)
                m.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        return m;
    }

    public int getLinhas() {
        return linhas;
    }

    public int getColunas() {
        return colunas;
    }
}
