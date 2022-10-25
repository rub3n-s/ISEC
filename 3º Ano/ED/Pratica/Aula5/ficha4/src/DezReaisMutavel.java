import java.util.Iterator;

public class DezReaisMutavel extends DezReais {
    int modificacoes = 0;

    void remove(int pos) {
        lista.remove(pos);
        modificacoes++;
    }

    public void acrescenta(Double valor) {
        modificacoes++;
        add(valor);
    }

    public int getModificacoes() { return modificacoes; }

    public Iterator<Double> iterator() {
        //return new ItDezReaisMutavel(this);
        return new ItDezReaisPositivos(this);   // torna-se o iterador padrao
    }
}
