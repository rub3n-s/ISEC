package comparators;

import java.util.Comparator;
import interfaces.IPassengers;

public class LoadComparator implements Comparator<IPassengers> {
    @Override
    public int compare(IPassengers o1, IPassengers o2) {
        return o1.getNumberPassengers() - o2.getNumberPassengers();
    }
}
