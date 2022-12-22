package pt.isec.ed.ex3;

public class Triangulo extends Figura {
    public float base, altura;

    public Triangulo(float base, float altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    float area() { return (base * altura)/2; }
}
