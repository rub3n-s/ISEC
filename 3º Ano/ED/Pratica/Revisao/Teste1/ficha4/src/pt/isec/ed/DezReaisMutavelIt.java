package pt.isec.ed;

import java.util.Iterator;

public class DezReaisMutavelIt implements Iterator<Double> {
    DezReaisMutavel dezReaisMutavel;
    int posUltimo = 0;

    public DezReaisMutavelIt(DezReaisMutavel dezReaisMutavel) {
        this.dezReaisMutavel = dezReaisMutavel;
    }

    @Override
    public boolean hasNext() {
        return posUltimo + 1 < dezReaisMutavel.size();
    }

    @Override
    public Double next() {
        return dezReaisMutavel.get(posUltimo++);
    }

    @Override
    public void remove() {
        dezReaisMutavel.remove(posUltimo);
    }
}
