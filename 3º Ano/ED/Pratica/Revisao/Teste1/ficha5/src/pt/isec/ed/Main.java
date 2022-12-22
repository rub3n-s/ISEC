package pt.isec.ed;

import pt.isec.ed.ex3.Pilha;

import java.util.*;

public class Main {
    // Exercicio 1
    public static <T> void myFill(List<? super T> list, T value) {
        ListIterator it = list.listIterator();
        while(it.hasNext()) {
            it.next();
            it.set(value);
        }
    }

    // Exercicio 2
    public static <T> void imprimeInverso(List<? super T> list) {
        // inicializar o iterador no fim, para que percorra no sentido inverso
        ListIterator it = list.listIterator(list.size());

        while(it.hasPrevious())
            System.out.print(it.previous() + " ");
    }

    // Exercicio 3
    public static double testa(Pilha p, long sz) {
        long startTime = System.nanoTime();
        for (int j = 0; j < sz; j++)
            p.push(j);
        for (int i = 0; i < sz; i++)
            p.pop();
        return (System.nanoTime() - startTime)/1000000.0;
    }

    public static void main(String[] args) {
	    // Exercicio 1
        System.out.println("Exercicio 1");
        List list = new ArrayList();
        list.add("A");  list.add("B");  list.add("C");

        System.out.println("Lista original: " + list);
        Collections.fill(list,"ED");

        System.out.println("Depois do fill (Collections): " + list);

        myFill(list,"XPTO");
        System.out.println("Depois do fill (myFill): " + list);

        // Exercicio 2
        System.out.println("\nExercicio 2");
        List list2 = new ArrayList();
        list2.add("A");  list2.add("B");  list2.add("C");
        imprimeInverso(list2);

        // Exercico 3
        System.out.println("\n\nExercicio 3");

        long n, sz = 50000, nruns = 20;
        double tm;

        // alinea a)
        ArrayList arrayList = new ArrayList();
        Pilha pAL = new Pilha(arrayList);

        // alinea b)
        LinkedList linkedList = new LinkedList();
        Pilha pLL = new Pilha(linkedList);

        System.out.println("Tempo de execução médio " + nruns + "execuções (ms)");
        System.out.println("N | ArrayList | LinkedList");

        for (int i = 1; i <= 30; i++) {
            // tamanho do pacote de dados a meter neste ciclo
            n = sz * i;

            // arraylist
            tm = 0;
            for (int j = 0; j < nruns; j++)
                tm+= testa(pAL,n);
            System.out.printf("%d | %9.2f | ", i, (float)(tm/nruns));

            // linked list
            tm = 0;
            for (int j = 0; j < nruns; j++)
                tm+= testa(pLL,n);
            System.out.printf("%.2f\n", (float)(tm/nruns));
        }
    }
}
