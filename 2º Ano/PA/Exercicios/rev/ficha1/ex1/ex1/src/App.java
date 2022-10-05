import numAleatorio.numAleatorio;

public class App {
    public static void main(String[] args) throws Exception {
        numAleatorio num = new numAleatorio();

        System.out.printf("1ª gerado [%d]\n", num.getNum());
        num.geraNovo();
        System.out.printf("2º gerado [%d]\n", num.getNum());
    }
}
