package pt.isec.pa.pong.ui;

import javafx.fxml.Initializable;
import javafx.scene.layout.BorderPane;
import pt.isec.pa.pong.model.Game;

import java.net.URL;
import java.util.ResourceBundle;

public class GamePane implements Initializable {
    public BorderPane root;
    Game game;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        root.sceneProperty().addListener((observableValue, oldScene, newScene) -> {
            game = (Game) newScene.getUserData();
            registerHandlers();
            update();
        });
    }

    private void registerHandlers() {
        //game.addListener(Game.PROP_GAME,evt -> Platform.runLater(this::update));
    }

    private void update() {

    }

}
