package pt.isec.pa.gamebw.model.data;

import java.util.ArrayList;

public class GameBWData {
    private static final int NR_BALLS = 10;
    private ArrayList<BallType> bag;
    private int nrWhiteBallsWon,nrWhiteBallsOut,nrBlackBallsOut;
    private int balls_bet = 0;

    public GameBWData() {
        initGame();
    }

    public void initGame() {
        bag = new ArrayList<>();
        bag.addAll(Collections.nCopies(NR_BALLS,BallType.WHITE));
        bag.addAll(Collections.nCopies(NR_BALLS,BallType.BLACK));
        nrWhiteBallsWon = 0;
        nrWhiteBallsOut = 0;
        nrBlackBallsOut = 0;
        shakeBag();
    }

    public void shakeBag() {
        Collections.shuffle(bag);
    }

    public int getNrWhiteBallsWon() {
        return nrWhiteBallsWon;
    }

    public int getNrWhiteBallsOut() {
        return nrWhiteBallsOut;
    }

    public int getNrBlackBallsOut() {
        return nrBlackBallsOut;
    }

    public boolean bagIsEmpty() {
        return bag.isEmpty();
    }

    public boolean bet(int nr_balls) {
        if (nr_balls>nrWhiteBallsWon)
            return false;
        balls_bet = nr_balls;
        nrWhiteBallsWon -= balls_bet;
        return true;
    }

    public int getBet() {
        return balls_bet;
    }

    public BallType getBall() {
        if (bag.isEmpty())
            return BallType.NONE;
        shakeBag();
        return bag.remove(0);
    }

    public void returnBalls(int nr, BallType type) {
        bag.addAll(Collections.nCopies(nr,type));
    }

    public void betWon() {
        nrWhiteBallsWon += balls_bet;
        nrWhiteBallsWon += 1;
        int tempWhiteBalls = 0;
        for(int i=0;i<balls_bet && !bag.isEmpty();i++) {
            BallType ball = getBall();
            if (ball == BallType.WHITE)
                tempWhiteBalls += 1;
            else
                nrBlackBallsOut += 1;
        }
        if (tempWhiteBalls>0)
            returnBalls(tempWhiteBalls,BallType.WHITE);
    }

    public void betLost() {
        nrWhiteBallsOut += balls_bet;
        nrBlackBallsOut += 1;
    }
    public boolean betLost_optionWhite() {
        if (nrWhiteBallsWon < 1)
            return false;
        nrWhiteBallsWon -= 1;
        nrWhiteBallsOut += 1;
        return true;
    }
    public void betLost_optionTwoBalls() {
        BallType ball1 = getBall();
        BallType ball2 = getBall();

        if (ball1 == BallType.WHITE)
            nrWhiteBallsOut += 1;
        else if (ball1 == BallType.BLACK)
            bag.add(ball1);

        if (ball2 == BallType.WHITE)
            nrWhiteBallsOut += 1;
        else if (ball2 == BallType.BLACK)
            bag.add(ball2);
    }
}
