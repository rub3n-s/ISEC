package triangulo;

public class Triangulo {
    private int [][] arr;

    public Triangulo(int prof) {
        arr = new int[prof][];
    }

    public void preenche() {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new int[i+1];
            for (int j = 0; j < arr[i].length; j++) {
                int n = 0, p = 0, np = 0;
                n = fatorial(i);
                p = fatorial(j);
                np = fatorial(i-j);
                arr[i][j] = n / (p * np);
            }
        }
    }

    public void imprime() {
        for (int i = 0 ; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                System.out.printf("%d ",arr[i][j]);
            System.out.println();
        }
        System.out.println();
    }

    public static int fatorial(int numero) {
        int fact = 1;
        for (int i = 1; i <= numero; i++)
            fact *= i;
        return fact;
    }

    @Override
    public String toString() {
        String str = new String();
        
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                str += arr[i][j] + " ";
            str += "\n";
        }

        return str;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Triangulo tr = new Triangulo(arr.length);
        //tr = this.
        return tr;
    }
}
