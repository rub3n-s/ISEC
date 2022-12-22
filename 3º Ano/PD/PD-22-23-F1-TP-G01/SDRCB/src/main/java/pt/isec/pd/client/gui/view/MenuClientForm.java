package pt.isec.pd.client.gui.view;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.util.Pair;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.fsm.State;

public class MenuClientForm {
    public AnchorPane pane;
    public Button editButton;
    public Button showsButton;
    public Button selectShowsButton;
    public Button unpaidReservesButton;
    public Button paidReservesButton;
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

        editButton.setOnAction(actionEvent -> {
            model.editTransition();
        });

        showsButton.setOnAction(actionEvent -> {
            model.showsTransition();
        });

        unpaidReservesButton.setOnAction(actionEvent -> {
            model.consultsPaymentsAwaitingTransition();
        });

        paidReservesButton.setOnAction(actionEvent -> {
            model.consultsPaymentsTransition();
        });

        selectShowsButton.setOnAction(actionEvent -> model.selectShowsTransition());
    }
    private void update() {
        pane.setVisible(model != null && model.getState() == State.MENU_CLIENT);
    }
}
