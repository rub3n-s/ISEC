package pascal;

public class Pascal {
    private int [][] arr;

    public Pascal(int profundidade) {
        arr = new int[profundidade][];
        for (int i = 0; i < profundidade; i++)
            arr[i] = new int[i+1];
        preenche();
    }

    private void preenche() {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = fatorial(i) / (fatorial(j)*fatorial(i-j));
            }
        }
    }

    private static int fatorial(int numero) {
        int fact = 1;
        for (int i = 1; i <= numero; i++)
            fact *= i;
        return fact;
    }

    public void imprime() {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                System.out.printf("%d ",arr[i][j]);
            System.out.println();
        }
        System.out.println();
    }

   @Override
   public String toString() {
        StringBuilder sb = new StringBuilder("\n[toString()] Triangulo de Pascal: \n");
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                sb.append(arr[i][j] + " ");
            sb.append("\n");
        }
        return sb.toString();
   } 
}
