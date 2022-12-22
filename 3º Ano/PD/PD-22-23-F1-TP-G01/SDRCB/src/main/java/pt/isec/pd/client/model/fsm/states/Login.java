package pt.isec.pd.client.model.fsm.states;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.Type;
import pt.isec.pd.client.model.fsm.Context;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.StateAdapter;
import pt.isec.pd.client.model.data.Client;

public class Login extends StateAdapter {
    public Login(Context context, Client data) {
        super(context,data);
    }

    @Override
    public void next() {
        if (data.getType() == Type.NORMAl_MODE) {
            changeState(State.MENU_CLIENT);
        } else {
            changeState(State.MENU_ADMIN);
        }
    }

    @Override
    public void login(String userName, String password) {
        data.login(userName,password);
    }

    @Override
    public State getState() {
        return State.LOGIN;
    }

    @Override
    public void registerTransition() {
        changeState(State.REGISTER);
    }
}
