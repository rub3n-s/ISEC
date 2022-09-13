package comparators;

import java.util.Comparator;
import interfaces.IMaxLoad;

public class WeigthComparator implements Comparator<IMaxLoad> {
    @Override
    public int compare(IMaxLoad o1, IMaxLoad o2) {
        return o1.getMaxWeight() - o1.getMaxWeight();
    }
}