package pt.isec.pa.model;

import pt.isec.pa.model.command.CommandManager;
import pt.isec.pa.model.command.RemoveProduct;
import pt.isec.pa.model.command.AddProduct;
import pt.isec.pa.model.data.ShoppingList;

// vai ser a facade

public class ShoppingListManager {
    ShoppingList rc;
    CommandManager cm;

    public ShoppingListManager() {
        rc = new ShoppingList();
        cm = new CommandManager();
    }

    // addProduct/removeProduct
    public boolean addProduct(String name, double quantity) {
        return cm.invokeCommand(new AddProduct(rc,name,quantity));
    }

    public boolean removeProduct(String name, double quantity) {
        return cm.invokeCommand(new RemoveProduct(rc,name,quantity));
    }

    // undo/redo
    public boolean hasUndo() {
        return cm.hasUndo();
    }

    public boolean undo() {
        return cm.undo();
    }

    public boolean hasRedo() {
        return cm.hasRedo();
    }

    public boolean redo() {
        return cm.redo();
    }

    // outputs shopping list
    public void list() {
        System.out.print(rc.toString());
    }
}
