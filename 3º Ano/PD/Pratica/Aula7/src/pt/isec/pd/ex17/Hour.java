package pt.isec.pd.ex17;

import java.io.Serial;
import java.io.Serializable;

public class Hour implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    protected int hours;
    protected int minutes;
    protected int seconds;

    public Hour(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    @Override
    public String toString() {
        return hours + ":" + minutes + ":" + seconds;
    }
}
