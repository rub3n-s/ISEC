import inventario.Inventario;

public class App {
    public static void main(String[] args) throws Exception {
        Inventario t = new Inventario();
        t.addProduto("Coca", 1234, 1); //nome, código, preço
        t.addProduto("Cola", 1235, 2);
        t.addProduto("Chipi", 1236, 3);
        System.out.println(t.getPreco(1235)); //2
        System.out.println(t.getPreco("Coca")); //1
        System.out.println(t.getCodigo("Chipi")); //1236
        //System.out.println(t.getNomes()); //mostra todos os nomes:
        //A ORDEM NÃO É RELEVANTE!!!!
    }
}
