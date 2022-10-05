package pt.isec.pa.ui.utils;

import pt.isec.pa.model.ShoppingListManager;

public class ShoppingListUI {
    ShoppingListManager sm;

    public ShoppingListUI(ShoppingListManager sm) {
        this.sm = sm;
    }

    public void start() {
        boolean finish = false;
        do {
            //System.out.println("\n\n" + sm + "\n");
            int op = PAInput.chooseOption("Shopping List",
                    "Add product", "Remove product", "List", "Undo", "Redo", "Quit");
            switch (op) {
                case 1 -> sm.addProduct(
                        PAInput.readString("\nProduct name: ", false),
                        PAInput.readNumber("Quantity: "));
                case 2 -> sm.removeProduct(
                        PAInput.readString("\nProduct name: ", false),
                        PAInput.readNumber("Quantity: "));
                case 3 -> sm.list();
                case 4 -> sm.undo();
                case 5 -> sm.redo();
                case 6 -> finish = true;
            }
        } while (!finish);
    }
}
