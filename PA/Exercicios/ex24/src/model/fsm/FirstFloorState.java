package model.fsm;

import java.util.Random;

import model.data.Elevator;

class FirstFloorState extends ElevatorStateAdapter {
    private final double PROB = 0.2;

    protected FirstFloorState(Elevator elevator, ElevatorContext context) {
        super(elevator, context);
        elevator.setCurrentFloor(1);
    }

    @Override
    public ElevatorState getState() {
        return ElevatorState.FIRST_FLOOR;
    }
    
    @Override
    public boolean up() {
        // using Factory
        changeState(ElevatorState.SECOND_FLOOR.createState(context, elevator));
        
        //changeState(new SecondFloorState(elevator,context));

        if (manutencao(PROB))
            // using Factory
            changeState(ElevatorState.MAINTENANCE.createState(context, elevator));
            
            //changeState(new MaintenanceState(elevator, context)); 

        return true;
    }    

    @Override
    public boolean down() {
        // using Factory
        changeState(ElevatorState.GROUND_FLOOR.createState(context, elevator));

        //changeState(new GroundFloorState(elevator,context));

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
