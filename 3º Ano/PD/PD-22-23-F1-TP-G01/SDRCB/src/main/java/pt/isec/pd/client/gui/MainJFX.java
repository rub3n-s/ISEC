package pt.isec.pd.client.gui;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Popup;
import javafx.stage.Stage;
import javafx.stage.Window;
import javafx.stage.WindowEvent;
import pt.isec.pd.client.Main;
import pt.isec.pd.client.gui.view.LoginForm;
import pt.isec.pd.client.model.ModelManager;
import pt.isec.pd.client.model.data.Client;
import pt.isec.pd.server.data.Server;
import pt.isec.pd.shared_data.ServerAddress;
import pt.isec.pd.utils.Log;

import java.io.IOException;
import java.net.URL;
import java.util.List;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

public class MainJFX extends Application {
    private final Log LOG = Log.getLogger(Client.class);
    ModelManager model;

    @Override
    public void start(Stage stage) {
        //Receive arguments from main
        Parameters params = getParameters();
        List<String> arguments = params.getRaw();
        ServerAddress udpConn = new ServerAddress(arguments.get(0),Integer.parseInt(arguments.get(1)));

        model = new ModelManager(udpConn);

        BorderPane root = new RootPane(model);
        Scene scene = new Scene(root,640,380);
        stage.setScene(scene);
        stage.setTitle("PD-meta1");
        stage.sizeToScene();
        stage.show();

        stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent windowEvent) {
                model.disconnect();
            }
        });
    }
}
