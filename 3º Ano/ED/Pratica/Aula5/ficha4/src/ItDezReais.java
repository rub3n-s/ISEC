import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReais implements Iterator<Double> {
    DezReais dr;
    Iterator<Double> it = dr.iterator();
    int posUltimo = -1; // indice do ultimo valor devolvido

    boolean proximo = it.hasNext();

    public ItDezReais(DezReais object) {
        this.dr = object;
    }

    @Override
    public Double next() {
        if (posUltimo + 1 >= dr.size())
            throw new NoSuchElementException();
        return dr.get(++posUltimo);
    }

    @Override
    public boolean hasNext() {
        return posUltimo + 1 < dr.size();
    }
}
