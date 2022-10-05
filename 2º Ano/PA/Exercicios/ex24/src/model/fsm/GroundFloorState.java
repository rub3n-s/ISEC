package model.fsm;

import model.data.Elevator;
import java.util.Random;

class GroundFloorState extends ElevatorStateAdapter {
    private final double PROB = 0.1;

    protected GroundFloorState(Elevator elevator, ElevatorContext context) {
        super(elevator,context);
        elevator.setCurrentFloor(0);
    }

    @Override
    public boolean up() {
        // using Factory
        changeState(ElevatorState.FIRST_FLOOR.createState(context, elevator));

        //changeState(new FirstFloorState(elevator,context));
        
        //implementar condição de random aqui
        if (manutencao(PROB)) {
            // using Factory
            changeState(ElevatorState.MAINTENANCE.createState(context, elevator));

            //changeState(new MaintenanceFloorState(elevator,context));
        }
        return true;
    }

    private boolean manutencao(double prob) {
        Random rnd = new Random();
        if (rnd.nextDouble() < prob)
            return true;
        return false;
    }

    @Override
    public ElevatorState getState() {
        return ElevatorState.GROUND_FLOOR;
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
