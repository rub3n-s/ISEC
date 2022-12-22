package pt.isec.ed;

import java.util.Iterator;

public class DezReaisPositivosIt implements Iterator<Double> {
    DezReaisMutavel dr;
    int posUltimo = -1;

    public DezReaisPositivosIt(DezReaisMutavel dezReaisMutavel) {
        this.dr = dezReaisMutavel;
    }

    @Override
    public void remove() {
        //Iterator.super.remove();
    }

    private int nextPositiveIndex(int from) {
        if (from >= dr.size()) return -1;
        while(dr.get(from) > 0)
            if (++from >= dr.size())
                return -1;
        return from;
    }

    public Double next() {
        posUltimo = nextPositiveIndex(++posUltimo);
        return dr.get(++posUltimo);
    }

    public boolean hasNext() {
        return nextPositiveIndex(posUltimo + 1) >= 0;
    }
}
