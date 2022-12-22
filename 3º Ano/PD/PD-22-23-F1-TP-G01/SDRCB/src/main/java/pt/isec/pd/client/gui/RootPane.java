package pt.isec.pd.client.gui;

import javafx.fxml.FXMLLoader;
import javafx.scene.layout.*;
import pt.isec.pd.client.gui.view.*;
import pt.isec.pd.client.model.ModelManager;

import java.io.IOException;

public class RootPane extends BorderPane {
    ModelManager model;

    public RootPane(ModelManager model) {
        this.model = model;

        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        FXMLLoader login = new FXMLLoader(RootPane.class.getResource("/fxml/login-form.fxml"));
        FXMLLoader register = new FXMLLoader(RootPane.class.getResource("/fxml/register-form.fxml"));
        FXMLLoader edit = new FXMLLoader(RootPane.class.getResource("/fxml/edit-form.fxml"));
        FXMLLoader menuClient = new FXMLLoader(RootPane.class.getResource("/fxml/menu-client-form.fxml"));
        FXMLLoader shows = new FXMLLoader(RootPane.class.getResource("/fxml/shows-form.fxml"));
        FXMLLoader seats_prices = new FXMLLoader(RootPane.class.getResource("/fxml/seats-form.fxml"));
        FXMLLoader payReservation = new FXMLLoader(RootPane.class.getResource("/fxml/pay-reservation-form.fxml"));

        FXMLLoader menuAdmin = new FXMLLoader(RootPane.class.getResource("/fxml/menu-admin-form.fxml"));
        FXMLLoader insertShows = new FXMLLoader(RootPane.class.getResource("/fxml/manage-shows-form.fxml"));
        FXMLLoader selectShows = new FXMLLoader(RootPane.class.getResource("/fxml/select-shows.fxml"));
        FXMLLoader consultPaymentsAwaiting = new FXMLLoader(RootPane.class.getResource("/fxml/consult-payments-awaiting-form.fxml"));
        FXMLLoader consultPayReservations = new FXMLLoader(RootPane.class.getResource("/fxml/consult-payments-form.fxml"));

        StackPane stackPane;
        try {
            stackPane = new StackPane(login.load(),register.load(),
                    edit.load(),menuClient.load(),shows.load(),
                    seats_prices.load(),menuAdmin.load(),
                    insertShows.load(),selectShows.load(),
                    consultPaymentsAwaiting.load(),
                    payReservation.load(),consultPayReservations.load());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }



        login.<LoginForm>getController().setModel(model);
        register.<RegisterForm>getController().setModel(model);
        edit.<EditForm>getController().setModel(model);
        menuClient.<MenuClientForm>getController().setModel(model);
        menuAdmin.<MenuAdminForm>getController().setModel(model);
        shows.<ShowsForm>getController().setModel(model);
        seats_prices.<SeatsForm>getController().setModel(model);
        insertShows.<ManageShowsForm>getController().setModel(model);
        selectShows.<SelectShows>getController().setModel(model);
        consultPaymentsAwaiting.<ConsultPaymentsAwaitingForm>getController().setModel(model);
        payReservation.<PayReservationForm>getController().setModel(model);
        consultPayReservations.<ConsultPaymentsForm>getController().setModel(model);

        this.setCenter(stackPane);
        this.setBottom(new StatusBar(model));
    }

    private void registerHandlers() { }

    private void update() { }
}
