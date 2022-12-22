package pt.isec.pd.client.model.data;

public enum ClientAction {
    REGISTER,                       // done
    LOGIN,                          // done
    EDIT_DATA,                      // done
    EDIT_NAME,                      // done
    EDIT_USERNAME,                  // done
    EDIT_PASSWORD,                  // done
    CONSULT_PAYMENTS_AWAITING,      // done
    CONSULT_PAYED_RESERVATIONS,     // done
    CONSULT_SHOWS_VISIBLE,                  // done
    CONSULT_SHOWS_ALL,
    SELECT_SHOWS,                   // done
    VIEW_SEATS_PRICES,              // done
    SUBMIT_RESERVATION,             // done
    DELETE_UNPAID_RESERVATION,      // done
    PAY_RESERVATION,                // done
    INSERT_SHOWS,
    DELETE_SHOW,                    // done
    DISCONNECTED,                   // done
    VISIBLE_SHOW
}
