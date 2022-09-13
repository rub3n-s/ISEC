package pt.isec.pa.gui;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import pt.isec.pa.model.ModelManager;
import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.State;

public class MessageDefinitionUI extends BorderPane {
    ModelManager model;
    Button btnNext,btnPrevious;
    TextField tfMsg;

    public MessageDefinitionUI(ModelManager model) {
        this.model = model;
        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        this.setStyle("-fx-background-color: #A0FF80;");

        btnNext = new Button("Next");
        btnPrevious = new Button("Previous");
        HBox hbox = new HBox(btnPrevious,btnNext);
        hbox.setSpacing(10);
        hbox.setAlignment(Pos.CENTER);
        tfMsg   = new TextField();
        tfMsg.setMaxWidth(200);
        VBox vbox = new VBox(tfMsg,hbox);
        vbox.setSpacing(20);
        vbox.setAlignment(Pos.CENTER);
        this.setCenter(vbox);

    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });
        btnNext.setOnAction(actionEvent -> {
            model.next();
        });
        btnPrevious.setOnAction(actionEvent -> {
            model.previous();
        });
        tfMsg.setOnKeyTyped(keyEvent -> { model.changeMessage(tfMsg.getText());});

    }

    private void update() {
        this.setVisible(model != null && model.getState() == State.MESSAGE_DEFINITION);
        tfMsg.setText(model.getMessage());
        tfMsg.requestFocus();
    }
}

