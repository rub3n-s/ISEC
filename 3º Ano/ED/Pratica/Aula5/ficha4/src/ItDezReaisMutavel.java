import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReaisMutavel implements Iterator<Double> {
    DezReais dr;
    Iterator<Double> it = dr.iterator();
    private Double valor = 5.0;
    private int posUltimo = -1; // indice do ultimo valor devolvido
    
    public ItDezReaisMutavel(DezReais object) {
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
    
    @Override
    public void remove() {
        if (valor.getClass() != Double.class)
            throw new IllegalStateException();
        while(it.hasNext()) {
            if (it.next() == valor)
                it.remove();
        }
        throw new NoSuchElementException();
    }
}
