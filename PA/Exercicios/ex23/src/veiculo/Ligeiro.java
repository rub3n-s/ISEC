package veiculo;

import interfaces.IMaxLoad;

// implementar interfaces em cada classe

public class Ligeiro extends Veiculo implements IMaxLoad {
    private int max_passageiros;

    public Ligeiro(String matricula, int ano, int passageiros) {
        super(matricula, ano);
        this.max_passageiros = passageiros;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n\n* Veiculo Ligeiro *");
        sb.append("\nMatricula: " + this.getMatricula());
        sb.append("\nAno: " + this.getAno());
        sb.append("\nMax Lugares: " + this.max_passageiros);
        return sb.toString();
    }

    @Override
    public int getNumberPassengers() {
        return max_passageiros;
    }
}
