package pt.isec.pa.model.fsm;

public interface IState {
    void changeMessage(String msg);
    void changeNumber(int nr);
    void next();
    void previous();

    State getState();
}
