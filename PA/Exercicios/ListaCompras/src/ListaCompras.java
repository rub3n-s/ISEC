import pt.isec.pa.model.ShoppingListManager;
import pt.isec.pa.ui.utils.ShoppingListUI;

public class ListaCompras {
    public static void main(String[] args) throws Exception {
        ShoppingListManager sm = new ShoppingListManager();
        ShoppingListUI ui = new ShoppingListUI(sm);
        ui.start();
    }
}
