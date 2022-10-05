package pt.isec.pa.mavenTest;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

// addFrameWorkSupport > botao direito sobre o projeto
public class Main extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Scene scene = new Scene(new Pane(),500, 500, Color.BLACK);
        stage.setScene(scene);
        stage.setTitle("Teste");
        stage.show();
    }

    // Para correr o projeto:
    // MavenTest > Plugins > javafx -> javafx:run > btn direito > Run Project

    /* Depois de correr a primeira vez, se não houverem problemas, ja nao será preciso
     fazer este passos */
}
