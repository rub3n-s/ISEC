package model.fsm;

import model.data.Elevator;

public class ElevatorContext {
    protected Elevator elevator;
    private IElevatorState state;
    
    public ElevatorContext() {
        elevator = new Elevator(0);
        state = new GroundFloorState(elevator, this);
    }

    public ElevatorState getState() {
        return state.getState();
    }

    void changeState(IElevatorState newState) {
        state = newState;
    }

    public boolean up() {
        return state.up();
    }

    public boolean down() {
        return state.down();
    }

    public int getCurrentFloor() {
        return elevator.getCurrentFloor();
    }

    public boolean unlock(String password) {
        return state.unlock(password);
    }


    // ------ log -------
    public boolean log() {
        return ModelLog.getInstance().addMessage("Elevator at: " + state.getState());
    }

    public boolean rmLog() {
        return ModelLog.getInstance().delMessages();
    }

    public boolean list() {
        return ModelLog.getInstance().showMessages();
    }
}
