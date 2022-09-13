package pt.isec.pa.ui;

import javafx.application.Platform;
import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.event.ActionEvent;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import pt.isec.pa.model.Game;

import java.net.URL;
import java.util.ResourceBundle;

class CommandsViewModel {
    Game game;
    BooleanProperty cantStart, cantPause, cantRestart;

    public CommandsViewModel(Game game) {
        this.game = game;
        cantStart = new SimpleBooleanProperty(false);
        cantPause = new SimpleBooleanProperty(false);
        cantRestart = new SimpleBooleanProperty(false);

        game.addListener(Game.PROP_GAME,evt -> Platform.runLater(() -> {
            cantStart.set(game.isGameActive());
            cantPause.set(!game.isGameActive() || game.isGamePaused());
            cantRestart.set(!game.isGameActive() || !game.isGamePaused());
        }));
    }

    public void start() {
        game.initGame();
    }

    public void resumeGame() {
        game.resumeGame();
    }

    public void pauseGame() {
        game.pauseGame();
    }
}

public class CommandsPane implements Initializable {
    public HBox root;
    public Button btnStart;
    public Button btnPause;
    public Button btnResume;
    CommandsViewModel gameVM;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        root.sceneProperty().addListener((observableValue, olsScene, newScene) -> {
            gameVM = new CommandsViewModel((Game) newScene.getUserData());
            registerHandlers();
            update();
        });
    }

    private void registerHandlers() {
        btnStart.disableProperty().bind(gameVM.cantStart);
        btnPause.disableProperty().bind(gameVM.cantPause);
        btnResume.disableProperty().bind(gameVM.cantRestart);
    }

    private void update() {
    }

    public void onStart(ActionEvent ignoredEvent) {
        gameVM.start();
    }

    public void onPause(ActionEvent ignoredEvent) {
        gameVM.pauseGame();
    }

    public void onResume(ActionEvent ignoredEvent) {
        gameVM.resumeGame();
    }
}
