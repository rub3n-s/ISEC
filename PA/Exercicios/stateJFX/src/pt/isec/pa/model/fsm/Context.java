package pt.isec.pa.model.fsm;

import pt.isec.pa.model.data.ModelData;

public class Context {
    ModelData data;
    IState state;

    public Context() {
        data = new ModelData();
        state = State.BEGIN.createState(this,data);
    }

    void changeState(IState state) {
        this.state = state;
    }

    public State getState() {
        return state.getState();
    }

    public void next() {
        state.next();
    }

    public void previous() {
        state.previous();
    }

    public void changeMessage(String msg) {
        state.changeMessage(msg);
    }

    public void changeNumber(int nr) {
        state.changeNumber(nr);
    }

    public int getNumber() {
        return data.getNumber();
    }

    public String getMessage() {
        return data.getMessage();
    }
}
