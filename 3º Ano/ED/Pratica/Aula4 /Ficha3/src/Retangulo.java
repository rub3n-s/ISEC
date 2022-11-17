public class Retangulo extends Figura{
    private float largura,comprimento;

    public Retangulo(float largura,float comprimento){
        this.comprimento= comprimento;
        this.largura = largura;
    }

    @Override
    float area() {
        return largura*comprimento;
    }
}
