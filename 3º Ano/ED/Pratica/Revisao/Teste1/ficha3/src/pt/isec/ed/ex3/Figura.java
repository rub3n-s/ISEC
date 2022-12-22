package pt.isec.ed.ex3;

abstract public class Figura implements Comparable<Figura> {
    abstract float area();

    @Override
    public int compareTo(Figura o) {
        if (area() > o.area())
            return 1;
        else if (area() < o.area())
            return -1;
        return 0;
    }
}
