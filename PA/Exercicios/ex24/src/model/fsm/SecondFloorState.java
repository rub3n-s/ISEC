package model.fsm;

import java.util.Random;

import model.data.Elevator;

class SecondFloorState extends ElevatorStateAdapter {
    private final double PROB = 0.3;

    protected SecondFloorState(Elevator elevator, ElevatorContext context) {
        super(elevator, context);
        elevator.setCurrentFloor(2);
    }

    @Override
    public ElevatorState getState() {
        return ElevatorState.SECOND_FLOOR;
    }

    @Override
    public boolean down() {
        // using Factory
        changeState(ElevatorState.FIRST_FLOOR.createState(context, elevator));

        //changeState(new FirstFloorState(elevator,context));

        if (manutencao(PROB))
            // using Factory
            changeState(ElevatorState.MAINTENANCE.createState(context, elevator));

            //changeState(new MaintenanceState(elevator, context)); 

        return true;
    } 

    private boolean manutencao(double prob) {
        Random rnd = new Random();
        if (rnd.nextDouble() < prob)
            return true;
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