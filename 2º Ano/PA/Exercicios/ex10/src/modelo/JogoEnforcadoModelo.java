package modelo;

import java.util.Random;
import java.util.Scanner;

import dicionario.*;

public class JogoEnforcadoModelo {
    private String palavra;
    private static int tentativas;
    private static final int MAX_TENTATIVAS = 10;
    private JogoEnforcadoDicionario dicionario;
    StringBuilder sb = new StringBuilder('_').;

    public JogoEnforcadoModelo() {
        Random rnd = new Random();
        palavra = dicionario.getPalavra(rnd.nextInt(dicionario.getNrPalavras()));
        System.out.printf("[PALAVRA] %s\n",palavra);
        tentativas = 0;
    }

    public void setOpcao(String op) {

    }

    public void situacao(String tenta) {
        if (palavra.contains(tenta)) {
            for (int i = 0; i < palavra.length(); i++) {
                if (tenta.equals(palavra[i])) {

                }
            }
        }
    }

    public boolean jogoTermina() {
        if (palavra.equals(sb.toString())) {
            System.out.printf("[COMPLETOU] Completou a palavra '%s' em %d tentativas",palavra,tentativas);
            return true;
        }

        if (tentativas < MAX_TENTATIVAS) {
            System.out.printf("Restam %d tentativas!\n", MAX_TENTATIVAS - tentativas);
            tentativas++; 
            return false;
        } 
        
        System.out.println("Terminou o jogo! Maximo de tentativas atingido!");
        return true;
    }
}
