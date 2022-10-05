package pt.isec.pa.gui;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import pt.isec.pa.model.ModelManager;

public class StatusBar extends HBox {
    ModelManager model;
    Label lbMsg, lbNumber;

    public StatusBar(ModelManager model) {
        this.model = model;

        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        Label lbMsgTitle = new Label("Message: ");
        lbMsgTitle.setPrefWidth(Integer.MAX_VALUE);
        lbMsgTitle.setAlignment(Pos.CENTER_RIGHT);
        lbMsg = new Label();
        lbMsg.setPrefWidth(Integer.MAX_VALUE);
        lbMsg.setAlignment(Pos.CENTER_LEFT);
        Label lbNumberTitle = new Label("Number: ");
        lbNumberTitle.setPrefWidth(Integer.MAX_VALUE);
        lbNumberTitle.setAlignment(Pos.CENTER_RIGHT);
        lbNumber = new Label();
        lbNumber.setPrefWidth(Integer.MAX_VALUE);
        lbNumber.setAlignment(Pos.CENTER_LEFT);
        this.getChildren().addAll(lbMsgTitle, lbMsg, lbNumberTitle, lbNumber);
    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_DATA, evt -> {
            update();
        });
    }

    private void update() {
        lbMsg.setText(model.getMessage());
        lbNumber.setText("" + model.getNumber());
    }
}
