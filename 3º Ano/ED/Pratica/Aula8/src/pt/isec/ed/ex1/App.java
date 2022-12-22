package pt.isec.ed.ex1;

public class App {
    public static void main(String[] args) throws Exception {
        // Exercicio 1
        Impressora a = new Impressora("a", 1, "a","a","a","a");
        Impressora b = new Impressora("b", 1, "b","b","b","b");
        Impressora c = new Impressora("c", 1, "c","c","c","c");

        GestorImpressoras gestorImpressoras = new GestorImpressoras();

        // Exercicio 2
        // a)
        Trabalho d = new Trabalho("d",1,2);
        Trabalho e = new Trabalho("e",1,23);
        Trabalho f = new Trabalho("f",12,40);

        a.enviaTrabalho(d);
        a.enviaTrabalho(e);
        a.enviaTrabalho(f);

        a.imprime();

        // b)
        gestorImpressoras.acrescentaImpressora(a);
        gestorImpressoras.acrescentaImpressora(b);
        gestorImpressoras.acrescentaImpressora(c);

        Trabalho t1 = new Trabalho("T1",12,22);
        Trabalho t2 = new Trabalho("T2",10,30);
        System.out.println("Fila de Espera: ");
        gestorImpressoras.mostraFila();

        System.out.println("Fila de espera com T1: ");
        gestorImpressoras.imprime(t1);
        gestorImpressoras.mostraFila();

        System.out.println("Fila de espera com T1 e T2: ");
        gestorImpressoras.imprime(t2);
        gestorImpressoras.mostraFila();
    }
}
