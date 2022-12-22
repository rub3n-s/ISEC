package pt.isec.ed;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class DezReais implements Iterable<Double> {
    private static double[] arr;
    //List<Double> arr;
    private static final int MAX = 10;
    private int counter = 0;

    public DezReais() {
        arr = new double[MAX];
        //arr = new ArrayList<Double>();
    }

    // Exercicio 1
    public boolean add(double num) {
        if (counter >= MAX)
            throw new RuntimeException();
        arr[counter] = num;
        counter++;
        return true;
    }

    public int size() { return arr.length; }

    public Double get(int pos) { return arr[pos]; }

    public void drRemove(int pos) {
        for (int i = pos; i < arr.length - 1; i++)
            arr[i] = arr[i + 1];
    }

    @Override
    public Iterator<Double> iterator() {
        return new DezReaisIt(this);
    }
}
