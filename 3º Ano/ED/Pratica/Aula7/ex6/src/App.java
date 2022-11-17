import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class App {
    public static <T> void revPrint(Collection<T> col) {
        Pilha<T> pilha = new Pilha<>(new ArrayList<T>());
        
        for (T valor : col) pilha.push(valor);
        while(!pilha.empty())
            System.out.println(pilha.pop());            
    }

    public static void main(String[] args) throws Exception {
        List list = new ArrayList();
        list.add("A");  list.add("B");  list.add("C");
        list.add("D");  list.add("E");
        
        System.out.println(list);
        revPrint(list);
    }
}
