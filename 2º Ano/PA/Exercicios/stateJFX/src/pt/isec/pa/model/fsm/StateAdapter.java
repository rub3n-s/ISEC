package pt.isec.pa.model.fsm;

import pt.isec.pa.model.data.ModelData;

public abstract class StateAdapter implements IState {
    protected Context context;
    protected ModelData data;

    protected StateAdapter(Context context, ModelData data) {
        this.context = context;
        this.data = data;
    }

    protected void changeState(State newState) {
        context.changeState(newState.createState(context,data));
    }

    @Override
    public void changeMessage(String msg) {

    }

    @Override
    public void changeNumber(int nr) {

    }

    @Override
    public void next() {

    }

    @Override
    public void previous() {

    }
}
