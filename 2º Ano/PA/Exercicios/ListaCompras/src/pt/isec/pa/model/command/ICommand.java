package pt.isec.pa.model.command;

public interface ICommand {
    boolean execute();
    boolean undo();
}
