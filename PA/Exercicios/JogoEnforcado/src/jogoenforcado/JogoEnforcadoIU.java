package jogoenforcado;

import java.util.Scanner;

public class JogoEnforcadoIU {
    public JogoEnforcadoModelo jogoEnforcadoModelo;

    public JogoEnforcadoIU(JogoEnforcadoModelo jogoEnforcadoModelo) {
            this.jogoEnforcadoModelo = jogoEnforcadoModelo;
    }
    
    public void jogar() {
        //TODO: Arranjar um input
        Scanner sc = new Scanner(System.in);
        String opcao;

        while(jogoEnforcadoModelo.concluido()) {
            //TODO: Mostrar palavra
            //TODO: Mostrar palavras usadas
            //TODO: Pedir palavra/char
            //TODO: Enviar dados para o nosso modelo
            
            System.out.printf("\n\nA palavra tem [%d] letras, qual o palpite: ", jogoEnforcadoModelo.getNrLetras());
            opcao = sc.nextLine();

            jogoEnforcadoModelo.setOpcao(opcao);
        }
    }
}
