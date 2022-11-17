import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class App {
    public static <T> void myFill(List<? super T> list, T value) {
        //Collections.fill(list, value);
        // for (int j = 0; j < list.size(); j++)    d.set(j,value);     // O(N2) em linked list
        ListIterator it = list.listIterator();
        while(it.hasNext()) {
            it.next();
            it.set(value);
        }
    }

    public static void imprimeInverso(List<?> list) {
        // quando inicializa no fim é porque vai percorrer no sentido contrario
        ListIterator it = list.listIterator(list.size());  

        int j = list.size();

        while(it.hasPrevious())
            System.out.print("[" + (--j) + "]" + it.previous() + " ");
        System.out.println();
    }

    public static <T> void rev(List<? super T> list) { 
        ListIterator iti = list.listIterator();
        ListIterator itf = list.listIterator(list.size());
        T temp;

        while(iti.nextIndex() < itf.previousIndex()) {
            temp = (T) iti.next();
            iti.set(itf.previous());
            itf.set(temp);
        }
    }
    
    public static void main(String[] args) throws Exception {
        // ============= Ex1
        List list = new ArrayList();

        list.add("A");  list.add("B");  list.add("C");
        list.add("D");  list.add("E");

        System.out.println("Normal: " + list);

        //System.out.println("Inverso: " + );

        rev(list);

        System.out.println("Inverso: " + list);
    }
}
