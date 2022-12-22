package pt.isec.pd.shared_data;

import java.util.List;

public class UnPayedReserve extends Reserve {


    public UnPayedReserve(int id, String dateHour, boolean paied, int userId, int showId, String dateShow) {
        super(id, dateHour, paied, userId, showId, dateShow);
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Espetáculo: ").append(showId).append(" - ").append(dateShow).append("\n").append("Data: ").append(dateReserve).append("\n");
        for (Seat seat : seats) {
            builder.append("Lugar: ").append(seat.getRow()).append(seat.getNumber()).append(" - ").append(seat.getPrice()).append(" €").append("\n");
        }

        return builder.toString();
    }
}
