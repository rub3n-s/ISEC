package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

public class ConsultPaymentsAwaiting extends StateAdapter {
    public ConsultPaymentsAwaiting(Context context, Client data) {
        super(context, data);
    }

    @Override
    public void consultsPaymentsAwaitingTransition() {
        changeState(State.MENU_CLIENT);
    }

    @Override
    public void consultsPaymentsAwaiting() {
         data.consultsPaymentsAwaiting();
    }

    @Override
    public void payReservationTransition(int resId) { data.payReservation(resId); }

    @Override
    public void deleteReservationAwaiting(int resId) { data.deleteReservation(resId); }

    @Override
    public State getState() {
        return State.CONSULT_PAYMENTS_AWAITING;
    }
}
