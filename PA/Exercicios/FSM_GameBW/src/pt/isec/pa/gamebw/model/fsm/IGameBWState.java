package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.fsm.GameBWState;

public interface IGameBWState {
    // TODO: transitions
    public boolean bet();
    public boolean end();

    GameBWState getState();
}
