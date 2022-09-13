import pascal.*;

public class App {
    public static void main(String[] args) throws Exception {
        Pascal pascal = new Pascal(7);
        pascal.imprime();
        System.out.print(pascal.toString());
    }
}
