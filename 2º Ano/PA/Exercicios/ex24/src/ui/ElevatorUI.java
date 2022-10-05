package ui;

import utils.PAInput;

import model.fsm.*;

public class ElevatorUI {
    private boolean finish;
    private ElevatorContext fsm;
    
    public ElevatorUI(ElevatorContext fsm ) {
        this.fsm = fsm; 
    }

    public void start() {
        /*int op;
        do { 
            System.out.println("Elevator current floor: ");
            op = PAInput.chooseOption("Elevator", "1 - Up", "2 - Down");
            switch(op) {
                case 1 -> fsm.up();
                case 2 -> fsm.down();
            }
        } while(op >= 0 && op < 3); */

        while(!finish) {
            switch(fsm.getState()) {
                case GROUND_FLOOR -> groundFloorUI();
                case FIRST_FLOOR -> firstFloorUI();
                case SECOND_FLOOR -> secondFloorUI();
                case MAINTENANCE -> maintenanceUI();
                default -> throw new IllegalArgumentException("Unexpected value: " + fsm.getState());
            }
        }
    }

    public void groundFloorUI() {
        System.out.println("\n__________________");
        System.out.println("\nGround Floor");
        switch(PAInput.chooseOption("Elevator", "Up","Add log","Del log","List log")) {
            case 1 -> fsm.up();
            case 2 -> fsm.log();
            case 3 -> fsm.rmLog();
            case 4 -> fsm.list();
            default -> finish = true;
        }
    }

    public void firstFloorUI() {
        System.out.println("\n__________________");
        System.out.println("\n1st Floor");
        switch(PAInput.chooseOption("Elevator", "Up", "Down")) {
            case 1 -> fsm.up();
            case 2 -> fsm.down();
            default -> finish = true;
        }
    }

    public void secondFloorUI() {
        System.out.println("\n__________________");
        System.out.println("\n2nd Floor");
        switch(PAInput.chooseOption("Elevator", "Down")) {
            case 1 -> fsm.down();
            default -> finish = true;
        }
    }

    public void maintenanceUI() {
        String password;
        boolean flg = false;
        do {
            System.out.println("\n__________________");
            password = PAInput.readString("\n - MAINTENANCE - \nInsert password: ", true);
            if (!fsm.unlock(password))
                System.out.println("Wrong password!");
            else
                flg = true;
        } while(!flg);
    }
}
