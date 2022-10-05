package pt.isec.pa.biblio.model.books;

import java.util.List;

public class RecentBook extends Book {
    private String isbn;
    private double cost;

    public RecentBook(String title, List<String> authors,String isbn, double cost) {
        super(title, authors);
        this.isbn = isbn;
        this.cost = cost;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    @Override
    public String toString() {
        return String.format("*Recent Book* %s, isbn: %s, cost: %.2f",
                    super.toString(), isbn, cost);
    }
}
