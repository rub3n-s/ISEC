package pt.isec.ed.ex3;

import java.util.List;
import java.util.ListIterator;

public class Fila<T> {
    List<? super T> l;

    public Fila(List<? super T> li) {
        this.l = li;
        this.l.clear();
    }

    public boolean empty() {
        return l.size() == 0;
    }

    public void add(T n) {
        l.add(n);
    }

    public T remove() { // remove o primeiro elemento da fila
        return (T) l.remove(0);
    }

    public T element() {
        ListIterator <? super T> li = l.listIterator();
        return (T) li.next();
    }
}