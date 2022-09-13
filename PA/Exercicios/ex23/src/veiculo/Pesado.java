package veiculo;

import interfaces.IMaxLoad;
import interfaces.IPassengers;

public class Pesado extends Veiculo implements IMaxLoad, IPassengers{
    private int max_passageiros;
    private int max_carga;

    public Pesado(String matricula, int ano, int max_passageiros, int max_carga) {
        super(matricula, ano);
        this.max_passageiros = max_passageiros;
        this.max_carga = max_carga;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n\n* Veiculo Pesado *");
        sb.append("\nMatricula: " + this.getMatricula());
        sb.append("\nAno: " + this.getAno());
        sb.append("\nMax Lugares: " + this.max_passageiros);
        sb.append("\nMax Carga: " + this.max_carga);
        return sb.toString();
    }

    @Override
    public int getNumberPassengers() {
        return max_passageiros;
    }

    @Override
    public int getMaxWeight() {
        return max_carga;
    }
}
