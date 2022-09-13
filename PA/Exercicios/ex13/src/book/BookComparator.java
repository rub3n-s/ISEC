package book;

import java.util.Comparator;

public class BookComparator implements Comparator<Book> {
    public BookComparator() {}

    @Override
    public int compare(Book b1, Book b2) {
        return b1.getTitle().compareTo(b2.getTitle());
    }
}
