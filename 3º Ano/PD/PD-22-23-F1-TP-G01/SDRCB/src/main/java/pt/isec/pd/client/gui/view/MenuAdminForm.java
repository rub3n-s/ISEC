package pt.isec.pd.client.gui.view;

import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.fsm.State;

public class MenuAdminForm {
    public AnchorPane pane;
    public Button editButton;
    public Button showsButton;
    public Button insertShowsButton;
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

        editButton.setOnAction(actionEvent -> {
            model.editTransition();
        });

        showsButton.setOnAction(actionEvent -> {
            model.showsTransition();
        });

        insertShowsButton.setOnAction(actionEvent -> {
            model.insertShowsTransition();
        });

    }
    private void update() { pane.setVisible(model != null && model.getState() == State.MENU_ADMIN); }
}
