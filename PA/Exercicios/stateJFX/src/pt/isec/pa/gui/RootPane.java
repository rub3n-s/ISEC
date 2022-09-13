package pt.isec.pa.gui;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import pt.isec.pa.model.ModelManager;
import pt.isec.pa.model.data.ModelData;

public class RootPane extends BorderPane {
    ModelManager model;

    public RootPane(ModelManager model) {
        this.model = model;

        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        StackPane stackPane = new StackPane(
                new BeginUI(model), new MessageDefinitionUI(model),
                new NumberDefinitionUI(model), new ShowDataUI(model) );
        this.setCenter(stackPane);

        this.setBottom(new StatusBar(model));
    }

    private void registerHandlers() { }

    private void update() { }
}
