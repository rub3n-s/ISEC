import java.util.Random;
import java.util.Scanner;

import matrizexemplo.MatrizExemplo;

public class App {
    public static void main(String[] args) throws Exception {
        int linhas = 0, colunas = 0;
        Scanner sc = new Scanner(System.in);

        System.out.print("Linhas: "); linhas = sc.nextInt();
        System.out.print("Colunas: "); colunas = sc.nextInt();

        MatrizExemplo matrix = new MatrizExemplo(linhas, colunas);

        Random rnd = new Random();
        for (int i = 0; i <  linhas; i++)
            for (int j = 0; j < colunas; j++)
                matrix.set(i,j,rnd.nextFloat());
                // matrix.set(i,j,(float) Math.random() * 100);

        matrix.show();

        //MatrizExemplo m2 = new MatrizExemplo(matrix);
        //m2.show();
        
        //MatrizExemplo m3 = (MatrizExemplo) matrix.clone();

        matrix.set(1,1,1000);
        matrix.show();

        MatrizExemplo m2 = new MatrizExemplo(linhas,colunas);

        //m2.add(m2);
        
    }
}
