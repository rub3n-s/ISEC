package pt.isec.pd.shared_data;

import java.io.Serial;
import java.io.Serializable;

public class Seat implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private int id;
    private String row;
    private String number;
    private double price;
    private int showId;
    private boolean isReserved;

    public Seat(int id, String row, String number, double price, int showId) {
        this.id = id;
        this.row = row;
        this.number = number;
        this.price = price;
        this.showId = showId;
        this.isReserved = false;
    }

    public Seat(String row, String number, double price) {
        this.row = row;
        this.number = number;
        this.price = price;
    }

    public int getId() { return id; }

    public String getRow() { return row; }

    public String getNumber() { return number; }

    public double getPrice() { return price; }

    public int getShowId() { return showId; }

    public boolean isReserved() { return isReserved; }

    public void setReserved(boolean value) { isReserved = value; }

    @Override
    public String toString() {
        return "row: " + row + "   " +
                "number: " + number + "   " +
                "price: " + price;
        }
}
