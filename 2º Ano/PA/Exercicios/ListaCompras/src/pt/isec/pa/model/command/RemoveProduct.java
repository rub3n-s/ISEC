package pt.isec.pa.model.command;

import pt.isec.pa.model.data.ShoppingList;

public class RemoveProduct extends CommandAdapter {
    private String name;
    private double quantity;

    public RemoveProduct(ShoppingList receiver, String name, double quantity) {
        super(receiver);
        this.name = name;
        this.quantity = quantity;
    }

    @Override
    public boolean execute() {
        return receiver.removeProduct(name,quantity);
    }

    @Override
    public boolean undo() {
        return receiver.addProduct(name,quantity);
    }
}
