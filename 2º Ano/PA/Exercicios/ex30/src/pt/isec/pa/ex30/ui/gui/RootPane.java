package pt.isec.pa.ex30.ui.gui;

import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import pt.isec.pa.ex30.model.Drawing;
import pt.isec.pa.ex30.model.DrawingManager;

public class RootPane extends BorderPane {
    DrawingManager drawing;

    DrawingArea drawingArea;
    Pane areaPane;

    // alinea b)
    Drawing toolBar;

    public RootPane(DrawingManager drawing) {
        this.drawing = drawing;

        createViews();
        registerHandlers();
    }

    private void createViews() {
        drawingArea = new DrawingArea(drawing);
        areaPane = new Pane(drawingArea);
        setCenter(areaPane);

        // so vai ser criada uma vez porque nunca vai ser alterada
        setTop(
            new VBox(
                    new AppMenu(drawing),
                    new DrawingToolBar(drawing)
            )
        );
    }

    private void registerHandlers() {
        areaPane.heightProperty();
        areaPane.widthProperty().addListener(observable -> drawingArea.updateSize(areaPane.getWidth(),areaPane.getHeight()));
        areaPane.heightProperty().addListener(observable -> drawingArea.updateSize(areaPane.getWidth(),areaPane.getHeight()));
    }
}
