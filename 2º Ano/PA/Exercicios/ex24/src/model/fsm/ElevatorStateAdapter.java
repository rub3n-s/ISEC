package model.fsm;
import model.data.*;

abstract class ElevatorStateAdapter implements IElevatorState {
    protected Elevator elevator;
    protected ElevatorContext context;

    protected ElevatorStateAdapter(Elevator elevator, ElevatorContext context) {
        this.elevator = elevator;
        this.context = context;
    }

    protected void changeState(IElevatorState newState) {
        context.changeState(newState);
    }

    @Override
    public boolean up() {
        return false;
    }

    @Override
    public boolean down() {
        return false;
    }

    @Override
    public boolean unlock(String password) {
        return false;
    }
}