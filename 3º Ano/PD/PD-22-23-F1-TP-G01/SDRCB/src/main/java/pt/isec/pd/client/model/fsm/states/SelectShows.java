package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

import java.util.HashMap;

public class SelectShows extends StateAdapter {
    public SelectShows(Context context, Client data) {
        super(context,data);
    }

    @Override
    public void consultShows(HashMap<String, String> filters) {
        data.consultShows(ClientAction.SELECT_SHOWS,null);
    }

    @Override
    public void seatsTransition(Integer idShow) {
        changeState(State.SEATS_PRICES);
        data.viewSeatsAndPrices(idShow);
    }

    @Override
    public void selectShowsTransition() {
        changeState(State.MENU_CLIENT);
    }

    @Override
    public State getState() {
        return State.SELECT_SHOWS;
    }
}
