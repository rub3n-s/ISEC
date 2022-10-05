package pt.isec.pa.gui;

import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import pt.isec.pa.model.ModelManager;
import pt.isec.pa.model.data.ModelData;
import pt.isec.pa.model.fsm.State;

public class BeginUI extends BorderPane {
    ModelManager model;
    Button btnNext;

    public BeginUI(ModelManager model) {
        this.model = model;
        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        this.setStyle("-fx-background-color: #FFA080;");
        btnNext = new Button("Next");
        this.setCenter(btnNext);
    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });
        btnNext.setOnAction(actionEvent -> {
            model.next();
        });
    }

    private void update() {
        this.setVisible(model != null && model.getState() == State.BEGIN);
    }
}

