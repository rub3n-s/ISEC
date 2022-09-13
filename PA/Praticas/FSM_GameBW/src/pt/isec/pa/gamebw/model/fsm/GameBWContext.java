package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.data.GameBWData;

public class GameBWContext {
    IGameBWState state;
    GameBWData data;

    public GameBWContext() {
        data = new GameBWData();
        state = GameBWState.INITIAL_BET.createState(this,data);
    }

    void changeState(IGameBWState newState) {
        state = newState;
    }

    // getters
    public GameBWState getState() {
        if (state == null)
            return null;
        return state.getState();
    }

    public int getNrWhiteBallsWon() {
        return data.getNrWhiteBallsWon();
    }

    public int getNrWhiteBallsOut() {
        return data.getNrWhiteBallsOut();
    }

    public int getNrBlackBallsOut() {
        return data.getNrBlackBallsOut();
    }

    public boolean bagIsEmpty() {
        return data.bagIsEmpty();
    }

    public boolean bet(int nrBalls) {
        if (nrBalls >= 0 && nrBalls <= data.getNrWhiteBallsWon()) {

        }
        return false;
    }

    public void end() {

    }

    public void removeTwoBalls() {
    }

    public void loseWhiteBall() {

    }

    public void getRandom() {

    }
}
