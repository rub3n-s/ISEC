package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.Type;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

import java.util.HashMap;

public class ManageShows extends StateAdapter {
    public ManageShows(Context context, Client data) {
        super(context, data);
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
    public void insertShowsTransition() {
        changeState(State.MENU_ADMIN);
    }

    @Override
    public void insertShows(String filePath) {
        data.insertShows(filePath);
    }

    @Override
    public void consultShows(HashMap<String, String> filters) {
        data.consultShows(ClientAction.CONSULT_SHOWS_ALL,null);
    }

    @Override
    public void deleteShow(int idShow) {
        data.deleteShow(idShow);
    }

    @Override
    public void showVisible(int idShow) {
        data.showVisible(idShow);
    }

    @Override
    public State getState() {
        return State.MANAGE_SHOWS;
    }
}
