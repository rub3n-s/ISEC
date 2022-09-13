package model.fsm;

public interface IElevatorState {
    // moves elevator up or down
    boolean up();
    boolean down();

    // locks maintenance mod
    boolean unlock(String password);
    
    // return elevator actual state
    ElevatorState getState();

    // adds elevator state to log
    boolean log();

    // removes all content from log
    boolean rmLog();

    // list log content
    boolean list();
}
