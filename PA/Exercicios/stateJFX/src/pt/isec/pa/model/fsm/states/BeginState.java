package pt.isec.pa.model.fsm.states;

import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.Context;
import pt.isec.pa.model.fsm.State;
import pt.isec.pa.model.fsm.StateAdapter;

public class BeginState extends StateAdapter {
    public BeginState(Context context, ModelData data) {
        super(context,data);
    }

    @Override
    public void next() {
        changeState(State.MESSAGE_DEFINITION);
    }

    @Override
    public State getState() {
        return State.BEGIN;
    }
}
