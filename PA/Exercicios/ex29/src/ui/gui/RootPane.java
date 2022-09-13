package ui.gui;

import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public class RootPane extends BorderPane {
    int numberBlues;
    Color background = Color.OLIVE;
    Button button;
    TextField tfColor;
    Label lbStatus;

    // variables, inc. views
    public RootPane() {
        numberBlues = 0;
        button = new Button("Change Color");
        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        button = new Button("Blue");
        button.setMinWidth(75);

        tfColor = new TextField();
        tfColor.setPromptText("Color name or RGB");
        tfColor.setPrefWidth(Integer.MAX_VALUE);
        tfColor.setMinWidth(200);

        HBox hbox = new HBox();
        hbox.getChildren().addAll(button,tfColor);
        hbox.setPadding(new Insets(10));
        hbox.setSpacing(10);
        this.setTop(hbox);

        // cria a label
        lbStatus = new Label("Clicks: " + numberBlues);
        lbStatus.setPrefWidth(Integer.MAX_VALUE);
        lbStatus.setStyle("-fx-background-color: #d0d0d0; -fx-font-size: 16; -fx-font-family: 'Roboto Light'");
        lbStatus.setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.DOTTED, CornerRadii.EMPTY, BorderWidths.DEFAULT)));
        this.setBottom(lbStatus);
    }

    private void registerHandlers() {
        /* handlers/listeners */
        button.setOnAction(actionEvent -> {
            background = Color.BLUE;
            numberBlues++;
            System.out.println("BLUE" + tfColor.getText());
            tfColor.requestFocus();
            update();
        });

        tfColor.setOnKeyPressed(keyEvent -> {
            tfColor.setStyle("-fx-control-inner-background: #000000;");
           if (keyEvent.getCode() == KeyCode.ENTER)
               button.fire();
        });
    }

    private void update() {
        this.setBackground(new Background(new BackgroundFill(background, CornerRadii.EMPTY,Insets.EMPTY)));
        lbStatus.setText("Clicks ..." + numberBlues);
    }
}
