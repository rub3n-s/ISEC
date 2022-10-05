package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.fsm.GameBWState;

public interface IGameBWState {
    public boolean bet(int nrBalls);

    GameBWState getState();
}
