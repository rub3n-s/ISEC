package pt.isec.pd.client.gui.view;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.ShowsResponse;

public class PayReservationForm {
    @FXML
    private Button payButton;
    @FXML
    private Button deleteResButton;
    @FXML
    private AnchorPane pane;
    @FXML
    private Button backToMenuButton;
    private ModelManager model;

    public void setModel(ModelManager model) {
        this.model = model;

        registerHandlers();
        update();
    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });

        model.addPropertyChangeListener(ClientAction.DELETE_UNPAID_RESERVATION.toString(), evt -> {
            model.setMessage("Pagamento cancelado com sucesso!");
            model.previous();
        });

        model.addPropertyChangeListener(ClientAction.SELECT_SHOWS.toString(), evt -> {
            if (model.getState() == State.PAY_RESERVATION) {
                ShowsResponse showsResponse = (ShowsResponse) model.getResponse();
                model.showNotification(showsResponse.getShowId());
                model.setMessage("O show foi removido pelo administrado e a sua reserva foi cancelada");
            }
        });


        model.addPropertyChangeListener(ClientAction.PAY_RESERVATION.toString(), evt -> {
            model.setMessage("Pagamento efetuado com sucesso!");
            model.previous();
        });

        backToMenuButton.setOnAction(actionEvent -> model.previous());

        payButton.setOnAction(actionEvent -> model.payReservation());

        deleteResButton.setOnAction(actionEvent -> model.deleteReservation());
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.PAY_RESERVATION);
    }
}
