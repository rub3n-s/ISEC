package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.Type;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

public class MenuAdmin extends StateAdapter {
    public MenuAdmin(Context context, Client data) {
        super(context, data);
    }

    @Override
    public void editTransition() {
        if (data.getType() == Type.ADMIN) {
            changeState(State.EDIT_USER);
        }
    }

    @Override
    public void showsTransition() {
        if (data.getType() == Type.ADMIN) {
            changeState(State.SHOWS);
        }
    }

    @Override
    public void insertShowsTransition() {
        changeState(State.MANAGE_SHOWS);
        data.consultShows(ClientAction.CONSULT_SHOWS_ALL,null);
    }

    @Override
    public State getState() {
        return State.MENU_ADMIN;
    }
}
