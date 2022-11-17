import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class App {
    public static <T> void removePares(List<? super T> list) {
        ListIterator it = list.listIterator();
        List<T> l = new ArrayList<>(list.size()/2 + 1);     // garante o espaço necessário

        while(it.hasNext()) {
            it.next();
            if (it.hasNext())
                l.add((T)it.next());
        }
        list.clear();
        list.addAll(l);
    }

    public static <T> void removePares_O1(List<? super T> list) {
        ListIterator it = list.listIterator();

        while(it.hasNext()) {
            it.next();
            it.remove();
            if (it.hasNext())                
                it.next();
        }
    }

    public static void main(String[] args) throws Exception {
        // Alinea a)
        List list = new ArrayList();
        list.add("A");  list.add("B");  list.add("C");
        list.add("D");  list.add("E");
        
        //removePares(list);
        
        // Alinea b)
        removePares_O1(list);

        System.out.println(list);

        

    }
}
