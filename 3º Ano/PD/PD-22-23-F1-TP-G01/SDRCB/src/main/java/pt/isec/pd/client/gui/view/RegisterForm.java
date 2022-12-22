package pt.isec.pd.client.gui.view;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.RegisterResponse;

public class RegisterForm {
    public AnchorPane pane;
    public PasswordField passwordField;
    public TextField nameField;
    public TextField userNameField;
    public Button loginButton;
    public Button registerButton;
    private ModelManager model;

    public void setModel(ModelManager model) {
        this.model = model;

        registerHandlers();
        update();
        clearView();
    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });

        //Request
        registerButton.setOnAction(actionEvent -> {
            model.setMessage("");
            if (userNameField.getText().isEmpty()) {
                userNameField.setStyle("-fx-background-color: #FF2400;");
                return;
            } else {
                userNameField.setStyle("");
            }
            if (nameField.getText().isEmpty()) {
                nameField.setStyle("-fx-background-color: #FF2400;");
                return;
            } else {
                nameField.setStyle("");
            }
            if (passwordField.getText().isEmpty()) {
                passwordField.setStyle("-fx-background-color: #FF2400;");
                return;
            } else {
                passwordField.setStyle("");
            }
            if (userNameField.getText().equals(nameField.getText())) {
                model.setMessage("O username e nome devem ser diferentes");
                return;
            }

            model.register(userNameField.getText(),nameField.getText(),passwordField.getText());
        });

        // Response
        model.addPropertyChangeListener(ClientAction.REGISTER.toString(), evt -> {
            RegisterResponse registerResponse = (RegisterResponse) model.getResponse();

            model.setMessage(registerResponse.getMsg());
            if (registerResponse.isSuccess()) {
                model.swapToRegister();
                model.setMessage(registerResponse.getMsg());
            }
        });

        loginButton.setOnAction(actionEvent -> {
            clearView();
            model.swapToRegister();
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.REGISTER);
    }

    private void clearView() {
        passwordField.clear();
        nameField.clear();
        userNameField.clear();
        userNameField.setStyle("");
        nameField.setStyle("");
        passwordField.setStyle("");
    }
}
