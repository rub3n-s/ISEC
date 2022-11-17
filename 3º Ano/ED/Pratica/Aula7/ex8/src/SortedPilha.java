import java.util.ArrayList;

public class SortedPilha<T extends Comparable<? super T>>  {
    Pilha <T> val = new Pilha<>(new ArrayList<>());
    Pilha <T> min = new Pilha<>(new ArrayList<>());

    public void push(T value) {
        if (min.empty() || min.peek().compareTo(value) >= 0)
            min.push(value);
        val.push(value);
    }

    public T pop() {
        T ret = val.pop();
        if (ret.compareTo(min.peek()) == 0)
            min.pop();
        return ret;
    }

    public T findMin() {
        return min.peek();
    }

    public void show() {
        System.out.println("Valores: "); val.show();
        System.out.println("Minimos: "); min.show();
    }
}
