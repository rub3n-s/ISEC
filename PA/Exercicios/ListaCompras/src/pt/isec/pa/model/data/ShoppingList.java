package pt.isec.pa.model.data;

import java.util.ArrayList;

// alvo das nossas ações/comandos -> funciona como receiver

public class ShoppingList {
    private ArrayList<Product> list;

    public ShoppingList() {
        list = new ArrayList<>();
    }

    public boolean addProduct(String name, double qt) {
        if (name != null && !name.isBlank() && qt > 0) {
            list.add(new Product(name, qt));
            return true;
        }
        return false;
    }

    public boolean removeProduct(String name, double qt) {
        return list.remove(new Product(name, qt));
    }

    public boolean concreteCommand() {
        return false;
    }

    public boolean undoConcreteCommand() {
        return false;
    }

    @Override
    public String toString() {
        if (list.isEmpty())
            return "\nThe shopping cart is empty!\n";

        StringBuilder sb = new StringBuilder("\nShopping List:\n");
        for (Product p : list)
            sb.append("\t- ").append(p).append("\n");
        return sb.toString();
    }
}
