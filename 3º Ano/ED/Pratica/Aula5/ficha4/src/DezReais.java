import java.util.ArrayList;
import java.util.Iterator;

public class DezReais implements Iterable<Double> {
    private static final int LIMITE = 10;
    ArrayList<Double> lista;
    protected int last = 0;

    public DezReais() {
        lista = new ArrayList<>();
    } 

    public void add(Double num) throws Exception {
        if (lista.size() >= LIMITE)
            throw new RuntimeException();
        lista.add(num);    
    }

    public void getList() {
        for (var l : lista)
            System.out.print(l + " ");
        System.out.println();
    }

    public Iterator <Double> iterator() {
        return new ItDezReais(this);
    }

    public Double get(int pos) { return lista.get(pos); }

    public int size() { return lista.size(); }
}
