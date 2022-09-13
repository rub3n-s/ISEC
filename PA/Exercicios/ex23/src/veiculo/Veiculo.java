package veiculo;

import interfaces.*;

public class Veiculo {
    private String matricula;
    private int ano;

    public Veiculo(String matricula, int ano) {
        this.matricula = matricula;
        this.ano = ano;
    }

    public String getMatricula() {
        return matricula;
    }

    public int getAno() {
        return ano;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Matricula: " + this.matricula);
        sb.append("\nAno: " + this.ano);
        return sb.toString();
    }

    @Override
    public int getNumberPassengers() {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public int getMaxWeight() {
        // TODO Auto-generated method stub
        return 0;
    }
}