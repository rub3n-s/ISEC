package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.data.GameBWData;

public class InitialBetState extends GameBWStateAdapter {
    protected InitialBetState(GameBWContext context, GameBWData data) {
        super(context,data);
    }

    @Override
    public GameBWState getState() {
        return GameBWState.INITIAL_BET;
    }

    @Override
    public boolean bet(int nrBalls) {
        return false;
    }
}
