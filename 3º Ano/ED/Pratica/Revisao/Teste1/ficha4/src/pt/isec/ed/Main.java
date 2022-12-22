package pt.isec.ed;

public class Main {

    public static void main(String[] args) {
        System.out.println("Exercicio 1-2-3");
        // Exercicio 1
        DezReais dezReais = new DezReais();
        for (int i = 0; i < 10; i++)
            dezReais.add(0.1 * i);

        // Exercicio 2
        DezReaisIt dezReaisIt = new DezReaisIt(dezReais);
        while(dezReaisIt.hasNext())
            System.out.print(dezReaisIt.next().floatValue() + " ");

        // Exercicio 4
        System.out.println("\n\nExercicio 4");
        DezReaisMutavel dezReaisMutavel = new DezReaisMutavel();
        DezReaisMutavelIt dezReaisMutavelIt = new DezReaisMutavelIt(dezReaisMutavel);
        for (int i = 0; i < 10; i++)
            dezReaisMutavel.add(0.1 * i + 5.0);

        Double tmp;
        while(dezReaisMutavelIt.hasNext() && (tmp = dezReaisMutavelIt.next()) < 5.4)
            System.out.println("ultimo: " + dezReaisMutavelIt.next());

        // Exercicio 6
        System.out.println("\n\nExercicio 6");
        DezReaisMutavel dezReaisMutavel1 = new DezReaisMutavel();
        DezReaisPositivosIt dezReaisPositivosIt = new DezReaisPositivosIt(dezReaisMutavel1);
        Double[] arr = {1.1, 5.2, -5.1, -9.0, 6.4, -1.4, 4.35};

        for (int i = 0; i < arr.length; i++)
            dezReaisMutavel1.add(arr[i]);

        while(dezReaisPositivosIt.hasNext())
            System.out.println(dezReaisPositivosIt.next());
    }
}
