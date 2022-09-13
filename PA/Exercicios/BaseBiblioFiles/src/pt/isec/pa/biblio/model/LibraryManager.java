package pt.isec.pa.biblio.model;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import pt.isec.pa.biblio.model.books.Book;
import pt.isec.pa.biblio.model.books.OldBook;
import pt.isec.pa.biblio.model.books.RecentBook;
import pt.isec.pa.biblio.model.library.Library;

public class LibraryManager {
    private Library library;

    public LibraryManager(String name) {    // como é um Proxy, apenas precisamos do nome para instanciar o objeto
        library = new Library(name);
    }

    // metodos para o Proxy -> redirecionar

    public String getName() {
        return library.getName();
    }

    public void setName(String name) {
        library.setName(name);
    }

    public int addBook(Book book) {
        return library.addBook(book);
    }

    public boolean removeBook(int id) {
        return library.removeBook(id);
    }

    public Book findBook(int id) {
        return library.findBook(id);
    }

    public String toString() {
        return library.toString();
    }

    public String toStringOtherOrder() {
        return library.toStringOtherOrder();
    }


    // Decorator
    public void exportToTextFile(String filename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        bw.write(library.toString());
        bw.close();
    }

    public boolean addBookFromFile(String filename) throws IOException { 
        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            Scanner sc = new Scanner(System.in);    // cada vez que faz nextLine() parte a string com \n
            
            String type;
            String title;
            String authors;
            List<String> authorsList = new ArrayList<>();
            
            int copies = 0; // OldBook

            String isbn;    // RecentBook
            double cost = 0.0;

            while(br.readLine() != null) {
                // parametros em comum dos livros
                type = br.readLine();
                title = sc.nextLine();
                authors = sc.nextLine();

                // separa os autores, caso haja, por ':' e insere na lista
                String []authorsArr = authors.split(":");
                for (int i = 0; i < authorsArr.length; i++)
                    authorsList.add(authorsArr[i]);

                // verifica qual o tipo de livro para pedir os restantes parametros
                switch(type) {
                    case "Old":
                        copies = sc.nextInt();
                        OldBook ob = new OldBook(title, authorsList, copies);
                        library.addBook(ob);
                        break;
                    case "Recent":
                        isbn = sc.nextLine();
                        cost = sc.nextDouble();
                        RecentBook rb = new RecentBook(title, authorsList, isbn, cost);
                        library.addBook(rb);
                        break;
                }
            }

            br.close();
            return true;
        } catch(IOException e) {
            e.printStackTrace();
        }

        return false; 
    }

    public boolean load() { 
        // garantir que a biblioteca e o livro
        // implementar interface serializable
        // para serializar -> FileOutputStreamer
        return false; 
    }

    public boolean save() { 
        return false; 
    }
}
