package pt.isec.pd.shared_data;

import java.io.Serial;
import java.io.Serializable;

public class Triple<T,U,V> implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private final T first;
    private final U second;
    private final V third;

    public Triple(T first, U second, V third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    public T getFirst() { return first; }

    public U getSecond() { return second; }

    public V getThird() { return third; }
}
