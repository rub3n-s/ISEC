package pt.isec.pa.biblio.model.library;

import pt.isec.pa.biblio.model.books.Book;
import pt.isec.pa.biblio.model.books.BookComparator;

import java.util.*;

public class Library {
    Set<Book> books;
    String name;

    public Library(String name) {
        this.name=name;
        books = new HashSet<>();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int addBook(Book book) {
        if (book==null)
            return -1;

        Book newBook = (Book) book.clone();
        if (!books.add(newBook))
            return -1;

        return book.getId();
    }

    public Book findBook(int id) {
        if (books ==null || books.size()==0)
            return null;
        for(Book book : books)
            if (id == book.getId())
                return (Book) book.clone();
        return null;
    }

    public Book findBook2(int id) {
        if (books ==null || books.size()==0)
            return null;
        Iterator<Book> it = books.iterator();
        while (it.hasNext()) {
            Book book = it.next();
            if (id == book.getId())
                return (Book) book.clone();
        }
        return null;
    }

    public boolean removeBook(int id) {
        if (books == null)
            return false;
        return books.remove(Book.getDummyBook(id));
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("Library: "+name);
        sb.append("\nBooks:\n");
        if (books ==null || books.size()==0)
            sb.append("The library is empty");
        else
            for(Book book : books)
                sb.append(String.format("- %s\n",book.toString()));
        return sb.toString();
    }

    public String toStringOtherOrder() {
        StringBuilder sb = new StringBuilder("Library: "+name);
        sb.append("\nBooks:\n");
        if (books ==null || books.size()==0)
            sb.append("The library is empty");
        else {
            List<Book> orderSet = new ArrayList<>(books);
            Collections.sort(orderSet,new BookComparator());
            for (Book book : orderSet)
                sb.append(String.format("- %s\n", book.toString()));
        }

        return sb.toString();
    }
}
