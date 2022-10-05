import triangulo.*;

public class App {
    public static void main(String[] args) throws Exception {
        Triangulo tr = new Triangulo(7);

        tr.preenche();
        //tr.imprime();
        System.out.print(tr.toString());
    }
}
