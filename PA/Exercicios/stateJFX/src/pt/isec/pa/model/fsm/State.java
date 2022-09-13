package pt.isec.pa.model.fsm;

import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.states.BeginState;
import pt.isec.pa.model.fsm.states.MessageDefinitionState;
import pt.isec.pa.model.fsm.states.NumberDefinitionState;
import pt.isec.pa.model.fsm.states.ShowDataState;

public enum State {
    BEGIN, MESSAGE_DEFINITION, NUMBER_DEFINITION, SHOW_DATA;

    IState createState(Context context, ModelData data) {
        return switch (this) {
            case BEGIN -> new BeginState(context,data);
            case MESSAGE_DEFINITION -> new MessageDefinitionState(context,data);
            case NUMBER_DEFINITION -> new NumberDefinitionState(context,data);
            case SHOW_DATA -> new ShowDataState(context,data);
        };
    }
}
