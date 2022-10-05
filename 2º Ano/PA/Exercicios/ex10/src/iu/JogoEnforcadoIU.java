package iu;

import java.util.Scanner;

import modelo.*;

public class JogoEnforcadoIU {
    JogoEnforcadoModelo jogo;
    
    public JogoEnforcadoIU(JogoEnforcadoModelo jogo) {
        this.jogo = jogo;
    }

    public void jogar() {
        Scanner sc = new Scanner(System.in);

        // char/string que guardará a tentativa do user
        String opcao = new String();
        
        do {
            // obter a opcao
            opcao = sc.next();

            // retirar os espaços
            opcao.trim();

            // enviar a opção para o modelo avaliar
            jogo.setOpcao(opcao);
        } while(!jogo.jogoTermina());
    }
}
