package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;

public class ConsultPayments extends StateAdapter {
    public ConsultPayments(Context context, Client data) {
        super(context, data);
    }

    @Override
    public State getState() {
        return State.CONSULT_PAYMENTS;
    }

    @Override
    public void consultsPaymentsTransition() { changeState(State.MENU_CLIENT); }

    @Override
    public void consultsPayments() {
        data.consultsPayments();
    }
}
