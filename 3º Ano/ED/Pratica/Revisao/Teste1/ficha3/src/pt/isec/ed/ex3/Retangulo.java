package pt.isec.ed.ex3;

public class Retangulo extends Figura {
    private int comprimento, largura;

    public Retangulo(int comprimento, int largura) {
        this.comprimento = comprimento;
        this.largura = largura;
    }

    @Override
    float area() { return comprimento * largura; }
}
