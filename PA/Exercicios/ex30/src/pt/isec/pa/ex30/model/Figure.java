package pt.isec.pa.ex30.model;

public abstract class Figure implements Cloneable{
    public enum FigureType {
        LINE, RECTANGLE, OVAL;

        public Figure createFigure() {
            return switch (this) {
                case LINE -> new Line();
                case RECTANGLE -> new Rectangle();
                case OVAL -> new Oval();
            };
        }
    }

    double x1,y1;
    double x2,y2;
    double r,g,b;

    public void setP1(double x, double y) {
        this.x1 = x;
        this.y1 = y;
    }
    public void setP2(double x, double y) {
        this.x2 = x;
        this.y2 = y;
    }

    public void setRGB(double r,double g, double b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public double getX1() {
        return x1;
    }

    public double getY1() {
        return y1;
    }

    public double getX2() {
        return x2;
    }

    public double getY2() {
        return y2;
    }

    public double getR() {
        return r;
    }

    public double getG() {
        return g;
    }

    public double getB() {
        return b;
    }

    public double getCX() {
        return (x1+x2)/2.0;
    }
    public double getCY() {
        return (y1+y2)/2.0;
    }
    public double getWidth() {
        return Math.abs(x1-x2);
    }
    public double getHeight() {
        return Math.abs(y1-y2);
    }

    public void setPropsCentered(double cx, double cy, double border_px, double border_py) {
        double w = 2*Math.abs(border_px-cx);
        double h = 2*Math.abs(border_py-cy);
        x1 = cx-w/2.0;
        y1 = cy-h/2.0;
        x2 = cx+w/2.0;
        y2 = cy+h/2.0;
    }

    public abstract FigureType getType();


    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    @Override
    public String toString() {
        return getClass().getSimpleName() + ": (" + getX1() + ", " + getY1() + "), " + "(" + getX2() + ", " + getY2() + ")\n";
    }
}
