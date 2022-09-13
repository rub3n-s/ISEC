package pt.isec.pa.ex30.ui.gui;

import javafx.application.Platform;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.stage.FileChooser;
import pt.isec.pa.ex30.model.DrawingManager;

import java.io.File;
import java.io.IOException;

public class AppMenu extends MenuBar {
    DrawingManager drawing;
    Menu mnFile;
    MenuItem miNew, miOpen, miSave, miExit;
    Menu mnEdit;
    MenuItem miUndo, miRedo;

    public AppMenu(DrawingManager drawingManager) {
        this.drawing = drawingManager;

        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        mnFile = new Menu("File");
            miNew = new MenuItem("_New");    // '_' antes acrescenta um comportamento extra: ao fazer alt+n faz a funcao do new
            //miNew.setMnemonicParsing(false);    // para prevenir o efeito do '_'
            miOpen = new MenuItem("_Open");
            miOpen.setAccelerator(new KeyCodeCombination(KeyCode.O, KeyCombination.CONTROL_DOWN));
            miSave = new MenuItem("_Save");
            miExit = new MenuItem("_Exit");
        mnFile.getItems().addAll(miNew, miOpen, miSave, miExit);

        mnEdit = new Menu("Edit");
            miUndo = new MenuItem("_Undo");
            miRedo = new MenuItem("_Redo");
        mnEdit.getItems().addAll(miUndo, miRedo);

        this.getMenus().addAll(mnFile, mnEdit);
        //this.setUseSystemMenuBar(true);
    }

    private void registerHandlers() {
        //TODO: init
        miNew.setOnAction(actionEvent -> drawing.clearAll());

        miOpen.setOnAction(actionEvent -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("File open...");
            fileChooser.setInitialDirectory(new File("."));
            fileChooser.getExtensionFilters().addAll(
                    new FileChooser.ExtensionFilter("Drawing (.*dat)", "*.dat"),
                    new FileChooser.ExtensionFilter("All", "*.*")
            );
            File hFile = fileChooser.showOpenDialog(this.getScene().getWindow());
            if (hFile != null) {
                try {
                    drawing.load(hFile);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        miSave.setOnAction(actionEvent -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("File save...");
            fileChooser.setInitialDirectory(new File("."));
            fileChooser.getExtensionFilters().addAll(
                    new FileChooser.ExtensionFilter("Drawing (.*dat)", "*.dat"),
                    new FileChooser.ExtensionFilter("All", "*.*")
            );
            File hFile = fileChooser.showSaveDialog(this.getScene().getWindow());
            if (hFile != null) {
                try {
                    drawing.save(hFile);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        miExit.setOnAction(actionEvent -> Platform.exit());

        miUndo.setOnAction(actionEvent -> {
            //TODO: ...
        });

        miRedo.setOnAction(actionEvent -> {
            //TODO: ...
        });
    }

    private void update() {
        //TODO: drawing.hasUndo
        miUndo.setDisable(true);
    }
}
