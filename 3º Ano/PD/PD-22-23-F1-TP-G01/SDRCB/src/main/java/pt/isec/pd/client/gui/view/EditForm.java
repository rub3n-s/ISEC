package pt.isec.pd.client.gui.view;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.util.Pair;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.EditResponse;

public class EditForm {
    public AnchorPane pane;
    public ChoiceBox choiceBox;
    public Button editButton;
    public TextField editField;
    public Button cancelButton;

    private ModelManager model;

    public void setModel(ModelManager model) {
        this.model = model;

        registerHandlers();
        update();
    }
    private void registerHandlers() {
        choiceBox.getSelectionModel().select(0);

        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });

        model.addPropertyChangeListener(ClientAction.EDIT_DATA.toString(), evt -> {
           EditResponse editResponse = (EditResponse) model.getResponse();
           model.setMessage(editResponse.getMsg());
        });


        editButton.setOnAction(actionEvent -> {
            switch ((String) choiceBox.getSelectionModel().getSelectedItem()) {
                case "Username" -> model.edit(ClientAction.EDIT_USERNAME,editField.getText());
                case "Name" -> model.edit(ClientAction.EDIT_NAME,editField.getText());
                case "Password" -> model.edit(ClientAction.EDIT_PASSWORD,editField.getText());
            }
        });

        cancelButton.setOnAction(actionEvent -> {
            model.editTransition();
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.EDIT_USER);
    }
}
