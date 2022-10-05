package pt.isec.pa.teostatejfx.model.fsm.states;

import pt.isec.pa.teostatejfx.model.data.ModelData;
import pt.isec.pa.teostatejfx.model.fsm.Context;
import pt.isec.pa.teostatejfx.model.fsm.State;
import pt.isec.pa.teostatejfx.model.fsm.StateAdapter;

public class ShowDataState extends StateAdapter {
    public ShowDataState(Context context, ModelData data) {
        super(context, data);
    }

    @Override
    public void previous() {
        changeState(State.NUMBER_DEFINITION);
    }

    @Override
    public State getState() {
        return State.SHOW_DATA;
    }
}
