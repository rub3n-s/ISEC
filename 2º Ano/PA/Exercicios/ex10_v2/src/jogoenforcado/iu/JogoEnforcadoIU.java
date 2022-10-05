package jogoenforcado.iu;

import jogoenforcado.modelo.*;

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

        // Mostra o estado inicial da situacao
        //System.out.println(jogoEnforcadoModelo.getSituacao());

        while(!jogoEnforcadoModelo.concluido()) {
            //TODO: Mostrar palavra
            //TODO: Mostrar palavras usadas
            //TODO: Pedir palavra/char
            //TODO: Enviar dados para o nosso modelo

            System.out.printf("\nTentativa [%d]\n",jogoEnforcadoModelo.getTentativas()+1);
            // Mostra o estado atual da situacao
            System.out.println(jogoEnforcadoModelo.getSituacao());

            System.out.printf("\nA palavra tem [%d] letras, qual o palpite: ", jogoEnforcadoModelo.getPalavra().length());
            opcao = sc.next();
            opcao = opcao.trim(); // retira espaços antes da string e depois
            jogoEnforcadoModelo.setOpcao(opcao);

            
        }
    }
}
