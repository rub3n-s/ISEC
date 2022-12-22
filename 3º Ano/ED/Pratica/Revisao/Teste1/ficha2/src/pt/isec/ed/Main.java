package pt.isec.ed;

import java.util.Arrays;
import java.util.Random;

public class Main {
    static int[] criaArrayCom( int valor, int dimensao, boolean diferentes){
        int m[]=new int[dimensao];
        if(diferentes){
            for(int i=0;i<dimensao;i++)
                m[i]=i*10;
            if((valor%10!=0)||(0>valor)||(valor>(dimensao-1)*10))
                m[0]=valor;
        }
        else{
            Random r=new Random();
            int gama=(Math.abs(valor)<10)?10:Math.abs(valor);
            for(int i=0;i<dimensao;i++)
                m[i]=r.nextInt(gama*4)-gama*2;
            m[0]=valor;
        }
        Arrays.sort(m);
        return m;
    }

    public static void printArray(int[] arr) {
        for (int a : arr)
            System.out.print(a + " ");
        System.out.println();
    }

    // ===============================
    // Ex1 - Pesquisa Recursiva
    // ===============================
    public static boolean recursive(int[] arr, int key) {
        int start = 0, end = arr.length, middle = (start + end) / 2;

        printArray(arr);

        if (arr[middle] == key) // caso esteja no meio
            return true;

        if (arr[middle] > key) // se está à esquerda do meio, pesquisar lado esquerdo do array
            end = middle - 1;    // definir que o fim é antes do meio
        else
            start = middle + 1;  // caso contrário a chave esta do lado direito

        if (end < arr.length)
            end++;

        return recursive(Arrays.copyOfRange(arr,start,end),key);
    }

    // ===============================
    // Ex2 - Binária Iterativa
    // ===============================
    public static boolean binIterative(int[] arr, int key) {
        int start = 0, end = arr.length, middle = (start + end) / 2;

        while(start < end) {
            if (arr[middle] == key)
                return true;
            if (arr[middle] > key)  // se a chave estiver à esquerda do meio
                end = middle - 1;
            else
                start = middle + 1; // caso contrario, esta a direita do meio
            middle = (start + end) / 2; // recalcular o meio
        }
        return false;
    }

    // ===============================
    // Ex3 - Posicao
    // ===============================
    public static int binPosition(int[] arr, int key) {
        int start = 0, end = arr.length, middle = (start + end) / 2;

        while(start < end) {
            if (arr[middle] == key)
                return middle;
            if (arr[middle] > key)  // se a chave estiver à esquerda do meio
                end = middle - 1;
            else
                start = middle + 1; // caso contrario, esta a direita do meio
            middle = (start + end) / 2; // recalcular o meio
        }
        return -1;
    }

    // ===============================
    // Ex4 - Compara Posicao
    // ===============================
    public static int binCompare(int[] arr, int key) {
        int start = 0, end = arr.length, middle = (start + end) / 2;

        while(start < end) {
            if (arr[middle] == key)
                return middle;

            if (arr[middle] > key)  // se a chave estiver à esquerda do meio
                end = middle - 1;
            else
                start = middle + 1; // caso contrario, esta a direita do meio

            middle = (start + end) / 2; // recalcular o meio
        }

        if (middle == arr.length)
            middle--;

        if (arr[middle] < key)
            return -middle - 2;

        return Math.abs(-middle -1 + 1);
    }

    // ===============================
    // Ex5 - Percentage
    // ===============================
    public static double binPercentage(int[] arr, int key) {
        int pos = binCompare(arr,key);

        // se o valor existir
        if (pos >= 0)
            return (double)pos/arr.length;

        // se os valor nao existir
        int posInsert = -pos - 1;

        // o valor na posicao de insercao é menor e deve contar
        return posInsert/(double)arr.length;
    }

    // ===============================
    // Ex6 - Interval
    // ===============================
    public static int binInterval(int[] arr, int limInf, int limSup) {
        if (limSup - limInf == 1)
            return 0;

        int posInf = binCompare(arr,limInf);
        int posSup = binCompare(arr,limSup);

        if (posInf < 0)
            posInf = -posInf - 1;

        if (posSup < 0)
            posSup = -posSup - 1;
        else
            posSup++;

        return posSup - posInf;
    }

    // ===============================
    // Ex7 - Repeated
    // ===============================
    public static boolean binRepeated(int[] arr, int key) {
        int pos = binCompare(arr,key);

        if (pos < 0)
            return false;
        if (pos == 0 && arr[pos + 1] == key)
            return true;
        else if (pos == arr.length - 1 && arr[pos - 1] == key)
            return true;
        return (pos > 0 && pos < arr.length - 1 && (arr[pos + 1] == key || arr[pos - 1] == key));
    }

    // ===============================
    // Ex8 - Higher Value Before Key
    // ===============================
    public static int higherValue(int[] arr, int key) {
        int pos = binCompare(arr,key);

        if (pos == 0)  // se nao houver nenhum numero maior
            return key;

        if (pos < 0)
            pos = -pos - 1;

        return arr[pos-1];
    }

    // ===============================
    // Ex9 - Search Key
    // ===============================
    public static boolean searchValue(int[] arr, int key) {
        int start = 0, end = arr.length -1, middle = (start + end) / 2;

        while(start < end) {
            if (arr[middle] == key)
                return true;

            // verificar se estamos do 'lado' dos positivos ou negativos
            if (arr[middle] * key >= 0) {
                if (arr[middle] > key)
                    end = middle - 1;
                else
                    start = middle + 1;
            }
            // caso esteja do lado contrario
            else {
                if (arr[middle] > key)
                    start = middle + 1;
                else
                    end = middle - 1;
            }

            middle = (start + end) / 2;
        }

        return arr[middle] == key;
    }

    // ===============================
    // Ex10 - Index
    // ===============================
    public static int index(int[] arr) {
        int start = 0, end = arr.length - 1;
        int middle = (start + end) / 2;
        do {
            if (arr[middle] > middle)
                end = middle;
            else
                start = middle + 1;

            middle = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[middle] > middle)
            return middle;
        return -1;
    }

    public static void main(String[] args) {
        int [] arr = criaArrayCom(5,5,true);

        System.out.println("\n===================\nEx1 - Recursive\n===================");
        System.out.println(recursive(arr,5));

        System.out.println("\n===================\nEx2 - Binary\n===================");
        System.out.println(binIterative(arr,5));

        System.out.println("\n===================\nEx3 - Position\n===================");
        System.out.println(binPosition(arr,5));

        int [] arr2 = {3,7,12,15};
        System.out.println("\n===================\nEx4 - Position_v2\n===================");
        System.out.println("Valor procurado:" + 15 + "\tResultado:" + binCompare(arr2,15));
        System.out.println("Valor procurado:" + 3 + "\tResultado:" + binCompare(arr2,3));
        System.out.println("Valor procurado:" + 1 + "\tResultado:" + binCompare(arr2,1));
        System.out.println("Valor procurado:" + 4 + "\tResultado:" + binCompare(arr2,4));
        System.out.println("Valor procurado:" + 10 + "\tResultado:" + binCompare(arr2,10));
        System.out.println("Valor procurado:" + 13 + "\tResultado:" + binCompare(arr2,13));

        System.out.println("\n===================\nEx5 - Percentage\n===================");
        System.out.println("Valor:" + 15 + "\tResultado:" + binPercentage(arr2,15));
        System.out.println("Valor:" + 14 + "\tResultado:" + binPercentage(arr2,14));
        System.out.println("Valor:" + 3 + " \tResultado:" + binPercentage(arr2,3));
        System.out.println("Valor:" + 1 + " \tResultado:" + binPercentage(arr2,1));

        System.out.println("\n===================\nEx6 - Interval\n===================");
        System.out.println("Valores(0,15)\tResultado:" + binInterval(arr2,0,15));
        System.out.println("Valores(3,7) \tResultado:" + binInterval(arr2,3,7));
        System.out.println("Valores(4,14)\tResultado:" + binInterval(arr2,4,14));
        System.out.println("Valores(4,5) \tResultado:" + binInterval(arr2,4,5));

        System.out.println("\n===================\nEx7 - Repeated\n===================");
        int[] arr3 = {3,3,7,12,12,15};
        System.out.println("Valor:15\tResultado:" + binRepeated(arr3,15));
        System.out.println("Valor:14\tResultado:" + binRepeated(arr3,14));
        System.out.println("Valor:12\tResultado:" + binRepeated(arr3,12));
        System.out.println("Valor:3 \tResultado:" + binRepeated(arr3,3));

        System.out.println("\n===================\nEx8 - Higher Value Before Key\n===================");
        System.out.println("Valor:15 \tResultado:" + higherValue(arr2,15));
        System.out.println("Valor:14 \tResultado:" + higherValue(arr2,14));
        System.out.println("Valor:3  \tResultado:" + higherValue(arr2,3));
        System.out.println("Valor:1  \tResultado:" + higherValue(arr2,1));
        System.out.println("Valor:100\tResultado:" + higherValue(arr2,100));

        System.out.println("\n===================\nEx9 - Search Key\n===================");
        int[] arr4 = {3,6,8, -10,-3,-2,-1};
        System.out.println("Valor:8 \tResultado:" + searchValue(arr4,8));

        System.out.println("\n===================\nEx10 - Index\n===================");
        int[] arr5 = {3,7,12,15};
        System.out.println(Arrays.toString(arr5) + " Resultado=" + index(arr5));
        int[] arr6 = {-3,1,7,12,15};
        System.out.println(Arrays.toString(arr6) + " Resultado=" + index(arr6));
        int[] arr7 = {-15,-14,1,2,3,4};
        System.out.println(Arrays.toString(arr7) + " Resultado=" + index(arr7));
    }
}
