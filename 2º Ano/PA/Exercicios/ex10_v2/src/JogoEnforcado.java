import jogoenforcado.dicionario.*;
import jogoenforcado.iu.*;
import jogoenforcado.modelo.*;

public class JogoEnforcado {
    public static void main(String args[]) { 
        JogoEnforcadoModelo jogo = new JogoEnforcadoModelo(); 
        JogoEnforcadoIU jogoIU = new JogoEnforcadoIU(jogo); 
        jogoIU.jogar(); 
    }
}
