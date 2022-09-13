package library;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

import book.*;

public class Library {
    private ArrayList<Book> livros;
    //private HashSet<Book> livros;
    //private HashMap<Integer,Book> livros;

    private String nome;

    public Library(String name) {
        livros = new ArrayList<Book>();
        //livros = new HashSet<>();
        //livros = new HashMap<>();
        nome = name;
    }

    public String getName() {
        return nome;
    }

    public boolean addBook(String titulo, ArrayList<String> autores) {
        if (titulo != null && autores != null) {
            Book book = new Book(titulo,autores);
            livros.add(book);
            return true;
        }
        return false;

        // -----------hashSet-------------
        // if (livros.add(new Book(titulo, autores)))
        //     return true;
        // return false;

        // -----------hashMap-------------
 /*        if (titulo != null & autores != null) {
            Book book = new Book(titulo,autores);
            livros.put(book.getId(),book);
            return true;
        } 
        return false;*/
    }

    public boolean addOldBook(String title, ArrayList<String> authors, int copies) {
        if (title != null && authors != null) {
            OldBook book = new OldBook(title, authors, copies);
            livros.add(book);
            return true;
        }
        return false;
    }

    public boolean addRecentBook(String title, ArrayList<String> authors, String isbn, double price) {
        if (title != null && authors != null) {
            RecentBook book = new RecentBook(title, authors, isbn, price);
            livros.add(book);
            return true;
        }
        return false;
    }

    public Book findBook(int id) {
        System.out.println();
        // 1º Método - Pesquisa Iterativa - com Objeto
 /*        if (book != null) {
            for (int i = 0; i < livros.size(); i++) {
                if (book.equals(livros.get(i))) {
                    System.out.printf("Encontrou o livro '%s' na lista!\n",book.getTitulo());
                    return true;
                }
            }
        }
        return false; */

        //2º Método - Pesquisa Iterativa - com ID
        if (id > 0) {
            for(var l : livros) {
                if (l.getId() == id) {
                    return l;
                }
            }
        }
        return null;

        // 3º Método - IndexOf() - com ID
/*         if (id > 0) {
            int pos = livros.indexOf(livros.contains(id));
            if (pos != -1) {
                System.out.printf("Encontrou o livro '%s' na lista!\n",livros.get(pos).getTitle());
                return livros.get(pos);
            }
        }
        return null; */

        // 4º Método - Pesquisa HashMap
/*         if (id > 0) {
            for (Map.Entry<Integer,Book> entry: livros.entrySet()) {
                if (entry.getKey() == id) {
                    System.out.printf("Encontrou o livro '%s' na lista!\n",entry.getValue().getTitle());
                    return entry.getValue();
                }
            }
        }
        return null; */
    }

    public boolean removeBook(int id) {
        // 1º Método - Pesquisa Iterativa
        // HashSet/HashMap -> não utilizam indexOf()
        for (var l : livros) {
            if (l.getId() == id) {
                livros.remove(l);
                return true;
            }
        }
        return false;

/*         for (Map.Entry<Integer,Book> entry : livros.entrySet()) {
            if (entry.getKey() == id) {
                livros.remove(entry.getKey());
                return true;
            }                
        }  
        return false; */

        // 2º Método - indexOf()
        // int pos = livros.indexOf();
        // if (pos != -1) {
        //     livros.remove(livros.get(pos));
        //     return true;
        // }
        // return false;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (livros.size() > 0) {
            // ArrayList e HashSet
            // for (Book l : livros ) {
            //     sb.append("ID: " + l.getId() + "\n");
            //     sb.append("Titulo: " + l.getTitulo()+"\n");
            //     sb.append("Autores: \n");
            //     for (int i = 0; i < l.getAutores().size(); i++)
            //         sb.append("\t" + l.getAutores().get(i) + "\n");
            // }

            // HashMap
/*             for (Map.Entry<Integer,Book> entry : livros.entrySet()) {
                sb.append("ID: " + entry.getValue().getId() + "\n");
                sb.append("Title: " + entry.getValue().getTitle()+"\n");
                sb.append("Authors: \n");
                for (int i = 0; i < entry.getValue().getAuthors().size(); i++)
                    sb.append("\t" + entry.getValue().getAuthors().get(i) + "\n");
            } */

            for (var b : livros) {
                sb.append(b.toString());
            }
        }
        sb.append("\n");
        return sb.toString();
    }

    public String toStringSorted() {
        StringBuilder sb = new StringBuilder("\nSorted Books: ");
        ArrayList<Book> newList = new ArrayList<>(livros);

        // compareTo
        Collections.sort(newList);
        sb.append(newList.toString());

        // compare
        //Collections.sort(newList, new BookComparator());

        return sb.toString();
    }
}
