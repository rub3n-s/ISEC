package matrizexemplo;

import java.lang.module.InvalidModuleDescriptorException;

public class MatrizExemplo {
    private float [][] values;

    private MatrizExemplo() {

    }

    public MatrizExemplo(int linhas, int colunas) {
        values = new float[linhas][colunas];
    }

    public MatrizExemplo(MatrizExemplo other) {
        values = new float[other.values.length][other.values[0].length];
        for (int i = 0; i < other.values[i].length; i++)
            for (int j = 0; j < other.values[j].length; j++)
                values[i][j] = other.get(i, j);
        
        // outro método
        //_copy(other);
    }

    public void set(int linha, int coluna, float value) {
        values[linha][coluna] = value;
    }

    public float get(int linha, int coluna) {
        return values[linha][coluna];
    }

    public void show() {
        for (int i = 0; i <  values.length; i++) {
            for (int j = 0; j < values[i].length; j++)
                System.out.printf("%8.2f", values[i][j]);
            System.out.print("\n");
        }
        System.out.print("\n");
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        MatrizExemplo newm = new MatrizExemplo();   // construtor private
        newm._copy(this);
        return newm;
    }

    public boolean add(MatrizExemplo m2) {
        if (values.length != m2.values.length)
            return false;

        return true;
    } 

    public static MatrizExemplo add_2(MatrizExemplo m1, MatrizExemplo m2) {
        if (m1.values.length != m2.values.length)
            System.out.print("Erro");
            //return m1;
        MatrizExemplo newm = new MatrizExemplo(m1);
        //MatrizExemplo newm = (MatrizExemplo)m1.clone();

        return newm;
        
    } 
}
