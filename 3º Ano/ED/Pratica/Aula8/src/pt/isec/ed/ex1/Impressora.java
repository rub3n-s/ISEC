package pt.isec.ed.ex1;

import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;

public class Impressora {
    private String nome;
    private int porto;
    private String marca;
    private String modelo;
    private String driver;
    private String versao;
    PriorityQueue<Trabalho> queue;

    public Impressora(String nome, int porto, String marca, String modelo, String driver, String versao) {
        this.nome = nome;
        this.porto = porto;
        this.marca = marca;
        this.modelo = modelo;
        this.driver = driver;
        this.versao = versao;
        this.queue = new PriorityQueue<Trabalho>(
            new Comparator<Trabalho>() {
                public int compare(Trabalho a, Trabalho b) {
                    return a.getNumPaginas() - b.getNumPaginas();
                }
        });
    }
    
    public String getNome() { return nome; }

    public String getMarca() { return marca; }

    public void enviaTrabalho(Trabalho trabalho) { queue.add(trabalho); }

    public boolean temProximoTrabalho() {
        return !queue.isEmpty();
    }

    public Trabalho proximoTrabalho() {
        return queue.poll();
    }

    public int getNumTrabalhos() { return queue.size(); }

    public void imprime()
    {
        while(temProximoTrabalho()) {
            System.out.println(proximoTrabalho().toString());
        }
    }

    public void show() { 
        System.out.println(" " + nome + " " + marca + " " + porto);
    }
}