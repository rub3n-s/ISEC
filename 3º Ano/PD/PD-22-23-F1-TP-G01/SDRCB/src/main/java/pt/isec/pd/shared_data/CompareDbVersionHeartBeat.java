package pt.isec.pd.shared_data;

import java.util.Comparator;

public class CompareDbVersionHeartBeat implements Comparator<HeartBeat> {
    @Override
    public int compare(HeartBeat o1, HeartBeat o2) {
        int firstComp = Integer.compare(o1.getDbVersion(),o2.getDbVersion());
        if(firstComp != 0) {
            return firstComp;
        }

        return -Integer.compare(o1.getActiveConnections(),o2.getActiveConnections());
    }
}
