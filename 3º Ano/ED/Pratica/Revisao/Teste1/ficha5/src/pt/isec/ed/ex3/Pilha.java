package pt.isec.ed.ex3;

import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;

public class Pilha<T> {
    List<? super T> list;

    public Pilha(List<? super T> list) {
        this.list = list;
        list.clear();
    }

    public boolean empty() {
        return list.size() == 0;
    }

    public T peek() {
        if (!empty()) {
            ListIterator<? super T> it = list.listIterator(list.size());
            return (T) it.previous();
        }
        throw new NoSuchElementException();
    }

    public <T> T pop() {
        if (!empty())
            return (T) list.remove(list.size() - 1);
        throw new NoSuchElementException();
    }

    public void push(T value) {
        list.add(value);
    }
}