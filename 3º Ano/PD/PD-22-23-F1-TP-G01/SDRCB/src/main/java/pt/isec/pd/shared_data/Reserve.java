package pt.isec.pd.shared_data;

import java.io.Serial;
import java.io.Serializable;
import java.util.List;

public class Reserve implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    protected int id;
    protected String dateReserve;
    protected String dateShow;
    protected boolean paied;
    protected int userId;
    protected int showId;
    protected List<Seat> seats;

    public Reserve(int id, String dateHour, boolean paied, int userId, int showId,String dateShow) {
        this.id = id;
        this.dateReserve = dateHour;
        this.paied = paied;
        this.userId = userId;
        this.showId = showId;
        this.dateShow = dateShow;
    }

    public int getId() { return id; }

    public String getDateReserve() { return dateReserve; }

    public boolean isPaied() { return paied; }

    public int getUserId() { return userId; }

    public int getShowId() { return showId; }

    public List<Seat> getSeats() {
        return seats;
    }

    public void setSeats(List<Seat> seats) {
        this.seats = seats;
    }

    public void setDateShow(String dateShow) {
        this.dateShow = dateShow;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Espetáculo: ").append(showId).append(" ").append(dateShow).append("\n").append("Data: ").append(dateReserve).append("\n");
        for (Seat seat : seats) {
            builder.append("Lugar: ").append(seat.getRow()).append(seat.getNumber()).append("\n");
        }

        return builder.toString();
    }
}
