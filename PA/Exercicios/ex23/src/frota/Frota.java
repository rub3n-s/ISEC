package frota;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

import veiculo.*;
import comparators.*;
import interfaces.IMaxLoad;

public class Frota {
    Set<Veiculo> frota;

    public Frota() {
        frota = new HashSet<>();
    }

    public void addLigeiro(String matricula, int ano, int passageiros) {
        Veiculo v = new Ligeiro(matricula, ano, passageiros);
        frota.add(v);
    }

    public void addPesado(String matricula, int ano, int passageiros, int carga) {
        Veiculo v = new Pesado(matricula, ano, passageiros, carga);
        frota.add(v);
    }

    public void addCarga(String matricula, int ano, int carga) {
        Veiculo v = new Carga(matricula, ano, carga);
        frota.add(v);
    }

    public boolean removeVeiculo(String matricula) {
        for (var v : frota) {
            if (v.getMatricula().equals(matricula)) {
                frota.remove(v);
                return true;    
            }
        }
        return false;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("\n======== Listagem da frota ========\n\n");
        for (var v : frota)
            sb.append(v.toString());
        sb.append("\n");
        return sb.toString();
    }

    public String sortedMaxPassageiros() {
        StringBuilder sb = new StringBuilder("\n======== Listagem da frota (Ordenada Max Passageiros) ========\n\n");
        ArrayList<Veiculo> ordenada = new ArrayList<>(frota);

        // inserir veiculos numa coleção ordenada
        //Collections.sort(ordenada, new WeigthComparator());
        
        // imprimir lista ordenada
        sb.append(ordenada.toString()+"\n");

        return sb.toString();
    }

    public String sortedMaxCarga() {
        StringBuilder sb = new StringBuilder("\n======== Listagem da frota (Ordenada Max Carga) ========\n");
        ArrayList<Veiculo> ordenada = new ArrayList<>(frota);

        // inserir veiculos numa coleção ordenada
        Collections.sort(ordenada, new LoadComparator());
        
        // imprimir lista ordenada
        sb.append(ordenada.toString()+"\n");

        return sb.toString();
    }
}
