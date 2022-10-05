package pt.isec.pa.ex29_v2.models;

public class Figura {
    double x1, y1;  // canto superior esquerdo
    double x2, y2;  // canto inferior direito
    double r,g,b;

    public Figura() {
        x1 = y1 = 50;
        x2 = 300;
        y2 = 200;
        r = 0.6;
        g = 0.3;
        b = 0.0;
    }

    public void setP1(double x, double y) {   // definir o ponto superior esquerdo
        x1 = x;
        y1 = y;
    }

    public void setP2(double x, double y) {   // definir o ponto inferior direito
        x2 = x;
        y2 = y;
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

    public void setRGB(double r, double g, double b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public double getMinX() {   // para saber qual é o canto superior esquerdo
        return Math.min(x1, x2);
    }

    public double getMinY() {   // para saber qual é o canto superior esquerdo
        return Math.min(y1, y2);
    }

    public double getWidth() {
        return Math.abs(x1 - x2);
    }

    public double getHeight() {
        return Math.abs(y1 - y2);
    }
}
