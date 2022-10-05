package pt.isec.pa.ui;

import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import pt.isec.pa.model.Game;

import java.net.URL;
import java.util.ResourceBundle;

class StatsViewModel {
    Game game;
    StringProperty victP1, victP2;

    public StatsViewModel(Game game) {
        this.game = game;

        victP1 = new SimpleStringProperty("" + game.getVictories(Game.P1));
        victP2 = new SimpleStringProperty("" + game.getVictories(Game.P2));

        game.addListener(Game.PROP_STATS,evt -> Platform.runLater(() -> {
            victP1.set("" + game.getVictories(Game.P1));
            victP2.set("" + game.getVictories(Game.P2));
        }));
    }
}

public class StatsPane implements Initializable {
    public HBox root;
    public Label lbPlayer1;
    public Label lbPlayer2;

    StatsViewModel gameVM;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        root.sceneProperty().addListener((observableValue, oldScene, newScene) -> {
            gameVM = new StatsViewModel((Game) newScene.getUserData());
            registerHandlers();
            update();
        });
    }

    private void registerHandlers() {
        lbPlayer1.textProperty().bind(gameVM.victP1);
        lbPlayer2.textProperty().bind(gameVM.victP2);
    }

    private void update() {

    }
}
