package book;

import java.util.ArrayList;

public class OldBook extends Book {
    private final int copies;

    public OldBook(String title, ArrayList<String> authors, int copies) {
        // chama o construtor book
        super(title, authors);

        // define os restantes parametros
        this.copies = copies;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n* Old Book *");
        sb.append("\n\tID: " + this.getId());
        sb.append("\n\tTitle: " + this.getTitle());
        for (var a : this.getAuthors())
            sb.append("\n\tAuthor: " + a);
        sb.append("\n\tNumber of copies: " + copies + "\n");
        return sb.toString();
    }
}
