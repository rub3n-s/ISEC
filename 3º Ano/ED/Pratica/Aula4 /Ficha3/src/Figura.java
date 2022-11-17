abstract public class Figura implements Comparable<Figura>{
    abstract float area();

    @Override
    public int compareTo(Figura figura){
         if(area() > figura.area())
             return 1;
         else if (area() < figura.area()) {
             return -1;
         }
        return 0;
    }
}
