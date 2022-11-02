package ficha4;

import java.util.Iterator;

public class DezReaisMutavel extends DezReais {
    int modificacoes = 0;
    
    public void remove(int pos) {
        array.remove(pos);
        modificacoes++;
    }

    public void adicionar(Double num) {
        add(num);
        modificacoes++;
    }

    public int getModifcacoes() { return modificacoes; }

    @Override
    public Iterator<Double> iterator() {
        //return new ItDezReaisMutavel(this);
        return new ItDezReaisPositivos(this);   // torna-se o iterador padrao
    }
}
