package pt.isec.pa.ui;

import javafx.application.Platform;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import pt.isec.pa.model.Game;

import java.net.URL;
import java.util.ResourceBundle;

public class BoardPane implements Initializable {
    public Pane root;
    public Canvas board;
    Game game;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        root.sceneProperty().addListener((observableValue, oldScene, newScene) -> {
            game = (Game) newScene.getUserData();
            game.initGame();
            registerHandlers();
            update();
        });
    }

    private void registerHandlers() {
        game.addListener(Game.PROP_GAME,evt -> Platform.runLater(this::update));

        board.widthProperty().bind(root.widthProperty());
        board.heightProperty().bind(root.heightProperty());

        board.widthProperty().addListener(observable -> update());
        board.heightProperty().addListener(observable -> update());

        //root.widthProperty().addListener(obs -> updateBoardSize());
        //root.heightProperty().addListener(obs -> updateBoardSize());

        board.setOnKeyPressed(keyEvent -> {
            switch (keyEvent.getCode()) {
                case A -> game.movePlayer(Game.P1,Game.PLAYER_MOVE_UP);
                case Z -> game.movePlayer(Game.P1,Game.PLAYER_MOVE_DOWN);
                case K -> game.movePlayer(Game.P2,Game.PLAYER_MOVE_UP);
                case M -> game.movePlayer(Game.P2,Game.PLAYER_MOVE_DOWN);
                default -> { }
            }
        });
    }

    public void updateBoardSize() {
            board.setWidth(root.getWidth());
            board.setHeight(root.getHeight());
            update();
    }

    private static final Color colorBackground  = Color.BLACK;
    private static final Color colorLines       = Color.WHITE;
    private static final Color colorPlayer1     = Color.ORANGE; // original: Color.WHITE
    private static final Color colorPlayer2     = Color.YELLOW; // original: Color.WHITE
    private static final Color colorBall        = Color.RED;    // original: Color.WHITE

    private void update() {
        board.requestFocus();
        double w = board.getWidth();
        double h = board.getHeight();
        GraphicsContext gc = board.getGraphicsContext2D();
        gc.setFill(colorBackground);
        gc.fillRect(0,0,w,h);
        gc.setStroke(colorLines);
        gc.setLineWidth(5);
        gc.setLineDashes(5,10);
        gc.strokeLine(w/2,0,w/2,h);

        double playerWidth = game.getWidthPlayer();
        double pPos = game.getPosPlayer(Game.P1);
        double pHeight = game.getHeightPlayer(Game.P1);
        gc.setFill(colorPlayer1);
        gc.fillRect(playerWidth*w,pPos*h,playerWidth*w,pHeight*h);

        pPos = game.getPosPlayer(Game.P2);
        pHeight = game.getHeightPlayer(Game.P2);
        gc.setFill(colorPlayer2);
        gc.fillRect(w-2*playerWidth*w,pPos*h,playerWidth*w,pHeight*h);

        double ballRadius = game.getRadiusBall()*w;
        double posbX = game.getPosBallX()*w-ballRadius/2;
        double posbY = game.getPosBallY()*h-ballRadius/2;

        gc.setFill(colorBall);
        gc.fillOval(posbX,posbY,ballRadius,ballRadius);

    }
}
