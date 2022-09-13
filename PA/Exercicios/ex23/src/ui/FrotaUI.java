package ui;

import PAInput.PAInput;
import frota.Frota;

public class FrotaUI {
    Frota frota;

    public FrotaUI(Frota frota) {
        this.frota = frota;
    }

    void addVeiculo() {
        System.out.println();
        
        String matricula;
        int ano, passageiros, carga;
        
        // garante que os inputs são inseridos corretamente
        do {
            matricula = PAInput.readString("Matricula: ",false);
            ano = PAInput.readInt("Ano: ");

            if (ano < 0 || ano > 2022)
                System.out.println("Ano deve estar entre 0 e 2022\n");
        } while(matricula.isEmpty() || ano < 0 || ano > 2022);

        switch (PAInput.chooseOption("Tipo de veiculo: ",
                "Ligeiro","Pesado","Carga")) {
            case 1:
                System.out.println();
                
                // add ligeiro de passageiros
                passageiros = PAInput.readInt("[MAX] Passageiros: ");

                // garante que existe um minimo de passageiros
                if (passageiros < 0)
                    passageiros = 1;
                
                // envia os parametros para a frota
                frota.addLigeiro(matricula,ano,passageiros);  

                break;
            case 2:
                System.out.println();

                // add pesado de passageiros
                passageiros = PAInput.readInt("[MAX] Passageiros: ");
                carga = PAInput.readInt("[MAX] Carga: ");

                // garante que existe um minimo de passageiros
                if (passageiros < 0)
                    passageiros = 1;
                if (carga < 0)
                    carga = 1;
                
                // envia os parametros para a frota
                frota.addPesado(matricula,ano,passageiros,carga);  

                break;
            case 3:
                System.out.println();

                // add veiculo de carga
                carga = PAInput.readInt("[MAX] Carga: ");

                // garante que existe um minimo de carga
                if (carga < 0)
                    carga = 1;
                
                // envia os parametros para a frota
                frota.addCarga(matricula,ano,carga);  
                break;
        }
    }

    void removeVeiculo() {
        String matricula = PAInput.readString("Matricula do veiculo a remover: ",false);
        boolean deleted = frota.removeVeiculo(matricula);
        if (!deleted)
            System.out.println("Veiculo não detetado");
        else
            System.out.println("Veiculo eliminado");
    }

    public void start() {
        while (true) {
            switch (PAInput.chooseOption("Frota de Veiculos: ",
                    "Add novo veiculo","Remove veiculo","Lista Frota","Sort Max Passageiros", 
                    "Sort Max Carga", "Sair")) {
                case 1:
                    addVeiculo();
                    break;
                case 2:
                    removeVeiculo();
                    break;
                case 3:
                    System.out.println(frota.toString());
                    break;
                case 4:
                    System.out.println(frota.sortedMaxPassageiros());
                    break;
                case 5:
                    System.out.println(frota.sortedMaxCarga());
                    break;
                case 6:
                    return;
            }
        }
    }
}
