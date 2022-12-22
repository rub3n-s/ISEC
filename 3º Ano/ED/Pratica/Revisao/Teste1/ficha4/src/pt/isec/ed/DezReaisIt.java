package pt.isec.ed;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class DezReaisIt implements Iterator<Double> {
    DezReais dezReais;
    int posUltimo = 0;

    public DezReaisIt(DezReais dezReais) {
        this.dezReais = dezReais;
    }

    @Override
    public boolean hasNext() {
        return posUltimo + 1 <= dezReais.size();
    }

    @Override
    public Double next() {
        if (!hasNext())
            throw new NoSuchElementException();
        return dezReais.get(posUltimo++);
    }

    @Override
    public void remove() {
        //Iterator.super.remove();
    }
}
