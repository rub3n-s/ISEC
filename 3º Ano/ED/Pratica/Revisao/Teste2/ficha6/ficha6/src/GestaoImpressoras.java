import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;

public class GestaoImpressoras {
    Map<String,Impressora> map = new HashMap<>();

    public Impressora getImpressora(String nome) {
        return map.get(nome);
    }

    public Set<String> getNomesImpressoras() {
        return map.keySet();
    }

    public void acrescentaImpressora(Impressora i) {
        map.put(i.getNome(), i);
    }

    public void removeImpressora(String nome) {
        map.remove(nome);
    }

    public boolean existeImpressora(String nome) {
        return map.containsKey(nome);
    }


    // Exercico 2.b)
    PriorityQueue<Impressora> queue = new PriorityQueue<Impressora>(
        new Comparator<Impressora>() {
            public int compare(Impressora a, Impressora b) {
                return a.getNumTrabalhos() - b.getNumTrabalhos();
            }
        }
    );

    public void imprime(Trabalho t) {
        Impressora imp = queue.poll();
        imp.enviaTrabalho(t);
        queue.add(imp);
    }

    public void mostraFila() {
        Iterator i = queue.iterator();
        Impressora imp;
        while(i.hasNext()) {
            imp = (Impressora) i.next();
            System.out.println(imp.getNome());
        }
    }
}
