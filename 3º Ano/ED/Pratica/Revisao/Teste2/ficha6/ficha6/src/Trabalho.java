public class Trabalho {
    String ficheiro;
    int paginaInicial, paginaFinal;
    
    public Trabalho(String ficheiro, int paginaInicial, int paginaFinal) {
        this.ficheiro = ficheiro;
        this.paginaInicial = paginaInicial;
        this.paginaFinal = paginaFinal;
    }

    public int getNumPaginas() { return paginaFinal - paginaInicial; }

    @Override
    public String toString() {
        return "Trabalho: " + ficheiro + ", " + getNumPaginas() + " paginas";
    }

    
}
