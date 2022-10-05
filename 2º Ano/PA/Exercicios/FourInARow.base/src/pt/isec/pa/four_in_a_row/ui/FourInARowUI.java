package pt.isec.pa.four_in_a_row.ui;

import pt.isec.pa.four_in_a_row.model.FourInARowData;
import pt.isec.pa.four_in_a_row.model.Piece;
import pt.isec.pa.four_in_a_row.ui.utils.PAInput;

public class FourInARowUI {
    FourInARowData game;

    public FourInARowUI(FourInARowData game) {
        this.game = game;
    }

    public void start() {
        Piece winner = Piece.NONE;
       while (!game.isFull() && (winner=game.checkWinner()) == Piece.NONE) {
            System.out.println("\n" + game);
            System.out.println("\nCurrent player: " + game.getCurrentPlayer() +"\n");
            int move = PAInput.readInt("Column: ");
            game.play(move);
        }
        System.out.println("\n\n"+game);
       if (winner != Piece.NONE)
           System.out.println("The winner was: "+winner);
       else
           System.out.println("It was a draw");

    }
}
