package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

public class PayReservation extends StateAdapter {
    private int resId;
    private int showId;

    public PayReservation(Context context, Client data) {
        super(context, data);
    }

    public PayReservation(Context context, Client data, int resId, int showId) {
        super(context, data);
        this.resId = resId;
        this.showId = showId;
    }

    @Override
    public void payReservationTransition(int resId) {
        changeState(State.MENU_CLIENT);
    }

    @Override
    public void payReservation() { data.payReservation(resId); }

    @Override
    public void deleteReservation() { data.deleteReservation(resId); }

    @Override
    public void next() {
        changeState(State.CONSULT_PAYMENTS);
        data.consultsPayments();
    }

    @Override
    public void previous() {
        changeState(State.MENU_CLIENT);
    }

    @Override
    public void showNotification(int showId) {
        if (showId == this.showId){
            changeState(State.MENU_CLIENT);
        }
    }

    @Override
    public State getState() {
        return State.PAY_RESERVATION;
    }
}
