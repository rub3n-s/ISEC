package pt.isec.pd.client.model.fsm;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.fsm.states.*;

public enum State {
    LOGIN, REGISTER, EDIT_USER, MENU_CLIENT,SHOWS, SELECT_SHOWS,SEATS_PRICES, MENU_ADMIN, MANAGE_SHOWS, CONSULT_PAYMENTS_AWAITING, PAY_RESERVATION, CONSULT_PAYMENTS;

    IState createState(Context context, Client data) {
        return switch (this) {
            case LOGIN -> new Login(context,data);
            case REGISTER -> new Register(context,data);
            case EDIT_USER -> new EditUser(context,data);
            case MENU_CLIENT -> new MenuClient(context,data);
            case SHOWS -> new Shows(context,data);
            case SEATS_PRICES -> new SeatsAndPrices(context,data);
            case MENU_ADMIN -> new MenuAdmin(context,data);
            case MANAGE_SHOWS -> new ManageShows(context,data);
            case SELECT_SHOWS -> new SelectShows(context,data);
            case CONSULT_PAYMENTS_AWAITING -> new ConsultPaymentsAwaiting(context,data);
            case PAY_RESERVATION -> new PayReservation(context,data);
            case CONSULT_PAYMENTS -> new ConsultPayments(context,data);
        };
    }
}
