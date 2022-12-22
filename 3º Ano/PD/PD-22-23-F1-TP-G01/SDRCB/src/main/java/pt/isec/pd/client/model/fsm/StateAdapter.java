package pt.isec.pd.client.model.fsm;

import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.shared_data.Seat;

import java.util.HashMap;
import java.util.List;

public abstract class StateAdapter implements IState {
    protected Context context;
    protected Client data;

    protected StateAdapter(Context context, Client data) {
        this.context = context;
        this.data = data;
    }

    protected void changeState(State newState) {
        context.changeState(newState.createState(context,data));
    }


    @Override
    public void next() { context.next(); }

    @Override
    public void login(String userName, String password) {
         context.login(userName,password);
    }

    @Override
    public void register(String userName, String name, String password) {
        context.register(userName,name,password);
    }

    @Override
    public void edit(ClientAction action, String edit) {
        context.edit(action,edit);
    }

    @Override
    public void previous() {

    }

    @Override
    public void disconnect() {
        data.disconnect();
    }

    @Override
    public void registerTransition() {

    }

    @Override
    public void editTransition() {

    }

    @Override
    public void showsTransition() {

    }

    @Override
    public void consultShows(HashMap<String, String> filters) {}

    @Override
    public List<Seat> getSeatsAndPrices() {
        return null;
    }

    @Override
    public void seatsTransition(Integer idSwow) {
    }

    @Override
    public void insertShowsTransition() {
    }

    @Override
    public void insertShows(String filePath) {
    }

    @Override
    public void deleteShow(int idShow) {
    }

    @Override
    public void showVisible(int idShow) {
    }

    @Override
    public void selectShowsTransition() {

    }

    @Override
    public void submitReservation(List<Seat> seats) {
    }

    @Override
    public void consultsPaymentsAwaitingTransition() { }

    @Override
    public void consultsPaymentsTransition() { }

    @Override
    public void consultsPaymentsAwaiting() { }

    @Override
    public void payReservationTransition(int resId) { }

    @Override
    public void deleteReservationAwaiting(int resId) { }

    @Override
    public void consultsPayments() { }

    @Override
    public void payReservation() { }

    @Override
    public void deleteReservation() { }

    @Override
    public Object getResponse() {
        return data.getResponse();
    }

    @Override
    public void payReservationTransitionToState(int resId, int showId) {

    }

    @Override
    public void showNotification(int showId) {

    }

    @Override
    public String getMessage() {
        return null;
    }

    @Override
    public void setMessage(String message) {
    }

    @Override
    public void notifyMessage() {

    }
}
