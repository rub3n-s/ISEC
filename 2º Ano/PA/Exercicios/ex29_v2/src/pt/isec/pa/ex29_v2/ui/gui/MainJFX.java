package pt.isec.pa.ex29_v2.ui.gui;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import pt.isec.pa.ex29_v2.models.Figura;

public class MainJFX extends Application {
    Figura figura;

    @Override
    public void init() throws Exception {
        super.init();
        figura = new Figura();
    }

    @Override
    public void start(Stage stage) throws Exception {
        RootPane rootPane = new RootPane(figura);
        Scene scene = new Scene(rootPane, 600, 500);
        stage.setScene(scene);
        stage.setTitle("DEIS-ISEC");
        stage.show();
    }
}
