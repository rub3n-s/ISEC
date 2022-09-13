package pt.isec.pa.pong.ui;

import javafx.application.Platform;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import pt.isec.pa.pong.model.Game;

import java.net.URL;
import java.util.ResourceBundle;


public class StatsPane implements Initializable {
    public HBox root;
    public Label lbPlayer1;
    public Label lbPlayer2;
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
        game.addListener(Game.PROP_STATS,evt -> Platform.runLater(this::update));
    }

    private void update() {
        int vitP1 = game.getVictories(Game.P1);
        int vitP2 = game.getVictories(Game.P2);
        lbPlayer1.setText(""+vitP1);
        lbPlayer2.setText(""+vitP2);
    }
}
