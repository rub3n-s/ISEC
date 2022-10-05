package pt.isec.pa.ex29_v2.ui.gui;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Rectangle;
import pt.isec.pa.ex29_v2.models.Figura;

public class RootPane extends Pane {
    Figura figura;

    Rectangle rectangle;
    Ellipse ellipse;

    public RootPane(Figura figura) {
        this.figura = figura;

        createViews();
        registerHandlers();
        update();
    }

    //  1) criar o retangulo
    private void createViews() {
        rectangle = new Rectangle();
        rectangle.setStrokeWidth(2);
        rectangle.setStroke(Color.BLUE);
        rectangle.setFill(null);    // tirar o fundo do retangulo

        ellipse = new Ellipse();
        ellipse.setStrokeWidth(2);
        ellipse.setStroke(Color.GREEN);
        ellipse.setFill(null);    // tirar o fundo do retangulo

        getChildren().addAll(rectangle);
        getChildren().addAll(ellipse);
    }

    //  3) Implementar os eventos para os clicks
    private void registerHandlers() {
        /*rectangle.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> {
            figura.setRGB(Math.random(), Math.random(), Math.random());
            update();
        }); */

        this.setOnMousePressed(mouseEvent -> {
            figura.setP1(mouseEvent.getX(),mouseEvent.getY());
            figura.setP2(mouseEvent.getX(),mouseEvent.getY());
            figura.setRGB(Math.random(), Math.random(), Math.random());
            update();
            System.out.println("PRESSED");
        });

        this.setOnMouseDragged(mouseEvent -> {
            figura.setP2(mouseEvent.getX(),mouseEvent.getY());
            update();
            System.out.println("DRAGGED");
        });

        this.setOnMouseReleased(mouseEvent -> {
            figura.setP2(mouseEvent.getX(),mouseEvent.getY());
            update();
            System.out.println("RELEASED");
        });
    }

    //  2) definir os pontos e cor do rectangulo
    private void update() {
        rectangle.setX(figura.getMinX());
        rectangle.setY(figura.getMinY());
        rectangle.setWidth(figura.getWidth());
        rectangle.setHeight(figura.getHeight());
        //rectangle.setFill(Color.color(figura.getR(),figura.getG(),figura.getB()));

        ellipse.setRadiusX(figura.getX2());
        ellipse.setRadiusY(figura.getY1());
        ellipse.setCenterX(figura.getWidth()/2);
        ellipse.setCenterY(figura.getHeight()/2);
    }
}
