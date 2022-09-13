package book;

import java.util.ArrayList;

public class Book implements Comparable<Book> {
    private static int cont = 1;
    private int id;
    private String title;
    private ArrayList<String> authors;

    private Book(int i) {
        id = i;
    }

    public Book(String title, ArrayList<String> authors) {
        id = cont;
        this.title = title;
        this.authors = authors;
        System.out.println("\nO livro foi criado com sucesso!");
        cont++;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public ArrayList<String> getAuthors() {
        return authors;
    }

    public boolean setTitulo(String title) {
        if (title != null) {
            this.title = title;
            return true;
        }
        return false;
    }

    public boolean setAutor(String authors) {
        if (authors != null) {
            this.authors.add(authors);
            return true;
        }
        return false;
    }

   @Override
   public String toString() {
       StringBuilder sb = new StringBuilder("\nBook Data: \n");
       sb.append("\tTitle: " + title);
       for (var a : authors)
           sb.append("\n\tAuthor: " + a);
       sb.append("\n");
       return sb.toString();
   } 

  @Override
  public boolean equals(Object other) {
    if (this != null && other != null
      && this.getClass() == other.getClass()) {
        return true;
    }
    return false;
  }

  @Override
  public int hashCode() {
      return this.hashCode();
  }

  public static Book getDummyBook(int id) {
    Book book = new Book(id);
    return book;
  }

  @Override
  public int compareTo(Book book) {
      // == 0, iguais
      // < 0, this é menor
      // > 0, this é maior
      return this.id - book.id; 
  }
}
