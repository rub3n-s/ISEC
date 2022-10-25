import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReaisPositivos implements Iterator<Double> {
    DezReaisMutavel dr;
    private int posUltimo = -1; // indice do ultimo valor devolvido

    public ItDezReaisPositivos(DezReaisMutavel object) {
        this.dr = object;
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
