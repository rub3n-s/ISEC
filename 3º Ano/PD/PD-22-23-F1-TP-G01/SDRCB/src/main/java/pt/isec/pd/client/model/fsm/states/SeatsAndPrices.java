package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;
import pt.isec.pd.shared_data.Seat;

import java.util.List;

public class SeatsAndPrices extends StateAdapter {
    public SeatsAndPrices(Context context, Client data) {
        super(context, data);
    }

    @Override
    public void seatsTransition(Integer idShow) {
        changeState(State.SELECT_SHOWS);
        data.resetShow();
    }

    @Override
    public void previous() {
        changeState(State.MENU_CLIENT);
    }

    @Override
    public void disconnect() {
        super.disconnect();
    }

    @Override
    public void submitReservation(List<Seat> seats) {
         data.submitReservation(seats);
    }

    @Override
    public void payReservationTransitionToState(int resId, int showId) {
        context.changeState(new PayReservation(context,data,resId,showId));
    }

    @Override
    public State getState() {
        return State.SEATS_PRICES;
    }
}
