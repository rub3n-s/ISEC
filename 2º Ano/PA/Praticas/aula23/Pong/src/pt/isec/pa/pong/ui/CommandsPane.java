package pt.isec.pa.pong.ui;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import pt.isec.pa.pong.model.Game;

import java.net.URL;
import java.util.ResourceBundle;

public class CommandsPane implements Initializable {
    public HBox root;
    public Button btnStart;
    public Button btnPause;
    public Button btnResume;
    Game game;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        root.sceneProperty().addListener((observableValue, olsScene, newScene) -> {
            game = (Game) newScene.getUserData();
            registerHandlers();
            update();
        });
    }

    private void registerHandlers() {
        game.addListener(Game.PROP_GAME,evt -> Platform.runLater(this::update));
    }

    private void update() {
        btnStart.setDisable(game.isGameActive());
        btnPause.setDisable(!game.isGameActive() || game.isGamePaused());
        btnResume.setDisable(!game.isGameActive() || !game.isGamePaused());
    }

    public void onStart(ActionEvent ignoredEvent) {
        game.initGame();
    }

    public void onPause(ActionEvent ignoredEvent) {
        game.pauseGame();
    }

    public void onResume(ActionEvent ignoredEvent) {
        game.resumeGame();
    }
}
