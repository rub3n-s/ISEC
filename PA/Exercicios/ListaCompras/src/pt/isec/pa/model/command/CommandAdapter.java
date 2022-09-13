package pt.isec.pa.model.command;

import pt.isec.pa.model.data.ShoppingList;

abstract class CommandAdapter implements ICommand {
    protected ShoppingList receiver;

    protected CommandAdapter(ShoppingList receiver) {
        this.receiver = receiver;
    }
}
