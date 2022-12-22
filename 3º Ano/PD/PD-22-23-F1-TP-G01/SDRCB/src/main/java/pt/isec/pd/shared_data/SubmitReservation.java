package pt.isec.pd.shared_data;

import java.io.Serializable;
import java.util.List;

public class SubmitReservation implements Serializable {
    private int showId;
    private List<Seat> seats;

    public SubmitReservation(int showId, List<Seat> seats) {
        this.showId = showId;
        this.seats = seats;
    }

    public int getShowId() {
        return showId;
    }

    public void setShowId(int showId) {
        this.showId = showId;
    }

    public List<Seat> getSeats() {
        return seats;
    }

    public void setSeats(List<Seat> seats) {
        this.seats = seats;
    }

    @Override
    public String toString() {
        return "SubmitReservation{" +
                "showId=" + showId +
                ", seats=" + seats +
                '}';
    }
}
