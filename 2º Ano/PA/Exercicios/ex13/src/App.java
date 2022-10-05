import library.*;
import libraryUI.*;

public class App {
    public static void main(String[] args) throws Exception {
        Library lib = new Library("DEIS-ISEC_ArrayList");
        LibraryUI libui = new LibraryUI(lib);
        libui.start();
    }
}
