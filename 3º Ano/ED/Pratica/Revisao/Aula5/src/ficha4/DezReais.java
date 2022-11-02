package ficha4;

import java.util.ArrayList;
import java.util.Iterator;

public class DezReais implements Iterable<Double> {
    private static final int LIMITE = 10;
    ArrayList<Double> array;
    protected int last = 0;
    
    public DezReais() {
        this.array = new ArrayList<>();
    }

    public void add(Double num) {
        if (array.size() >= LIMITE)
            throw new RuntimeException();
        array.add(num);
    }

    public int size() {
        return array.size();
    }

    public Double get(int pos) {
        return array.get(pos);
    }

    @Override
    public Iterator<Double> iterator() {
        return new ItDezReais(this);
    }
}
