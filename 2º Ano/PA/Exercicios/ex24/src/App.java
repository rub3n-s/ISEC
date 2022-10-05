import model.fsm.*;
import ui.ElevatorUI;

public class App {
    public static void main(String[] args) throws Exception {
        ElevatorContext fsm = new ElevatorContext();
        ElevatorUI ui = new ElevatorUI(fsm);
        ui.start();
    }
}