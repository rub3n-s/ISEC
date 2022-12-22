package pt.isec.ed.ex1;

public class Trabalho {
    private String nomeFicheiro;
    private int paginaInicial;
    private int paginaFinal;
    
    public Trabalho(String nomeFicheiro, int paginaInicial, int paginaFinal) {
        this.nomeFicheiro = nomeFicheiro;
        this.paginaInicial = paginaInicial;
        this.paginaFinal = paginaFinal;
    }

    public int getNumPaginas() { return paginaFinal - paginaInicial; }

    @Override
    public String toString() {
        return nomeFicheiro + ", " + getNumPaginas() + " paginas";
    }
}
