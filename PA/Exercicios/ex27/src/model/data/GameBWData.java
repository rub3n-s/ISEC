package model.data;

import java.util.Collections;

public class GameBWData {
    private static final int NR_BALLS = 10;
    private ArrayList<BallType> bag;
    private int nrWhiteBallsWon, nrWhiteBallsOut, nrBlackBallsOut;
    private int balls_bet = 0;

    public GameBWData() {
        initGame();
    }

    public void initGame() {
        bag = new ArrayList();
        bag.addAll(Collections.nCopies(NR_BALLS,BallType.WHITE));
        bag.addAll(Collections.nCopies(NR_BALLS,BallType.WHITE));        
    }

    public void shakeBag() {
        // shuffle array, mete ordem aleatoria
    }

    public boolean bagIsEmpty() {
        return bag.bagIsEmpty();
    }

    //bet(int nrBalls)

    //getbet()

    //BallType getBall() {
    //     if (bag.isempty())
    //      return BallType.NONE; 
    //      shakeBag(); 
    //      return bag.remove(0))
    // }

    // betWon()

    // betLost()

    // betLost_optionWhite

    // betLost_optionTwoBalls
}
