package pt.isec.pd.client.gui.view;

import javafx.collections.FXCollections;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Reserve;
import pt.isec.pd.shared_data.Responses.ConsultPayedReservationResponse;
import pt.isec.pd.shared_data.Responses.LoginResponse;

public class ConsultPaymentsForm {
    public AnchorPane pane;
    public Button cancelButton;
    public ListView<Reserve> list;

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

        model.addPropertyChangeListener(ClientAction.CONSULT_PAYED_RESERVATIONS.toString(), evt -> {
            ConsultPayedReservationResponse reservationResponse = (ConsultPayedReservationResponse) model.getResponse();
            list.setItems(FXCollections.observableList(reservationResponse.getReserves()));
        });

        cancelButton.setOnAction(actionEvent -> {
            model.consultsPaymentsTransition();
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.CONSULT_PAYMENTS);
    }
}
