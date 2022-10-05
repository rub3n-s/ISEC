package model.fsm;

import model.data.Elevator;

public enum ElevatorState {
    GROUND_FLOOR, 
    FIRST_FLOOR,
    SECOND_FLOOR,
    MAINTENANCE;


    // Factory - instance method
    IElevatorState createState(ElevatorContext context, Elevator elevator) {
        return switch(this) {
            case GROUND_FLOOR -> new GroundFloorState(elevator,context);
            case FIRST_FLOOR -> new FirstFloorState(elevator,context);
            case SECOND_FLOOR -> new SecondFloorState(elevator,context);
            case MAINTENANCE -> new MaintenanceState(elevator,context);
        };
    }
}
