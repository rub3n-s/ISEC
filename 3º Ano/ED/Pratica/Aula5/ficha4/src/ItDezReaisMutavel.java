import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReaisMutavel implements Iterator<Double> {
    DezReaisMutavel dr;
    private int posUltimo = -1; // indice do ultimo valor devolvido
    private boolean podeRemover;
    private int modificacoesConhecidas;

    public ItDezReaisMutavel(DezReaisMutavel object) {
        this.dr = object;
        modificacoesConhecidas = object.getModificacoes();
        podeRemover = false;
    }

    public void verificaModificacao() {
        // caso a estrutura tenha sido modificada sem o conhecimento do iterador, gera excepcao
        if (modificacoesConhecidas != dr.modificacoes)
            throw new ConcurrentModificationException();
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
    
    public void remove() {
        if (!podeRemover)
            throw new IllegalStateException();
        dr.remove(posUltimo);
        posUltimo--;
        modificacoesConhecidas++;
    }
}
