package ficha4;

import java.util.Iterator;

public class ItDezReaisPositivos implements Iterator<Double> {
    DezReaisMutavel dr;
    private int posUltimo = -1;

    public ItDezReaisPositivos(DezReaisMutavel dr) {
        this.dr = dr;
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
