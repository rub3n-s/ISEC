package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.data.GameBWData;

public enum GameBWState {
    INITIAL_STATE, BET, EMPTY_BAG;

    // Factory    
    public IGameBWState createState(GameBWContext context, GameBWData data) {
        return switch (this) {
            case INITIAL_STATE -> new InitialState(context,data);
            case BET -> new BetState(context,data);
            case EMPTY_BAG -> new EmptyBagState(context,data);
            default -> null;
        };
    }
}
