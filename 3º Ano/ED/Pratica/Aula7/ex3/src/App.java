import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class App {
    public static double testa(Pilha p, long sz) {
        long startTime = System.nanoTime();
        for (int j = 0; j < sz; j++) 
            p.push(j);
        for (int i = 0; i < sz; i++) 
            p.pop();
        return (System.nanoTime() - startTime)/1000000.0;
    }

    public static void main(String[] args) throws Exception {
        long n, sz = 50000, nruns = 20;
        double tm;
        String filePath = "~/";

        File file = new File(filePath);

        // create FileWriter object with file as parameter
        FileWriter outputfile = new FileWriter(file);
    
        // create CSVWriter object filewriter object as parameter
        CSVWriter writer = new CSVWriter(outputfile);

        // alinea a)
        ArrayList arrayList = new ArrayList<>();
        Pilha pAL = new Pilha<>(arrayList);

        // alinea b)
        LinkedList linkedList = new LinkedList<>();
        Pilha pLL = new Pilha<>(linkedList);

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

    private static List<String[]> createCsvDataSimple(String[] str) {
        List<String[]> list = new ArrayList<>();
        list.add(str);

        return list;
    }
}
