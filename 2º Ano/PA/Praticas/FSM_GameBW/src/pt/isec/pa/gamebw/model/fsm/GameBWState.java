package pt.isec.pa.gamebw.model.fsm;

import pt.isec.pa.gamebw.model.data.GameBWData;

public enum GameBWState {
    INITIAL_BET, WAIT_BET, LOST_WAITDECISION; // TODO

    public IGameBWState createState(GameBWContext context, GameBWData data) {
        return switch (this) {
            case INITIAL_BET -> new InitialBetState(context,data);
            case WAIT_BET -> new WaitBetState(context,data);
            case LOST_WAITDECISION -> new LostWaitDecisionState(context,data);
            default -> null;
        };
    }
}
