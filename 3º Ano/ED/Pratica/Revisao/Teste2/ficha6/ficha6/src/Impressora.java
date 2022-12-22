import java.util.PriorityQueue;

public class Impressora {
    String nome, marca, modelo;
    int porto, versao, driver;
    PriorityQueue<Trabalho> queue;
    
    public Impressora(String nome, String marca, String modelo, int versao, int driver) {
        this.nome = nome;
        this.marca = marca;
        this.modelo = modelo;
        this.versao = versao;
        this.driver = driver;

        queue = new PriorityQueue<Trabalho>(
            new Comparator<Trabalho>() {
                public int compare(Trabalho a, Trabalho b) {
                    return a.getNumPaginas() - b.getNumPaginas();
                }
            }
        );
    }

    public String getNome() {
        return nome;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getVersao() {
        return versao;
    }

    public int getDriver() {
        return driver;
    }

    public int getPorto() {
        return porto;
    }

    public void enviaTrabalho(Trabalho t) {
        queue.add(t);
    }

    public boolean temProximoTrabalho() {
        return !queue.isEmpty();
    }

    public Trabalho proximoTrabalho() {
        return queue.poll();
    }

    public void imprime(Trabalho t) {
        while (temProximoTrabalho())
            System.out.println(proximoTrabalho().toString());
    }

    public int getNumTrabalhos() { return queue.size(); }
}
