package veiculo;

import interfaces.IMaxLoad;

public class Carga extends Veiculo implements IMaxLoad {
    private int max_carga;

    public Carga(String matricula, int ano, int max_carga) {
        super(matricula, ano);
        this.max_carga = max_carga;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n\n* Veiculo Pesado *");
        sb.append("\nMatricula: " + this.getMatricula());
        sb.append("\nAno: " + this.getAno());
        sb.append("\nMax Carga: " + this.max_carga);
        return sb.toString();
    }

    @Override
    public int getMaxWeight() {
        return max_carga;
    }
}
