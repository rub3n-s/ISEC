package book;

import java.util.ArrayList;

public class RecentBook extends Book {
    private final String ISBN;
    private final double price;

    public RecentBook(String title, ArrayList<String> authors, String isbn, double price) {
        // chama o construtor Book
        super(title,authors);

        // define os restantes parametros
        this.ISBN = isbn;
        this.price = price;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n* Recent Book *");
        sb.append("\n\tID: " + this.getId());
        sb.append("\n\tTitle: " + this.getTitle());
        for (var a : this.getAuthors())
            sb.append("\n\tAuthor: " + a);
        sb.append("\n\tISBN: " + this.ISBN);
        sb.append("\n\tPrice: " + this.price + "\n");
        return sb.toString();
    }
}
