import java.util.ArrayList;
import java.util.List;

public class App {
    public static <T> void findMin(List<? super T> list) {
        Pilha<T> ordenada = new Pilha<>(list);

        List aux = new ArrayList<>();
        Pilha<T> minimos = new Pilha<>(aux);

        ordenada.peek();
        minimos.push(ordenada.peek());                
    }

    public static void main(String[] args) throws Exception {
        
    }
}
