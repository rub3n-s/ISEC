package jogoenforcado;

import java.util.Random;

public class JogoEnforcadoModelo {
    private static final char ESCONDIDO = '_';
    private static final int TENTATIVAS = 15;

    private String palavra;
    private StringBuilder situacao;

    private int tentativas;

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
        
        palavra = JogoEnforcadoDicionario.getPalavra(index);
        
        tentativas = 0;

        //situacao = new StringBuilder(ESCONDIDO.repeat());
        for (int i = 0; i < palavra.length(); i++)
            situacao.append(ESCONDIDO);
    }

    public boolean concluido() {
        //TODO: situacao == palavra OU MAX tentativas excedeu
        if (palavra.equals(situacao.toString())) {
            System.out.printf("Acertou em [%d] tentativas!", tentativas);
            return false;
        }
        else if (tentativas == TENTATIVAS) {
            System.out.println("Excedeu o número de tentativas!");
            return false;
        }

        return true;
    }

    public void setOpcao(String p) {
        // imprimir o estado atual de situacao
        System.out.println(situacao);

        //TODO: verificar se palavra tem 1 char
        if (palavra.contains(p)){
            for (int i = 0; i < palavra.length(); i++)
                if (palavra.indexOf(p, i) != -1)
                    situacao.insert(i, p);

            System.out.printf("Acertou na letra [%c]\n", p);
        }        
        //TODO: else ...
        else {
            System.out.println("Errou! Tente novamente!");
        }

        tentativas++;
    }

    public int getNrLetras() {
        return palavra.length();
    }
}
