package pt.isec.pa.teostatejfx.ui.gui;

import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import pt.isec.pa.teostatejfx.model.ModelManager;
import pt.isec.pa.teostatejfx.model.fsm.State;

public class ShowDataUI extends BorderPane {
    ModelManager model;
    Button btnPrevious;

    public ShowDataUI(ModelManager model) {
        this.model = model;
        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        this.setStyle("-fx-background-color: #FFA0FF;");
        btnPrevious = new Button("Previous");
        this.setCenter(btnPrevious);

    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });
        btnPrevious.setOnAction(actionEvent -> {
            model.previous();
        });

    }

    private void update() {
        this.setVisible(model != null && model.getState() == State.SHOW_DATA);
    }
}
