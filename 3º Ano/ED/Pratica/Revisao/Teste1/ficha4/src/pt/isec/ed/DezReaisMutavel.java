package pt.isec.ed;

import java.util.Iterator;

public class DezReaisMutavel extends DezReais {
    int modificacoes = 0;

    public void remove(int pos) {
        drRemove(pos);
        modificacoes++;
    }

    public void adiciona(double num) {
        add(num);
        modificacoes++;
    }

    public int getModificacoes() { return modificacoes; }
    @Override
    public Iterator<Double> iterator() {
        return new DezReaisMutavelIt(this);
    }
}
