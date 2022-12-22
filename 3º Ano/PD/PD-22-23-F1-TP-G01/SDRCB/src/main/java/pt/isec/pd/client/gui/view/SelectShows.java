package pt.isec.pd.client.gui.view;

import javafx.collections.FXCollections;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.layout.AnchorPane;
import javafx.util.Pair;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.ShowsResponse;
import pt.isec.pd.shared_data.Show;

import java.util.List;

public class SelectShows {
    public AnchorPane pane;
    public ListView<Show> list;
    public Button cancelButton;
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

        model.addPropertyChangeListener(ClientAction.SELECT_SHOWS.toString(), evt -> {
            try {
                ShowsResponse showsResponse = (ShowsResponse) model.getResponse();
                list.setItems(FXCollections.observableList(showsResponse.getShows()));
            } catch (ClassCastException ignored) {}
        });

        list.setOnMouseClicked(actionEvent -> {
            if (list.getSelectionModel().getSelectedItem() != null) {
                model.seatsTransition(list.getSelectionModel().getSelectedItem().getId());
            }
        });

        cancelButton.setOnAction(actionEvent -> {
            model.selectShowsTransition();
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.SELECT_SHOWS);
    }
}
