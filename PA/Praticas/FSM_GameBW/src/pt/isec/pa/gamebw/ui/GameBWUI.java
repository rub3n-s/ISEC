package pt.isec.pa.gamebw.ui;

import pt.isec.pa.gamebw.model.fsm.GameBWContext;
import pt.isec.pa.gamebw.ui.utils.PAInput;

public class GameBWUI {
    GameBWContext fsm;

    public GameBWUI(GameBWContext fsm) {
        this.fsm = fsm;
    }

    private boolean finish = false;
    public void start() {
        while(!finish) {
            showResults();
            if (fsm.getState() == null) System.exit(-1); // TODO: remove!
            switch (fsm.getState()) {
                case INITIAL_BET -> initialUI();
                case WAIT_BET -> waitingBet();
                case LOST_WAITDECISION -> lostWaitDecisionUI();
            }
        }
    }

    private void showResults() {
        System.out.println("\n*** Game GW ***");
        System.out.printf("White Balls won: %d\n",fsm.getNrWhiteBallsWon());
        System.out.printf("White Balls out: %d\n",fsm.getNrWhiteBallsOut());
        System.out.printf("Black Balls out: %d\n",fsm.getNrBlackBallsOut());
    }

    private void initialUI() {
        switch(PAInput.chooseOption("Bet", "End")) {
            case 1 -> whatsTheBet();
            case 2 -> fsm.end();
            default -> finish = true;
        }
    }

    private void waitingBet() {
        switch(PAInput.chooseOption("Bet", "Get Random Ball","End")) {
            case 1 -> whatsTheBet();
            case 2 -> fsm.getRandom();
            case 3 -> fsm.end();
            default -> finish = true;
        }
    }

    private void lostWaitDecisionUI() {
        switch(PAInput.chooseOption("Remove two balls", "Lose white ball", "End")) {
            case 1 -> fsm.removeTwoBalls();
            case 2 -> fsm.loseWhiteBall();
            case 3 -> fsm.end();
            default -> finish = true;
        }
    }

    private void whatsTheBet() {
        int nrBalls = 0;
        do {
            nrBalls = PAInput.readInt("Choose a number of balls to bet between [0..." + fsm.getNrWhiteBallsWon() + "]");
            fsm.bet(nrBalls);
        } while(!fsm.bet(nrBalls));
    }
}
