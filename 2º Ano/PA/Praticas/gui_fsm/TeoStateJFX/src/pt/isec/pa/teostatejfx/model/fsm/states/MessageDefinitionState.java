package pt.isec.pa.teostatejfx.model.fsm.states;

import javafx.scene.layout.Pane;
import pt.isec.pa.teostatejfx.model.ModelManager;
import pt.isec.pa.teostatejfx.model.data.ModelData;
import pt.isec.pa.teostatejfx.model.fsm.Context;
import pt.isec.pa.teostatejfx.model.fsm.State;
import pt.isec.pa.teostatejfx.model.fsm.StateAdapter;

public class MessageDefinitionState extends StateAdapter {
    public MessageDefinitionState(Context context, ModelData data) {
        super(context,data);
    }

    @Override
    public void next() {
        changeState(State.NUMBER_DEFINITION);
    }

    @Override
    public void previous() {
        changeState(State.BEGIN);
    }

    @Override
    public void changeMessage(String msg) {
        data.setMessage(msg);
    }

    @Override
    public State getState() {
        return State.MESSAGE_DEFINITION;
    }
}

