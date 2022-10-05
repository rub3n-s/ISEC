package dicionario;

public class JogoEnforcadoDicionario {
    private static final String [] palavras = {"AMANHA","ARQUIMEDES","LEAO","TIGRE","ZEBRA","PRATO",
        "CASTANHO","LARANJA","ERVILHA","LONTRA","LASTRO","ORANGOTANGO","DISCIPLINA","PROGRAMACAO",
        "BATATA","PALHACO","CEREBRO","ATUM","PORTUGAL","SILVESTRE","ANIMAL","IRRACIONAL","MATEMATICA",
        "DISCRETO","EFICAZ","EFICIENTE","MARAVILHA","SINOPSE","DISPOSITIVO","LINEAR","LIMAO","LAMPADA",
        "ORELHA","BUFALO","SAPATO","LAGOSTA","ARRISCADO","RISCADO","CARNAVAL","ARROJADO","LIBERTADO",
        "SIMPLES","COMPLEXO","AGRAFADOR","MONITOR","TECLADO","CHAVE","RELOGIO","LENCO","JANELA","CORDA",
        "VIOLA","GUITARRA","PONTEIRO","ARGUENTE","SAGAZ","ERRONEO","INSTITUTO","SUPERIOR","ENGENHARIA",
        "DEPARTAMENTO","INFORMATICA","SISTEMA","CONVOCATORIA","PRESIDENTE","FEVEREIRO","AUMENTO","SALARIO",
        "DINHEIRO","IMEDIATO","FLAMINGO","RINOCERONTE","HIPOPOTAMO","BACALHAU","PARGO","SARDINHA","CARACOL",
        "INSECTO","VOADOR","LARANJA","ASPERSAO","EXTINTO","EXTERIOR","AMBIVALENTE"};

    private JogoEnforcadoDicionario() {}

    public static int getNrPalavras() {
        return palavras.length;
    }

    public static String getPalavra(int index) {
        if (index<0 || index>=palavras.length)
            return null;
        return palavras[index];
    }
}
