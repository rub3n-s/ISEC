public class Impressora {
    private String nome;
    private int porto;
    private String marca;
    private String modelo;
    private String driver;
    private String versao;

    public Impressora(String nome, int porto, String marca, String modelo, String driver, String versao) {
        this.nome = nome;
        this.porto = porto;
        this.marca = marca;
        this.modelo = modelo;
        this.driver = driver;
        this.versao = versao;
    }
    
    public String getNome() { return nome; }

    public String getMarca() { return marca; }

    public void show() { 
        System.out.println(" " + nome + " " + marca + " " + porto);
    }
}