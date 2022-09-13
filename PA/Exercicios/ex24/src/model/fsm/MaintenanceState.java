package model.fsm;

import model.data.Elevator;

public class MaintenanceState extends ElevatorStateAdapter {
    // password to unlock maintenance mod
    String password = "pass";

    protected MaintenanceState(Elevator elevator, ElevatorContext context) {
        super(elevator,context);
    }

    @Override
    public ElevatorState getState() {
        return ElevatorState.MAINTENANCE;
    }

    @Override 
    public boolean unlock(String password) {
        if (password.equals(this.password)) {
            //changeState(new GroundFloorState(elevator, context));

            // using Factory
            changeState(ElevatorState.GROUND_FLOOR.createState(context, elevator));

            return true;
        }
        return false;
    }

    //----------- 
    //    log 
    //-----------
    @Override
    public boolean log() {
        return ModelLog.getInstance().addMessage("Elevator at: " + this.getState() + "\n");
    }

    @Override
    public boolean rmLog() {
        return ModelLog.getInstance().delMessages();
    }

    @Override
    public boolean list() {
        return ModelLog.getInstance().showMessages();
    }
}
