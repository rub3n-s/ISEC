package pt.isec.pa.ex30.ui.gui;

import com.sun.javafx.font.CharToGlyphMapper;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Line;
import pt.isec.pa.ex30.model.Drawing;
import pt.isec.pa.ex30.model.DrawingManager;
import pt.isec.pa.ex30.model.Figure;
import pt.isec.pa.ex30.model.Oval;

public class DrawingToolBar extends ToolBar {
    private static final int TOGGLE_SIZE = 40;
    private static final int TOGGLE_IMG_SIZE = TOGGLE_SIZE - 10;

    DrawingManager drawing;
    Rectangle rectRandom;
    ToggleButton btnRed, btnGreen, btnBlue, btnRandom;
    ToggleButton btnLine, btnRect, btnOval;

    ColorPicker colorPicker;

    public DrawingToolBar(DrawingManager drawing) {
        this.drawing = drawing;

        createViews();
        registerHandlers();
        update();
    }

    private void createViews() {
        Rectangle rectR = new Rectangle(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);
        rectR.setFill(Color.color(1,0,0));

        Rectangle rectG = new Rectangle(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);
        rectG.setFill(Color.color(0,1,0));

        Rectangle rectB = new Rectangle(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);
        rectB.setFill(Color.color(0,0,1));

        rectRandom = new Rectangle(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);   // fill deste rect esta no update

        btnRed = new ToggleButton(null,rectR);  // ToggleButton(texto,Object rectangle)
        btnRed.setPrefSize(TOGGLE_SIZE,TOGGLE_SIZE);

        btnGreen = new ToggleButton(null,rectG);  // ToggleButton(texto,Object rectangle)
        btnGreen.setPrefSize(TOGGLE_SIZE,TOGGLE_SIZE);

        btnBlue = new ToggleButton(null,rectB);  // ToggleButton(texto,Object rectangle)
        btnBlue.setPrefSize(TOGGLE_SIZE,TOGGLE_SIZE);

        btnRandom = new ToggleButton("Random",rectRandom);
        btnRandom.setPrefHeight(TOGGLE_SIZE);

        colorPicker = new ColorPicker();
        colorPicker.setPrefHeight(TOGGLE_SIZE);

        Line shLine = new Line(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);
        shLine.setFill(Color.DEEPPINK);

        Rectangle shRect = new Rectangle(0,0,TOGGLE_IMG_SIZE, TOGGLE_IMG_SIZE);
        shRect.setFill(Color.BLACK);

        //Oval shOval = new Oval();
        //shOval.

        btnLine = new ToggleButton(null,shLine);
        btnLine.setPrefSize(TOGGLE_SIZE,TOGGLE_SIZE);

        btnRect = new ToggleButton(null,shRect);
        btnRect.setPrefSize(TOGGLE_SIZE,TOGGLE_SIZE);

        ToggleGroup colorsGroup = new ToggleGroup();
        ToggleGroup shapesGroup = new ToggleGroup();
        btnRed.setToggleGroup(colorsGroup);
        btnRandom.setToggleGroup(colorsGroup);
        btnLine.setToggleGroup(shapesGroup);
        btnRect.setToggleGroup(shapesGroup);

        this.getItems().addAll(btnRed,btnGreen,btnBlue,btnRandom,colorPicker,new Separator(),btnLine,btnRect);
    }

    private void registerHandlers() {
        drawing.addPropertyChangeListener(DrawingManager.PROP_TOOLS, evt -> update());

        btnRed.setOnAction(actionEvent -> {
            drawing.setRGB(1,0,0);
            //update();
        });

        btnGreen.setOnAction(actionEvent -> {
            drawing.setRGB(0,1,0);
            //update();
        });

        btnBlue.setOnAction(actionEvent -> {
            drawing.setRGB(0,0,1);
            //update();
        });

        btnRandom.setOnAction(actionEvent -> {
            drawing.setRGB(Math.random(), Math.random(), Math.random());
            //update();
        });

        colorPicker.setOnAction(actionEvent -> {
            Color color = colorPicker.getValue();
            drawing.setRGB(color.getRed(),color.getGreen(),color.getBlue());
            //update();
        });
        btnGreen.fire();

        btnLine.setOnAction(actionEvent -> drawing.setCurrentType(Figure.FigureType.LINE));
        btnRect.setOnAction(actionEvent -> drawing.setCurrentType(Figure.FigureType.RECTANGLE));
        //btnOval.setOnAction(actionEvent -> drawing.setCurrentType(Figure.FigureType.OVAL));
        btnLine.fire();
    }

    private void update() {
        Color color = Color.color(drawing.getR(),drawing.getG(),drawing.getB());
        rectRandom.setFill(color);
        colorPicker.setValue(color);

        // significa que o botao vermelho esta selecionado
        if (Color.color(1, 0, 0).equals(color))
            btnRed.setSelected(true);
        else if (Color.color(0, 1, 0).equals(color))
            btnGreen.setSelected(true);
        else if (Color.color(0, 0, 1).equals(color))
            btnBlue.setSelected(true);
        else
            btnRandom.setSelected(true);

        btnLine.setSelected(drawing.getCurrentType() == Figure.FigureType.LINE);
        btnRect.setSelected(drawing.getCurrentType() == Figure.FigureType.RECTANGLE);
        //btnOval.setSelected(drawing.getCurrentType() == Figure.FigureType.OVAL);
    }
}
