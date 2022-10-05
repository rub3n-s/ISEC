package pt.isec.pa.ex30.ui.gui;

import javafx.scene.control.ContextMenu;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import pt.isec.pa.ex30.model.DrawingManager;
import pt.isec.pa.ex30.model.Figure;

public class ListPane extends ListView<Figure> {
    DrawingManager drawing;
    MenuItem delete, change;

    public ListPane(DrawingManager drawing) {
        this.drawing = drawing;

        createViews();
        registerHandlers();
        update();
    }

    public void createViews() {
        delete = new MenuItem("Delete");
        change = new MenuItem("Change color");

        this.setContextMenu(new ContextMenu(delete, change));
    }

    public void registerHandlers() {
        drawing.addPropertyChangeListener(DrawingManager.PROP_FIGURES, evt -> update());

        this.setOnMouseClicked(mouseEvent -> {
            if (mouseEvent.getClickCount() == 2) {
                drawing.remove(this.getSelectionModel().getSelectedIndex());
            }
        });

        delete.setOnAction(actionEvent -> {
            //drawing.remove(this.getSelectionModel().getSelectedIndex());
            delete.fire();
        });
    }

    public void update() {
        this.getItems().clear();
        this.getItems().addAll(drawing.getList());
    }
}
