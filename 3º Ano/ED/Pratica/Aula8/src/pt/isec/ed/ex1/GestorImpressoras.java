package pt.isec.ed.ex1;

import java.util.*;

public class GestorImpressoras {
    HashMap<String,Impressora> mp = new HashMap<>();

    public Impressora getPrinter(String nome) {
        return mp.get(nome);    // O(1)
    }

    public Set<String> getNomes() {
        return mp.keySet();
    }

    public void acrescentaImpressora(Impressora i) {
        mp.put(i.getNome(), i);

        // Exercicio 2 b)
        queue.add(i);
    }

    public void removeImpressora(Impressora i) {
        mp.remove(i.getNome());
    }

    public boolean existeImpressora(Impressora i) {
        return mp.containsKey(i.getNome());
    }

    //  Exercicio 2
    //  b)
    private PriorityQueue<Impressora> queue = new PriorityQueue<>(
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
            imp.show();
        }
    }
}
