import array.*;

public class App {
    public static void main(String[] args) throws Exception {
        Array arr = new Array(10);
        arr.imprime();
        System.out.printf("Media[%.2f]\n",arr.getMedia());
        System.out.printf("Maior[%d]\n",arr.getMaior());
        System.out.printf("Menor[%d]\n",arr.getMenor());
        arr.inverter();
    }
}
