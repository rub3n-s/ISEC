import java.security.PublicKey;
import java.util.Arrays;
import java.util.Random;

public class App {
    private static int[] criaArrayCom(int valor,int dimensao,boolean diferentes) {
        int m[] = new int[dimensao];
        if (diferentes) {
            for (int i = 0; i < dimensao; i++)
                m[i] = i * 10;
            if ((valor % 10 != 0) || (0 > valor) || (valor > (dimensao - 1) * 10))
                m[0] = valor;
        } else {
            Random r = new Random();
            int gama = (Math.abs(valor) < 10) ? 10 : Math.abs(valor);
            for (int i = 0; i < dimensao; i++)
                m[i] = r.nextInt(gama * 4) - gama * 2;
            m[0] = valor;
        }
        Arrays.sort(m);
        return m;
    }

    private static void mostraArray(int[] arr) {
        for (var a : arr)
            System.out.print(a + " ");
        System.out.println();
    }

    private static int it = 0;

    //===============================
    //Ex1 - RECURSIVA
    //===============================
    private static boolean binRecursivo(int[] arr, int chave) {
        int start = 0, end = arr.length, meio = (start + end) / 2;        
        
        if (end == 0) {
            System.out.println("Tabela vazia");
            return false;
        }

        if (arr[meio] == chave) // caso esteja no meio
            return true;
        
        if (arr[meio] > chave)  // se nao esta no meio, mas esta à esquerda
            end = meio - 1;     // entao definir que o fim é antes do meio
        else
            start = meio + 1;   // caso contrario, o inicio começa a partir do meio
        
        if (end < arr.length)
            end++;
        
        // mostrar transformacao do array
        int newt[] = Arrays.copyOfRange(arr, start, end);
        System.out.print(it + ": ");
        mostraArray(arr);
        it ++;

        return binRecursivo(newt, chave);
    }

    //===============================
    //Ex2 - ITERATIVA
    //===============================
    private static boolean binIterativo(int[] arr, int chave) {
        int start = 0, end = arr.length, meio = (start + end) / 2;  

        while (start < end) {
            if (arr[meio] == chave) // caso esteja no meio
                return true;
            
            if (arr[meio] > chave)  // se nao esta no meio, mas esta à esquerda
                end = meio - 1;     // entao definir que o fim é antes do meio
            else
                start = meio + 1;   // caso contrario, o inicio começa a partir do meio
            
            meio = (start + end) / 2;

            // mostrar transformacao do array
            if (it == 0) {
                System.out.print("Original: ");
                mostraArray(arr);
            }
            int newt[] = Arrays.copyOfRange(arr, start, end);
            System.out.print(it + ": ");
            mostraArray(newt);
            it ++;
        }

        if (arr[meio] == chave)
            return true;

        return false;
    }

    //===============================
    //Ex3 - POSICAO
    //===============================
    private static int binPosicao(int[] arr, int chave) {
        int start = 0, end = arr.length, meio = (start + end) / 2;  

        while (start < end) {
            if (arr[meio] == chave) // caso esteja no meio
                return meio;
            
            if (arr[meio] > chave)  // se nao esta no meio, mas esta à esquerda
                end = meio - 1;     // entao definir que o fim é antes do meio
            else
                start = meio + 1;   // caso contrario, o inicio começa a partir do meio
            
            meio = (start + end) / 2;

            // mostrar transformacao do array
            if (it == 0) {
                System.out.print("Original: ");
                mostraArray(arr);
            }
            int newt[] = Arrays.copyOfRange(arr, start, end);
            System.out.print(it + ": ");
            mostraArray(newt);
            it ++;
        }

        if (arr[meio] == chave)
            return meio;

        return -1;
    }

    //===============================
    //Ex4 - COMPARE
    //===============================
    private static int binCmp(int[] arr, int chave) {
        int start = 0, end = arr.length, meio = (start + end) / 2;  

        while (start < end) {
            if (arr[meio] == chave) // caso esteja no meio
                return meio;
            
            if (arr[meio] > chave)  // se nao esta no meio, mas esta à esquerda
                end = meio - 1;     // entao definir que o fim é antes do meio
            else
                start = meio + 1;   // caso contrario, o inicio começa a partir do meio
            
            meio = (start + end) / 2;
        }

        if (arr[meio] == chave)
            return meio;

        if (arr[meio] < chave)
            return -meio - 2;

        return Math.abs(-meio -1 +1);
    }

    //===============================
    // Ex5 - PERCENTAGEM
    //===============================
    private static double binPercentagem(int[] arr, int chave) {
        int pos = binCmp(arr, chave);

        // se o valor existe
        if (pos >= 0)
            return (double)pos/arr.length;
        
        // se o valor nao existe
        int posInsert = -pos -1;

        // o valor na posicao de insercao é menor e deve contar
        return posInsert/(double)arr.length;
    }

    //===============================
    // Ex6 - INTERVALO
    //===============================
    public static int valoresNoIntervalo(int[] arr, int limInf, int limSup) {
        int posInf = binCmp(arr, limInf);
        int posSup = binCmp(arr, limSup);

        if (posInf < 0)
            posInf = -posInf - 1;
        
        if (posSup < 0)
            posSup = -posSup - 1;
        else
            posSup++;
        
        return posSup - posInf;
    }


    //===============================
    // Ex7 - REPETIDO
    //===============================
    public static boolean valorRepetido(int[] arr, int chave) {
        // como se trata de um array ordenado, comecamos por verificar a posicao da chave
        int pos = binPosicao(arr, chave);

        // nao encontrou a chave
        if (pos < 0)
            return false;

        // se a chave esta na primeira pos. do array, verifica a pos. seguinte
        if (pos == 0 && arr[pos + 1] == chave)
            return true;
        // se a chave se encontra na ultima pos. do array, verifica a pos. anterior
        else if (pos == arr.length - 1 && arr[arr.length - 1] == chave)
            return true;
        // se a chave nao esta no inicio nem no fim do array
        else if (arr[pos - 1] == chave || arr[pos + 1] == chave)
            return true;

        return false;
    }


    //===============================
    // Ex8 - MAIOR VALOR
    //===============================
    private static int maiorValor(int[] arr, int chave) {
        // obtem a posicao da chave
        int pos = binCmp(arr, chave);

        // se nao houver nenhum numero menor, devolve a propria chave
        if (pos == 0 || pos == -1)
            return chave;
        
        // se a chave nao existir no array
        if (pos < 0)
            pos = -pos - 1;

        return arr[pos - 1];
    }

    public static boolean procuraValor(int[] arr, int chave) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;
        
        do {
            // encontra o valor no meio
            if (arr[meio] == chave) 
                return true;
            // verifica se os sinais sao iguais (- * - = +, + * + = +)
            // assim sabemos se estamos a pesquisar do lado correto
            if (chave * arr[meio] >= 0) {
                if (arr[meio] < chave) 
                    start = meio + 1;
                else
                    end = meio -1;
            }
            else {
                if (arr[meio] < chave) 
                    end = meio - 1;
                else
                    start = meio + 1;
            }
            meio = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[meio] == chave) 
            return true;

        return false;       // chave deve ir para a esquerda do meio
    }

    public static int devolveIndice(int[] arr) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;
        do {
            if (arr[meio] > meio) 
                end = meio;
            else 
                start = meio + 1;

            meio = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[meio] > meio) 
            return meio;
        return -1;
    }

    public static void main(String[] args) throws Exception {
        int[] arr = criaArrayCom(5, 10, false);

        System.out.println("===============================\n"
                            + "\tEx1 - RECURSIVA           \n" +
                            "===============================");
        boolean res = binRecursivo(arr,5);
        if (res)
            System.out.println("Existe");
        else
            System.out.println("Nao Existe");

        System.out.println("\n===============================\n"
                            + "\tEx2 - ITERATIVA           \n" +
                            "===============================");
        res = binIterativo(arr,5);
        if (res)
            System.out.println("Existe");
        else
            System.out.println("Nao Existe");
            
        System.out.println("\n===============================\n"
                            + "\tEx3 - POSICAO             \n" +
                            "===============================");
        System.out.println("Pos: " + binPosicao(arr,5));

        int[] arr2 = {3,7,12,15};
        
        System.out.println("\n===============================\n"
                            + "\tEx4 - COMPARE             \n" +
                            "===============================");    
        int chave = 15;
        System.out.println("Chave: " + chave + ", resultado: " + binCmp(arr2,chave));

        System.out.println("\n===============================\n"
                            + "\tEx5 - PERCENTAGEM             \n" +
                            "===============================");    
        int chave5 = 15;
        System.out.println("Chave: " + chave5 + ", resultado: " + binPercentagem(arr2,chave5));

        System.out.println("\n===============================\n"
                            + "\tEx6 - INTERVALO             \n" +
                            "===============================");
        int limInf = 4, limSup = 14;        
        int num = valoresNoIntervalo(arr2,limInf,limSup);
        
        System.out.println("Valores (" + limInf + "," + limSup + ") Resultado = " + num);

        System.out.println("\n===============================\n"
                            + "\tEx7 - VALOR REPETIDO      \n" +
                            "===============================");
        int [] arr7 = {3,3,7,12,12,15};

        int chave7_1 = 15;
        System.out.println("Valor = " + chave7_1 + " resultado = " + valorRepetido(arr7, chave7_1));

        int chave7_2 = 15;
        System.out.println("Valor = " + chave7_2 + " resultado = " + valorRepetido(arr7, chave7_2));

        int chave7_3 = 14;
        System.out.println("Valor = " + chave7_3 + " resultado = " + valorRepetido(arr7, chave7_3));

        int chave7_4 = 3;
        System.out.println("Valor = " + chave7_4 + " resultado = " + valorRepetido(arr7, chave7_4));

        System.out.println("\n===============================\n"
                            + "\tEx8 - MAIOR VALOR             \n" +
                            "===============================");
        int chave8 = 15;
        System.out.println("Valor = " + chave8 + " resultado = " + maiorValor(arr, chave8));

        System.out.println("\n===============================\n"
                            + "\tEx9 - PROCURA VALOR       \n" +
                            "===============================");
        int[] arr9 = {3,6,8, -10,-3,-2,-1};
        int chave9 = 6;

        System.out.println("Valor = " + chave9 +  " Resultado = " + procuraValor(arr9, chave9));

        System.out.println("\n===============================\n"
                            + "\tEx10 - DEVOLVE INDICE      \n" +
                            "===============================");
        int[] arr10_1 = {3,7,12,15};
        System.out.println("Resultado = " + devolveIndice(arr10_1));

        int[] arr10_2 = {-3,1,7,12,15};
        System.out.println("Resultado = " + devolveIndice(arr10_2));

        int[] arr10_3 = {-15,-14,1,2,3,4};
        System.out.println("Resultado = " + devolveIndice(arr10_3));
    }   
}