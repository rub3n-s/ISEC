package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.Type;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

import java.util.HashMap;

public class Shows extends StateAdapter {
    public Shows(Context context, Client data) {
        super(context, data);
    }
    @Override
    public void consultShows(HashMap<String,String> filters) {
        data.consultShows(ClientAction.CONSULT_SHOWS_VISIBLE,filters);
    }
    @Override
    public void showsTransition() {
        if (data.getType() == Type.ADMIN) {
            changeState(State.MENU_ADMIN);
        } else {
            changeState(State.MENU_CLIENT);
        }
    }

    @Override
    public State getState() {
        return State.SHOWS;
    }
}
