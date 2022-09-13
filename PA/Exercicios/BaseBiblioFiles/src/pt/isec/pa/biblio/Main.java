package pt.isec.pa.biblio;

import pt.isec.pa.biblio.model.library.Library;
import pt.isec.pa.biblio.ui.LibraryUI;

public class Main {
    public static void main(String[] args) {
        Library lib = new Library("DEIS-ISEC");
        LibraryUI libui = new LibraryUI(lib);
        libui.start();
    }
}