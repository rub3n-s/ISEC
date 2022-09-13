package pt.isec.pa.teostatejfx.model;

import pt.isec.pa.teostatejfx.model.fsm.Context;
import pt.isec.pa.teostatejfx.model.fsm.State;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

public class ModelManager {
    public static final String PROP_STATE = "state";
    public static final String PROP_DATA  = "data";

    Context context;
    PropertyChangeSupport pcs;

    public ModelManager() {
        this.context = new Context();
        pcs = new PropertyChangeSupport(this);
    }

    public void addPropertyChangeListener(String property, PropertyChangeListener listener) {
        pcs.addPropertyChangeListener(property, listener);
    }

    public State getState() {
        return context.getState();
    }

    public void next() {
        context.next();
        pcs.firePropertyChange(PROP_STATE,null,context.getState());
    }

    public void previous() {
        context.previous();
        pcs.firePropertyChange(PROP_STATE,null,context.getState());
    }

    public void changeMessage(String msg) {
        context.changeMessage(msg);
        pcs.firePropertyChange(PROP_DATA,null,null);
    }

    public void changeNumber(int nr) {
        context.changeNumber(nr);
        pcs.firePropertyChange(PROP_DATA,null,null);
    }

    public int getNumber() {
        return context.getNumber();
    }

    public String getMessage() {
        return context.getMessage();
    }

}
