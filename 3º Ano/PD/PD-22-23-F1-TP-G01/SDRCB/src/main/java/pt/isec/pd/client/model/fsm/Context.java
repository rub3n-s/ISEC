package pt.isec.pd.client.model.fsm;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.shared_data.Reserve;
import pt.isec.pd.shared_data.Seat;
import pt.isec.pd.shared_data.ServerAddress;
import pt.isec.pd.shared_data.Show;

import java.beans.PropertyChangeSupport;
import java.util.HashMap;
import java.util.List;

public class Context {
    Client data;
    IState state;

    public Context(ServerAddress udpConn,PropertyChangeSupport pcs) {
        data = new Client(udpConn,pcs);
        state = State.LOGIN.createState(this,data);
    }

    public void changeState(IState state) {
        this.state = state;
    }

    public State getState() {
        return state.getState();
    }

    public void next() { state.next(); }

    public void login(String userName, String password) {
        state.login(userName,password);
    }

    public void register(String userName,String name,String password) {
        state.register(userName,name,password);
    }

    public void edit(ClientAction action, String edit) {
        state.edit(action,edit);
    }

    public void previous() { state.previous(); }

    public void disconnect() {
        data.disconnect();
    }

    public void swapToRegister() {state.registerTransition();}

    public void editTransition() {
        state.editTransition();
    }

    public void showsTransition() { state.showsTransition(); }

    public void consultShows(HashMap<String,String> filters) {
        state.consultShows(filters);
    }

    public List<Seat> getSeatsAndPrices() {
        return state.getSeatsAndPrices();
    }

    public void seatsTransition(Integer idShow) {
        state.seatsTransition(idShow);
    }

    public void insertShowsTransition() {
        state.insertShowsTransition();
    }

    public void insertShows(String filePath) {
        state.insertShows(filePath);
    }

    public void deleteShow(int idShow) {
        state.deleteShow(idShow);
    }

    public void showVisible(int idShow) {
         state.showVisible(idShow);
    }

    public void selectShowsTransition() {
        state.selectShowsTransition();
    }

    public void submitReservation(List<Seat> seats) {
        state.submitReservation(seats);
    }

    public void consultsPaymentsAwaitingTransition() { state.consultsPaymentsAwaitingTransition(); }

    public void consultsPaymentsAwaiting() { state.consultsPaymentsAwaiting(); }

    public void consultPaymentsTransition() { state.consultsPaymentsTransition(); }

    public void consultPayments() { state.consultsPayments(); }

    public void payReservationTransition(int resId) { state.payReservationTransition(resId); }

    public Object getResponse() { return state.getResponse(); }

    public void payReservation() { state.payReservation(); }

    public void deleteReservation() { state.deleteReservation(); }

    public void deleteReservationAwaiting(int resId) { state.deleteReservationAwaiting(resId);}

    public void payReservationTransitionToState(int resId, int showId) {
        state.payReservationTransitionToState(resId,showId);
    }

    public void showNotification(int show) {
        state.showNotification(show);
    }

    public String getMessage() {
        return data.getMessage();
    }

    public void setMessage(String message) {
        data.setMessage(message);
    }

    public void notifyMessage() {
        data.setMessage("There was a problem with the server try again");
    }
}
