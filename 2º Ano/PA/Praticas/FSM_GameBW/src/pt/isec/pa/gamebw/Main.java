package pt.isec.pa.gamebw;

import pt.isec.pa.gamebw.model.fsm.GameBWContext;
import pt.isec.pa.gamebw.ui.GameBWUI;

public class Main {
    public static void main(String[] args) {
        GameBWContext fsm = new GameBWContext();
        GameBWUI ui = new GameBWUI(fsm);
        ui.start();
    }
}
