package ui.gui;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.awt.*;

public class JavaFXMain extends Application {
    public JavaFXMain() {

    }

    @Override
    public void start(Stage stage) throws Exception {
        RootPane root = new RootPane();
        Scene scene = new Scene(root,600,400);
        stage.setScene(scene);
        stage.setTitle("Ex29");
        stage.show();
    }
}
