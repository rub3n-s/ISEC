package pt.isec.ed.ex5;

public class Ponto<T extends Number, E extends Number> {
    T x;
    E y;

    public Ponto(T x, E y) {
        this.x = x;
        this.y = y;
    }

    public void copy(Ponto<? extends T,? extends E> a){
        this.x =  a.x;
        this.y = a.y;
    }

    @Override
    public String toString() { return "(" + x + "," + y + ')'; }
}
