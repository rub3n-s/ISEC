package pt.isec.pa.ex30.model;

import java.util.ArrayList;
import java.util.List;

public class Drawing {
    Figure.FigureType currentType;
    double r,g,b;
    ArrayList<Figure> figures;
    Figure current;

    public Drawing() {
        figures = new ArrayList<>();
        currentType = Figure.FigureType.LINE;
        r=g=b=0;
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
    public void setRGB(double r,double g, double b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public Figure.FigureType getCurrentType() {
        return currentType;
    }

    public void setCurrentType(Figure.FigureType currentType) {
        this.currentType = currentType;
    }

    public void createFigure(double x, double y) {
        current = currentType.createFigure();
        current.setP1(x,y);
        current.setP2(x,y);
        current.setRGB(r,g,b);
    }

    public void updateCurrentFigure(double x, double y) {
        if(current==null)
            return;
        current.setP2(x,y);
    }

    public void finishCurrentFigure(double x,double y) {
        if(current==null)
            return;
        current.setP2(x,y);
        figures.add(current);
        current = null;
    }

    public Figure getCurrentFigure() {
        return current;
    }

    public List<Figure> getList() {
        List<Figure> retLst = new ArrayList<>();
        for(Figure fig : figures) {
            try {
                retLst.add((Figure)fig.clone());
            } catch (CloneNotSupportedException e) {
            }
        }
        return retLst;
    }

    public void clearAll() {
        figures.clear();
    }

    public void removeLast() {
        if (figures.size()>0)
            figures.remove(figures.size()-1);
    }

    public void remove(int index) {
        if (index >= 0 && index < figures.size())
            figures.remove(index);
    }
}
