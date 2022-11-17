import java.util.HashMap;
import java.util.Set;

public class GestorImpressoras {
    HashMap<String,Impressora> mp = new HashMap<>();

    public Impressora getPrinter(String nome) {
        return (Impressora) mp.get(nome);    // O(1)
    }

    public Set<String> getNomes() {
        return mp.keySet();
    }

    public void acrescentaImpressora(Impressora i) {
        mp.put(i.getNome(), i);
    }

    public void removeImpressora(Impressora i) {
        mp.remove(i.getNome());
    }

    public boolean existeImpressora(Impressora i) {
        if (mp.containsKey(i.getNome()))
            return true;
        return false;
    }
}
