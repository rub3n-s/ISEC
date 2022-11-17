import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class ex1 {
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

    public static void main(String[] args) throws Exception {
        // ============= Ex1
        List list = new ArrayList();

        list.add("A");  list.add("B");  list.add("C");

        System.out.println("Lista original: " + list);
        Collections.fill(list, "ED");

        System.out.println("Lista preenchida com fill: " + list);

        myFill(list,"F");
        System.out.println("Lista com myFill: " + list);

        // ============= Ex2
        imprimeInverso(list);
    }
}
