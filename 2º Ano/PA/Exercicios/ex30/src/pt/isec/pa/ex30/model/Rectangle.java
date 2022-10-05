package pt.isec.pa.ex30.model;

public class Rectangle extends Figure {
    @Override
    public FigureType getType() {
        return FigureType.RECTANGLE;
    }

    @Override
    public double getX1() {
        return x1 < x2 ? x1 : x2;
    }

    @Override
    public double getX2() {
        return x1 < x2 ? x2 : x1;
    }

    @Override
    public double getY1() {
        return y1 < y2 ? y1 : y2;
    }

    @Override
    public double getY2() {
        return y1 < y2 ? y2 : y1;
    }
}
