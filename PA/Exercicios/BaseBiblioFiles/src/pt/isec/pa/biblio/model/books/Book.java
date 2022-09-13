package pt.isec.pa.biblio.model.books;

import java.util.List;

public class Book implements Comparable<Book>,Cloneable {
    private static int countID = 0;

    private static int getNewID() {
        return ++countID;
    }

    protected int id;
    protected String title;
    protected List<String> authors;

    private Book(int id) {
        this.id = id;
        this.title = null;
        this.authors = null;
    }

    public static Book getDummyBook(int id) {
        return new Book(id);
    }

    protected Book(String title, List<String> authors) {
        id = getNewID();
        this.title = title;
        this.authors = List.copyOf(authors);
    }

    @Override
    public Object clone() {
        try {
            Book newBook = (Book) super.clone();
            newBook.authors = List.copyOf(this.authors); // authors is already immutable, but...
            return newBook;
        } catch (CloneNotSupportedException e) {
            return null;
        }
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public List<String> getAuthors() {
        return authors;
    }

    public void setAuthors(List<String> authors) {
        this.authors = List.copyOf(authors);
    }

    @Override
    public String toString() {
        if (title==null)
            return "DummyBook ["+id+']';
        if (authors==null || authors.size()==0)
            return id +",'" + title + "'";
        String strAuthors = authors.toString();
        return id +",'" + title + "', " + strAuthors.substring(1,strAuthors.length()-1);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        //if (o == null || getClass() != o.getClass()) return false;
        if ( o instanceof Book book )
            return id == book.id;
        return false;
    }

    @Override
    public int hashCode() {
        return id;
    }

    @Override
    public int compareTo(Book o) {
        return id - o.id;
        //return title.compareTo(o.title);
    }
}

