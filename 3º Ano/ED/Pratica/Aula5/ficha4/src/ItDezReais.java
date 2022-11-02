import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReais implements Iterator<Double> {
    DezReais dr;
    int posUltimo = -1; // indice do ultimo valor devolvido

    public ItDezReais(DezReais object) {
        this.dr = object;
    }

    public Double next() {
        if (posUltimo + 1 >= dr.size())
            throw new NoSuchElementException();
        return dr.get(++posUltimo);
    }

    public boolean hasNext() {
        return posUltimo + 1 < dr.size();
    }
}
