package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.data.GameBWData;

public class WaitBetState extends GameBWStateAdapter {
    protected WaitBetState(GameBWContext context, GameBWData data) {
        super(context,data);
    }

    @Override
    public boolean bet(int nrBalls) {
        return false;
    }

    @Override
    public GameBWState getState() {
        return GameBWState.WAIT_BET;
    }
}
