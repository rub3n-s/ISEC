package pt.isec.pd.client.model.fsm.states;

import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.Type;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;
import pt.isec.pd.client.model.data.Client;

public class EditUser extends StateAdapter {
    public EditUser(Context context, Client data) {
        super(context, data);
    }

    @Override
    public void next() {
        changeState(State.LOGIN);
    }

    @Override
    public void previous() {
        changeState(State.REGISTER);
    }

    @Override
    public void edit(ClientAction action, String edit){
        data.edit(action,edit);
    }


    @Override
    public void editTransition() {
        if (data.getType() == Type.NORMAl_MODE) {
            changeState(State.MENU_CLIENT);
        } else {
            changeState(State.MENU_ADMIN);
        }
    }

    @Override
    public State getState() {
        return State.EDIT_USER;
    }
}
