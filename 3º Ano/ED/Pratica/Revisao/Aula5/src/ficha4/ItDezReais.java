package ficha4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReais implements Iterator<Double> {
    DezReais dr;
    int posUltimo = -1;     // indice do ultimo valor devolvido
    //Iterator<Double> it = dr.iterator();
    //boolean proximo = it.hasNext();

    public ItDezReais(DezReais dr) {
        this.dr = dr;    
    }

    @Override
    public boolean hasNext() {
        // enquanto o ultimo elemento for menor que o tamanho do array
        return posUltimo + 1 < dr.size(); 
    }

    @Override
    public Double next() {
        // lanca excepcao se a pos. seguinte estiver for do tam. do array
        if (posUltimo >= dr.size())
            throw new NoSuchElementException();
        return dr.get(++posUltimo);
    }
    
}
