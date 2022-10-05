package pt.isec.pa.four_in_a_row;

import pt.isec.pa.four_in_a_row.model.FourInARowData;
import pt.isec.pa.four_in_a_row.ui.FourInARowUI;

public class FourInARow {
    public static void main(String[] args) {
        FourInARowData game = new FourInARowData();
        FourInARowUI gameui= new FourInARowUI(game);
        gameui.start();
    }
}
