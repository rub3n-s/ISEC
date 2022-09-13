package pt.isec.pa.teostatejfx.ui.gui;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import pt.isec.pa.teostatejfx.model.ModelManager;
import pt.isec.pa.teostatejfx.model.data.ModelData;
import pt.isec.pa.teostatejfx.model.fsm.State;

public class NumberDefinitionUI extends BorderPane {
    ModelManager model;
    Button btnNext,btnPrevious;
    TextField tfNumber;


    public NumberDefinitionUI(ModelManager model) {
        this.model = model;
        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        this.setStyle("-fx-background-color: #A080FF;");

        btnNext = new Button("Next");
        btnPrevious = new Button("Previous");
        HBox hbox = new HBox(btnPrevious,btnNext);
        hbox.setSpacing(10);
        hbox.setAlignment(Pos.CENTER);
        tfNumber = new TextField();
        tfNumber.setMaxWidth(200);
        VBox vbox = new VBox(tfNumber,hbox);
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
        tfNumber.setOnKeyTyped(keyEvent -> {
            try {
                model.changeNumber(Integer.parseInt(tfNumber.getText()));
            } catch (Exception e) {
                model.changeNumber(-1);
            }
        });

    }

    private void update() {
        this.setVisible(model != null && model.getState() == State.NUMBER_DEFINITION);
        tfNumber.setText(""+model.getNumber());
        tfNumber.requestFocus();
    }
}

