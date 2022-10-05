package inventario;

import java.util.HashMap;
import java.util.Map;

public class Inventario {
    Map<String,Map<Integer,Integer>> inv;

    public Inventario() {
        inv = new HashMap<>();
    }

    public boolean addProduto(String cola, int codigo, int preco) {
        if (cola!=null && codigo>0 && preco>0) {
            inv.put(cola, new HashMap<Integer,Integer>());
            inv.get(cola).put(codigo, preco);
            return true;
        }
        return false;
    }

    public int getPreco(Object obj) {
        //if (codigo>0) {
            for (var i : inv.entrySet())
                if (i.getValue().containsKey(obj))
                    return i.getValue().get(obj);
                //else if (i.getKey().equals(obj.toString()))
                    //return i.getValue();
        //}
        return 0;
    }

    public int getCodigo(Object obj) {
        
        return 0;
    }    
}
