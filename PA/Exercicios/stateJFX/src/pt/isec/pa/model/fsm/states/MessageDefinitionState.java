package pt.isec.pa.model.fsm.states;

import javafx.scene.layout.Pane;
import pt.isec.pa.model.ModelManager;
import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.Context;
import pt.isec.pa.model.fsm.State;
import pt.isec.pa.model.fsm.StateAdapter;

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

