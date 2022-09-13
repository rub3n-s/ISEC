package pt.isec.pa.pong.model;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

public class Game {
    public static final int P1 = 0;
    public static final int P2 = 1;
    public static final int PLAYER_MOVE_UP = 0;
    public static final int PLAYER_MOVE_DOWN = 1;

    public static final String PROP_GAME = "_game_";
    public static final String PROP_STATS = "_stats_";

    private static final double PLAYER_STEP = 0.05;
    private static final double BALL_STEP = 0.02;

    private double[] posPlayer;
    private double[] heightPlayer;
    private double widthPlayer;
    private final int[] victories;
    private double posBallX, posBallY; //0.0-1.0
    private double radiusBall;
    private double speedBallX, speedBallY;
    private boolean isGameActive, isGamePaused;

    PropertyChangeSupport pcs;

    public Game() {
        victories = new int[]{0, 0};
        isGameActive = false;
        pcs = new PropertyChangeSupport(this);
    }

    public void addListener(String property, PropertyChangeListener listener) {
        pcs.addPropertyChangeListener(property, listener);
    }

    public void initGame() {
        posPlayer = new double[]{0.4, 0.4};
        heightPlayer = new double[]{0.2, 0.2};
        widthPlayer = 0.025;

        posBallX = 0.5;
        posBallY = 0.5;
        radiusBall = 0.025;
        speedBallX = Math.random() < 0.5 ? BALL_STEP / 2 : -BALL_STEP / 2;
        speedBallY = Math.random() < 0.5 ? BALL_STEP : -BALL_STEP;

        if (!gameEngine.isAlive()) {
            gameEngine.setDaemon(true);
            gameEngine.start();
        }
        isGameActive = true;
        isGamePaused = false;
    }

    public void movePlayer(int player, int mode) {
        if (!isGameActive || isGamePaused)
            return;
        double move = mode == PLAYER_MOVE_UP ? -PLAYER_STEP : PLAYER_STEP;
        if (posPlayer[player] + move < 0)
            posPlayer[player] = 0;
        else if (posPlayer[player] + heightPlayer[player] + move > 1)
            posPlayer[player] = 1 - heightPlayer[player];
        else
            posPlayer[player] += move;
        pcs.firePropertyChange(PROP_GAME, null, null);
    }

    void moveBall() {
        if (!isGameActive || isGamePaused)
            return;

        double newX = posBallX + speedBallX;
        double newY = posBallY + speedBallY;
        if (newY >= 1.0 - radiusBall) {
            newY = 1.0 - radiusBall;
            speedBallY = -speedBallY;
        } else if (newY <= radiusBall) {
            newY = radiusBall;
            speedBallY = -speedBallY;
        }
        if (newX < 2 * widthPlayer + radiusBall && newY >= posPlayer[P1] && newY < posPlayer[P1] + heightPlayer[P1]) {
            if (speedBallX>0)
                endGame(P2);
            else
                speedBallX = -speedBallX;
        } else if (newX > 1.0 - 2*widthPlayer - radiusBall && newY >= posPlayer[P2] && newY < posPlayer[P2] + heightPlayer[P2]) {
            if (speedBallX<0)
                endGame(P1);
            else
                speedBallX = -speedBallX;
        } else if (newX <= radiusBall) {
            endGame(P2);
        } else if (newX >= 1.0 - radiusBall) {
            endGame(P1);
        }
        posBallX = newX;
        posBallY = newY;
        pcs.firePropertyChange(PROP_GAME, null, null);
    }

    private void endGame(int winner) {
        posBallX = -1;
        posBallY = -1;
        victories[winner]++;
        isGameActive = false;
        isGamePaused = true;
        pcs.firePropertyChange(PROP_GAME, null, null);
        pcs.firePropertyChange(PROP_STATS, null, null);
    }

    public void resumeGame() {
        if (!isGamePaused)
            return;
        isGamePaused = false;
        pcs.firePropertyChange(PROP_GAME, null, null);
    }

    public void pauseGame() {
        isGamePaused = true;
        pcs.firePropertyChange(PROP_GAME, null, null);
    }

    public boolean isGameActive() {
        return isGameActive;
    }

    public boolean isGamePaused() {
        return isGamePaused;
    }

    public double getPosPlayer(int player) {
        return posPlayer[player];
    }

    public double getHeightPlayer(int player) {
        return heightPlayer[player];
    }

    public int getVictories(int player) {
        return victories[player];
    }

    public double getPosBallX() {
        return posBallX;
    }

    public double getPosBallY() {
        return posBallY;
    }

    public double getRadiusBall() {
        return radiusBall;
    }

    public double getWidthPlayer() {
        return widthPlayer;
    }

    private static final int INTERVAL = 50;

    private final Thread gameEngine = new Thread(() -> {
        while (true) {
            try {
                Thread.sleep(INTERVAL);
            } catch (Exception e) {
                break;
            }
            moveBall();
        }
    });
}
