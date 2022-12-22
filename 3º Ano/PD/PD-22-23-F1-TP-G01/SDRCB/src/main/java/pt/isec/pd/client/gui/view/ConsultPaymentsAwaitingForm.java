package pt.isec.pd.client.gui.view;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.client.model.fsm.states.PayReservation;
import pt.isec.pd.shared_data.Reserve;
import pt.isec.pd.shared_data.Responses.ConsultUnpayedReservationResponse;
import pt.isec.pd.shared_data.Responses.DeleteReservationResponse;
import pt.isec.pd.shared_data.Responses.PayReservationResponse;
import pt.isec.pd.shared_data.Seat;

import java.util.ArrayList;
import java.util.List;

public class ConsultPaymentsAwaitingForm {
    @FXML
    private AnchorPane pane;
    @FXML
    private  ListView<Reserve> list;
    @FXML
    private Button cancelButton;
    @FXML
    private Button payButton;
    @FXML
    private Button deleteResButton;
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

        model.addPropertyChangeListener(ClientAction.PAY_RESERVATION.toString(), evt -> {
            model.consultsPaymentsAwaiting();
        });

        model.addPropertyChangeListener(ClientAction.CONSULT_PAYMENTS_AWAITING.toString(), evt -> {
            updateList();
        });

        cancelButton.setOnAction(actionEvent -> {
            model.consultsPaymentsAwaitingTransition();
        });

        payButton.setOnAction(actionEvent -> {
            Reserve res = list.getSelectionModel().getSelectedItem();
            if (res != null)
                model.payReservationTransition(res.getId());
        });

        deleteResButton.setOnAction(actionEvent -> {
            Reserve res = list.getSelectionModel().getSelectedItem();
            if (res != null)
                model.deleteReservationAwaiting(res.getId());
        });
    }


    private void update() {
        pane.setVisible(model != null && model.getState() == State.CONSULT_PAYMENTS_AWAITING);
    }

    private void updateList() {
        ConsultUnpayedReservationResponse response = (ConsultUnpayedReservationResponse) model.getResponse();
        if (response != null) {
            list.getItems().clear();
            list.setItems(FXCollections.observableList(response.getReserves()));
        }
    }
}
