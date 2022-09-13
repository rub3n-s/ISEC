package jogoenforcado.modelo;

import jogoenforcado.dicionario.*;

import java.util.Random;

public class JogoEnforcadoModelo {
    private static final String ESCONDIDO = ".";
    private static final int TENTATIVAS = 15;

    private String palavra;
    private StringBuilder situacao;
    private StringBuilder usadas;

    private int tentativas, nAcertos;

    public JogoEnforcadoModelo() {
        inicia();
    }

    public void inicia() {
        //TODO: Buscar palavra ao dicionario
        //TODO: Preencher stringbuilder com ESCONDIDO com base no tam da palavra
        //TODO: init tentativas
        //JogoEnforcadoDicionario jogoEnforcadoDicionario;
        
        Random rnd = new Random();
        int index = rnd.nextInt(JogoEnforcadoDicionario.getNrPalavras());

        palavra = JogoEnforcadoDicionario.getPalavra(index).toUpperCase();
        nAcertos = 0;
        tentativas = 0;
        this.situacao = new StringBuilder(ESCONDIDO.repeat(palavra.length()));
        this.usadas = new StringBuilder();
    }

    public boolean concluido() {
        //TODO: situacao == palavra OU MAX tentativas excedeu
        if (palavra.equalsIgnoreCase(situacao.toString())) {
            System.out.printf("\nAcertou a palavra [%s] em [%d] tentativas!\n", palavra, tentativas);
            System.out.printf("Obteve [%d] acertos \n", nAcertos);
            return true;
        }
        else if (tentativas == TENTATIVAS) {
            System.out.printf("\nExcedeu o número de tentativas [%d] para a palavra [%s]!\n",TENTATIVAS, palavra);
            System.out.printf("Obteve [%d] acertos \n", nAcertos);
            return true;
        }

        return false;
    }

    public boolean setOpcao(String p) {
        if (palavra == null || concluido())
            return false;

        tentativas++;

        if (p.isBlank())
            return false;

        p = p.toUpperCase();

        if (p.length() > 1) {
            if (palavra.equals(p))
                situacao = new StringBuilder(palavra);
            return true;
        }

        //TODO: verificar se palavra tem 1 char
        char chOpcao = p.charAt(0);
        usadas.append(chOpcao);
        String inicial = situacao.toString();
        for (int i = 0; i < palavra.length(); i++) {
            if (palavra.charAt(i) == chOpcao)
                situacao.setCharAt(i,chOpcao);
        }

        if (!inicial.equalsIgnoreCase(situacao.toString()))
            nAcertos++;
        else
            System.out.println("\n[Errou] A letra " + p + " não pertence à palavra!");

        return true;        
    }

    public String getSituacao() {
        return situacao.toString();
    }

    public int getTentativas() {
        return tentativas;
    }

    public String getPalavra() {
        return palavra;
    }
}
