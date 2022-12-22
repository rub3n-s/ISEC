package pt.isec.pd.client.gui.view;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.fsm.State;
import pt.isec.pd.shared_data.Responses.ConsultShowsFilterResponse;
import pt.isec.pd.shared_data.Show;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

public class ShowsForm {
    public ListView<Show> list;
    public AnchorPane pane;
    public CheckBox descricaoCheck; // done
    public CheckBox tipoCheck; // done
    public CheckBox dataCheck; // done
    public CheckBox duracaoCheck; // done
    public CheckBox localCheck; // done
    public CheckBox localidadeCheck; // done
    public CheckBox paisCheck; // done
    public CheckBox classCheck;
    public TextField descricaoField;
    public TextField tipoField;
    public DatePicker datField;
    public TextField duracaoField;
    public TextField localField;
    public TextField localidadeField;
    public TextField classField;
    public TextField paisField;
    public Button procurarButton;
    public Button retrocederButton;

    private ModelManager model;

    public void setModel(ModelManager model) {
        this.model = model;

        registerHandlers();
        update();
    }
    private void registerHandlers() {
        model.addPropertyChangeListener(ModelManager.PROP_STATE, evt -> {
            update();
            bindList();
        });

        model.addPropertyChangeListener(ClientAction.CONSULT_SHOWS_VISIBLE.toString(), evt -> {
            ConsultShowsFilterResponse response = (ConsultShowsFilterResponse) model.getResponse();
            if (response.getShows() != null)
                list.setItems(FXCollections.observableList(response.getShows()));
        });

        retrocederButton.setOnAction(actionEvent -> {
            model.showsTransition();
        });

        descricaoCheck.setOnAction(actionEvent -> {
            descricaoField.setDisable(!descricaoCheck.isSelected());
        });

        tipoCheck.setOnAction(actionEvent -> {
            tipoField.setDisable(!tipoCheck.isSelected());
        });

        dataCheck.setOnAction(actionEvent -> {
            datField.setDisable(!dataCheck.isSelected());
        });

        duracaoCheck.setOnAction(actionEvent -> {
            duracaoField.setDisable(!duracaoCheck.isSelected());
        });


        localCheck.setOnAction(actionEvent -> {
            localField.setDisable(!localCheck.isSelected());
        });

        localidadeCheck.setOnAction(actionEvent -> {
            localidadeField.setDisable(!localidadeCheck.isSelected());
        });

        localidadeCheck.setOnAction(actionEvent -> {
            localidadeField.setDisable(!localidadeCheck.isSelected());
        });

        paisCheck.setOnAction(actionEvent -> {
            paisField.setDisable(!paisCheck.isSelected());
        });

        classCheck.setOnAction(actionEvent -> {
            classField.setDisable(!classCheck.isSelected());
        });
        
        list.setOnMouseClicked(actionEvent -> {
            list.getSelectionModel();
        });

        procurarButton.setOnAction(actionEvent -> {
            HashMap<String,String> filters = new HashMap<>();

            if (descricaoCheck.isSelected() && !descricaoField.getText().isEmpty()) {
                filters.put("descricao",descricaoField.getText());
            }
            if (tipoCheck.isSelected() && !tipoField.getText().isEmpty()) {
                filters.put("tipo",tipoField.getText());
            }
            if (dataCheck.isSelected() && !datField.getEditor().getText().isEmpty()) {
                try {
                    DateFormat dfFrom = new SimpleDateFormat("dd/MM/yyyy");
                    Date inputDate = dfFrom.parse(datField.getEditor().getText());
                    DateFormat dfTo = new SimpleDateFormat("yyyy-MM-dd");
                    String outputDate = dfTo.format(inputDate);
                    filters.put("data_hora",outputDate);
                } catch (ParseException e) {
                    e.printStackTrace();
                }
            }
            if (duracaoCheck.isSelected() && !duracaoField.getText().isEmpty()) {
                filters.put("duracao",duracaoField.getText());
            }
            if (localCheck.isSelected() && !localField.getText().isEmpty()) {
                filters.put("local",localField.getText());
            }
            if (localidadeCheck.isSelected() && !localidadeField.getText().isEmpty()) {
                filters.put("localidade",localidadeField.getText());
            }
            if (paisCheck.isSelected() && !paisField.getText().isEmpty()) {
                filters.put("pais",paisField.getText());
            }
            if (classCheck.isSelected() && !classField.getText().isEmpty()) {
                filters.put("classificacao_etaria",classField.getText());
            }

            model.consultShows(filters);
        });

        list.setOnMouseClicked(actionEvent -> {
            if (list.getSelectionModel().getSelectedItem() != null) {
                model.seatsTransition(list.getSelectionModel().getSelectedItem().getId());
            }
        });
    }

    private void update() {
        pane.setVisible(model != null && model.getState() == State.SHOWS);
    }

    private void bindList() {
        list.prefWidthProperty().bind(pane.widthProperty().multiply(0.5));
        list.prefHeightProperty().bind(pane.heightProperty().multiply(0.75));
    }
}
