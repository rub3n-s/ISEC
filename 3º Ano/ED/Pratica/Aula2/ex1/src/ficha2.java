import java.util.Arrays;
import java.util.Random;

public class ficha2 {
    static int[] criaArrayCom(int valor, int dimensao, boolean diferentes){
        int m[]=new int[dimensao];
        
        if(diferentes){
            for(int i=0;i<dimensao;i++)
                m[i]=i*10;
            if((valor%10!=0)||(0>valor)||(valor>(dimensao-1)*10))
                m[0]=valor;
        } else {        
            Random r=new Random();

            int gama=(Math.abs(valor)<10)?10:Math.abs(valor);
        
            for(int i=0;i<dimensao;i++)
                m[i]=r.nextInt(gama*4)-gama*2;
            
            m[0]=valor;
        }
        
        Arrays.sort(m);
        
        return m;
    }

    static void mostraArray(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }


    // esta funcao vai ao meio, e se nao estiver no meio guarda a parte que precisa
    public static boolean binRecursivo(int[] arr, int chave) {
        int start = 0, end = arr.length, meio = (start + end)/2;

        if (end == 0) {
            System.out.println("Tabela vazia");
            return false;
        }
        
        if (arr[meio] == chave)
            return true;
        
        if (arr[meio] > chave)
            end = meio - 1;
        else
            start = meio + 1;

        if (end < arr.length)       // copyOfRange vai até end-1
            end++;
        
        int newt[] = Arrays.copyOfRange(arr, start, end);
        
        mostraArray(newt);

        return binRecursivo(newt, chave);
    }

    public static boolean binIterativo(int[] arr, int chave) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;

        if (end == 0) {
            System.out.println("Tabela vazia");
            return false;
        }
        
        do {
            if (arr[meio] == chave) 
                return true;
            if (arr[meio] < chave) 
                start = meio + 1;
            else
                end = meio -1;
            meio = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[meio] == chave) 
            return true;

        return false;
    }

    public static int binPosicao(int[] arr, int chave) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;
        
        do {
            if (arr[meio] == chave) 
                return meio;
            if (arr[meio] < chave) 
                start = meio + 1;
            else
                end = meio -1;
            meio = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[meio] == chave) 
            return meio;

        return -1;
    }

    public static int binCmp(int[] arr, int chave) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;
        
        do {
            if (arr[meio] == chave) 
                return meio;
            if (arr[meio] < chave) 
                start = meio + 1;
            else
                end = meio -1;
            meio = (start + end) / 2;   // calcula novo meio para ser testado
        } while(start < end);

        if (arr[meio] == chave) 
            return meio;

        if (arr[meio] < chave)
            return -meio - 2;   // chave deve ir para a direita do meio

        return Math.abs(-meio - 1 + 1);       // chave deve ir para a esquerda do meio
    }

    public static double binPercentagem(int[] arr, int chave) {
        int pos = binCmp(arr, chave);

        // se o valor existe
        if (pos >= 0)
            return (double)pos/arr.length;

        // se o valor não existe
        int posInsert = -pos - 1;

        // o valor na pos de inserção é menor e deve contar
        return posInsert/(double)arr.length;
    }

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

    public static boolean valorNoArray(int[] arr, int chave) {
        int pos = binPosicao(arr, chave);

        if (pos < 0)
            return false;

        if (pos == 0 && arr[pos + 1] == chave)
            return true;
        else if (arr.length - 1 == pos && arr[arr.length - 1] == chave)
            return true;
        else if (arr[pos - 1] == chave || arr[pos + 1] == chave)
            return true;
        
        return false;
    }

    public static int maiorValor(int[] arr, int chave) {
        int pos = binCmp(arr, chave);

        if (pos == 0 || pos == -1)
            return chave;
        
        if (pos < 0)
            pos = -pos -1;

        return arr[pos - 1];
    }

    public static boolean procuraValor(int[] arr, int chave) {
        int start = 0, end = arr.length - 1;
        int meio = (start + end) / 2;
        
        do {
            if (arr[meio] == chave) 
                return true;

            if (arr[meio] > 0 && chave > 0) {
                if (arr[meio] < chave) 
                    start = meio + 1;
                else
                    end = meio -1;
                meio = (start + end) / 2;   // calcula novo meio para ser testado
            }
            else if (arr[meio] < 0 && chave < 0) {                
                if (arr[meio] > chave) 
                    start = meio - 1;
                else
                    end = meio + 1;
                meio = (start - end) / 2;   // calcula novo meio para ser testado
            }
            
        } while(start < end);

        if (arr[meio] == chave) 
            return true;

        return false;       // chave deve ir para a esquerda do meio
    }

    public static void main(String[] args) throws Exception {
        /*int dimensao, valor;
        Scanner sc = new Scanner(System.in);

        System.out.print("Valor: ");
        valor = sc.nextInt();

        System.out.print("\nDimensao: ");
        dimensao = sc.nextInt();
        
        int[] array = criaArrayCom(valor, dimensao,false);

        mostraArray(array);*/

        //System.out.print("\nProcurar valor: ");
        //int procurar = sc.nextInt();

        //--------------------------------------
        // ex1 - Pesquisa Recursiva
        //--------------------------------------
        /*boolean res = binRecursivo(array, procurar);

        if (res) 
            System.out.println("Existe");
        else
            System.out.println("Nao existe");*/

        //--------------------------------------
        // ex2 - Pesquisa Iterativa
        //--------------------------------------
        /*int pos = binPosicao(array, procurar);

        if (pos != -1) 
            System.out.println("Existe");
        else
            System.out.println("Nao existe"); */

        //--------------------------------------
        // ex3 - Pesquisa e Devolve Posicao
        //--------------------------------------
        /*int pos = binPosicao(array, procurar);

        if (pos != -1) 
            System.out.println("Existe na posicao = " + pos);
        else
            System.out.println("Nao existe");*/

        //--------------------------------------
        // ex4 - Pesquisa e Devolve Posicao
        //--------------------------------------
        /*int [] arr = {3,7,12,15};
        int chave = 1;
        int pos = binCmp(arr, chave);

        System.out.println("Valor Procurado = " + chave + " Resultado = " + pos); */

        //--------------------------------------
        // ex5 - Pesquisa e Devolve Percentagem
        //--------------------------------------
        /*int [] arr = {3,7,12,15};
        double percentagem = binPercentagem(arr, procurar);

        System.out.println("Valor Procurado = " + procurar + " Percentagem = " + percentagem);*/

        //--------------------------------------
        // ex6 - Pesquisa e Devolve Percentagem
        //--------------------------------------
        /*int [] arr = {3,7,12,15};
        int limInf = 4, limSup = 14;
        
        int num = valoresNoIntervalo(arr,limInf,limSup);
        
        System.out.println("Valores (" + limInf + "," + limSup + ") Resultado = " + num); */

        //------------------------------------------
        // ex7 - Pesquisa e Devolve Valor Repetido
        //------------------------------------------
        /*int [] arr = {3,3,7,12,12,15};
        int chave;

        chave = 15;
        System.out.println("Valor = " + chave +  " Resultado = " + valorNoArray(arr, chave));

        chave = 14;
        System.out.println("Valor = " + chave +  " Resultado = " + valorNoArray(arr, chave));

        chave = 12;
        System.out.println("Valor = " + chave +  " Resultado = " + valorNoArray(arr, chave));

        chave = 3;
        System.out.println("Valor = " + chave +  " Resultado = " + valorNoArray(arr, chave)); */

        //------------------------------------------
        // ex8 - Pesquisa e Devolve Max
        //------------------------------------------
        /*int[] arr = {3,7,12,15};
        int chave = 15;

        System.out.println("Valor = " + chave +  " Resultado = " + maiorValor(arr, chave)); */

        //------------------------------------------
        // ex9 - Procura valor no array
        //------------------------------------------
        int[] arr = {3,6,8, -10,-3,-2,-1};
        int chave = 15;

        System.out.println("Valor = " + chave +  " Resultado = " + procuraValor(arr, chave));

        // fecha o scanner
        //sc.close();
    }
}
