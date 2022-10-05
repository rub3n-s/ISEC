package libraryUI;

import library.*;
import book.*;
import PAInput.PAInput;

import java.util.ArrayList;
import java.util.Scanner;

public class LibraryUI {
    Library lib;
    public LibraryUI(Library lib) {
        this.lib = lib;
    }

    void addBook() {
        System.out.println();
        // começa por pedir apenas o titulo e os autores
        String title = PAInput.readString("Book title: ",false);
        String author;
        ArrayList<String> authors = new ArrayList<>();
        
        do {
            author = PAInput.readString("Name of one author [\'exit\' to finish]: ",false);
            if (author!=null && !author.equalsIgnoreCase("exit"))
                authors.add(author);
        } while (!author.equalsIgnoreCase("exit"));

        if (authors.isEmpty())
            authors.add("Author unknown");

        switch (PAInput.chooseOption("Book type: ",
                "Old book","Recent book","Cancel operation")) {
            case 1:
                System.out.println();
                
                // add old book
                int copies = PAInput.readInt("Copies: ");

                // garante que existe um minimo de copias
                if (copies < 0)
                    copies = 1;
                
                // envia os parametros para a biblioteca
                lib.addOldBook(title,authors,copies);  

                break;
            case 2:
                System.out.println();

                // add recent book
                String isbn = PAInput.readString("ISBN: ",false);
                double price = PAInput.readNumber("Price: ");
                
                // garante que o preço é maior que zero
                if (price < 0.0)
                    price = 1.0;
                    
                // envia os parametros para a biblioteca
                lib.addRecentBook(title,authors,isbn,price);

                break;
            case 3:
                return;
        }
    }

    void findBook() {
        System.out.println();
        int bookId = PAInput.readInt("ID of the book to search: ");
        Book book = lib.findBook(bookId);
        if (book == null)
            System.out.println("Book not found");
        else
            System.out.println("Book found: "+book);
    }

    void removeBook() {
        int codigo = PAInput.readInt("ID of the book to remove: ");
        boolean deleted = lib.removeBook(codigo);
        if (!deleted)
            System.out.println("Book not found");
        else
            System.out.println("Book deleted");
    }

    public void start() {
        while (true) {
            switch (PAInput.chooseOption("Library Manager - "+lib.getName(),
                    "Add new book","Search book","Remove book","Show books","Sort books",
                    "Quit")) {
                case 1:
                    addBook();
                    break;
                case 2:
                    findBook();
                    break;
                case 3:
                    removeBook();
                    break;
                case 4:
                    System.out.println(lib.toString());
                    break;
                case 5:
                    System.out.println(lib.toStringSorted());
                case 6:
                    return;
            }
        }
    }

}