package pt.isec.pd.client.gui.view;

import javafx.collections.FXCollections;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.util.Pair;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.DeleteResponse;
import pt.isec.pd.shared_data.Responses.HandleVisibleShowResponse;
import pt.isec.pd.shared_data.Responses.InsertShowResponse;
import pt.isec.pd.shared_data.Responses.ShowsResponse;
import pt.isec.pd.shared_data.Show;

import java.util.List;

public class ManageShowsForm {
    public Button insertShowsButton;
    public TextField filePath;
    public ListView<Show> list;
    public AnchorPane pane;
    public Button retrocederButton;
    public Button removeButton;
    public Button handleVisibilityButton;
    private ModelManager model;

    public void setModel(ModelManager model) {
        this.model = model;

        registerHandlers();
        update();
    }

    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
        });

        model.addPropertyChangeListener(ClientAction.CONSULT_SHOWS_ALL.toString(), evt -> {
            bindList();
            ShowsResponse showsResponse = (ShowsResponse) model.getResponse();
            list.setItems(FXCollections.observableList(showsResponse.getShows()));
        });

        model.addPropertyChangeListener(ClientAction.INSERT_SHOWS.toString(), evt -> {
            InsertShowResponse showsResponse = (InsertShowResponse) model.getResponse();
            model.setMessage(showsResponse.getMsg());
        });

        model.addPropertyChangeListener(ClientAction.DELETE_SHOW.toString(), evt -> {
            DeleteResponse response = (DeleteResponse) model.getResponse();
            model.setMessage(response.getMsg());
        });

        model.addPropertyChangeListener(ClientAction.VISIBLE_SHOW.toString(), evt -> {
            HandleVisibleShowResponse handleVisibleShowResponse = (HandleVisibleShowResponse) model.getResponse();
            model.setMessage(handleVisibleShowResponse.getMsg());
        });

        retrocederButton.setOnAction(actionEvent ->{
            model.insertShowsTransition();
        });

        insertShowsButton.setOnAction(actionEvent -> {
            model.setMessage("");
            if (filePath.getText().isEmpty())
                return;
            model.insertShows(filePath.getText());
        });

        removeButton.setOnAction(actionEvent -> {
            model.setMessage("");
            if (list.getSelectionModel().getSelectedItem() == null) {
                model.setMessage("Selecione o espetaculo que pretende remover");
                return;
            }

            model.deleteShow(list.getSelectionModel().getSelectedItem().getId());
        });

        handleVisibilityButton.setOnAction(actionEvent -> {
            model.setMessage("");
            if (list.getSelectionModel().getSelectedItem() == null) {
                model.setMessage("Selecione o espetaculo que pretende tornar visivel");
                return;
            }

            model.showVisible(list.getSelectionModel().getSelectedItem().getId());
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.MANAGE_SHOWS);
    }

    private void bindList() {
        list.prefWidthProperty().bind(pane.widthProperty().multiply(0.45));
        list.prefHeightProperty().bind(pane.heightProperty().multiply(0.75));
    }
}
