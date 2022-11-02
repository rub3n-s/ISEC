package ficha4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReaisMutavel implements Iterator<Double> {
    DezReaisMutavel dr;
    private int posUltimo = -1; // indice do ultimo valor devolvido
    private boolean podeRemover = false;
    private int modificacoesConhecidas;
    
    public ItDezReaisMutavel(DezReaisMutavel dr) {
        this.dr = dr;
        modificacoesConhecidas = dr.getModifcacoes();
    }

    public boolean verificaModificacao() {
        // caso a estrutura tenha sido modificada sem o conhecimento do iterador, gera excepcao
        if (modificacoesConhecidas != dr.getModifcacoes())
            return false;
        return true;
    }

    public Double next() {
        verificaModificacao();
        if (posUltimo + 1 >= dr.size())
            throw new NoSuchElementException();
        podeRemover = true;
        return dr.get(++posUltimo);
    }

    public boolean hasNext() {
        verificaModificacao();
        return posUltimo + 1 < dr.size();
    }
    
    @Override
    public void remove() {
        if (!podeRemover)
            throw new IllegalStateException();
        dr.remove(posUltimo);
        posUltimo--;
        modificacoesConhecidas++;
    }
}
