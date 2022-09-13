package pt.isec.pa.model.fsm.states;

import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.Context;
import pt.isec.pa.model.fsm.State;
import pt.isec.pa.model.fsm.StateAdapter;

public class NumberDefinitionState extends StateAdapter {
    public NumberDefinitionState(Context context, ModelData data) {
        super(context, data);
    }

    @Override
    public void next() {
        changeState(State.SHOW_DATA);
    }

    @Override
    public void previous() {
        changeState(State.MESSAGE_DEFINITION);
    }

    @Override
    public void changeNumber(int nr) {
        data.setNumber(nr);
    }

    @Override
    public State getState() {
        return State.NUMBER_DEFINITION;
    }
}
