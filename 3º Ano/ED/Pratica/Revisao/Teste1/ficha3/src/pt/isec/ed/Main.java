package pt.isec.ed;

import pt.isec.ed.ex3.Figura;
import pt.isec.ed.ex3.Retangulo;
import pt.isec.ed.ex3.Triangulo;
import pt.isec.ed.ex5.Ponto;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

public class Main {
    // Exercicio 1
    public static <T> boolean isRepeated(T[] arr, T object) {
        int cont = 0;
        for (T t : arr)
            if (t.equals(object))
                cont++;
        return cont >= 2;
    }

    // Exercicio 2
    public static <T extends Comparable<T>> boolean isRepeated_v2(T[] arr, T object) {
        int cont = 0;
        for (T t : arr)
            if (t.compareTo(object) == 0)
                cont++;
       return cont >= 2;
    }

    // Exercicio 3
    public static <T extends Figura> boolean compareFigures(Figura figura, Retangulo retangulo) {
        return retangulo.compareTo(figura) > 0;
    }

    // Exercicio 4
    public static <T extends Comparable<T>> boolean higherValue(T[] arr, T object) {
        for (T a : arr)
            if (a.compareTo(object) > 0)
                return true;
        return false;
    }

    public static void main(String[] args) {
        // Exercicio 1
        Integer[] arr = {1,24,24,3,56,91};
        Integer[] arr2 = {1,24,3,56,91};
        System.out.println("Exercicio 1");
        System.out.println(Arrays.toString(arr) + " " + isRepeated(arr,24));
        System.out.println(Arrays.toString(arr2) + " " + isRepeated(arr2,24));

        // Exercicio 2
        System.out.println("\nExercicio 2");
        System.out.println(Arrays.toString(arr) + " " + isRepeated_v2(arr,24));
        System.out.println(Arrays.toString(arr2) + " " + isRepeated_v2(arr2,24));

        // Exercicio 3
        Retangulo retangulo = new Retangulo(3,4);
        Triangulo triangulo = new Triangulo(3,4);
        System.out.println("\nExercicio 3");
        System.out.println(retangulo.compareTo(triangulo)); // area retangulo > triangulo
        System.out.println(Main.compareFigures(triangulo,retangulo)); // area retangulo > triangulo

        // Exercicio 4
        Integer m[]={3,2,6,3};
        String n[]={"Ada", "Albino"};
        System.out.println("\nExercicio 4");
        System.out.println(higherValue(m,2)); // true
        System.out.println(higherValue(n,"Francisco")); // false

        // Exercicio 5
        System.out.println("\nExercicio 5");
        Ponto<Integer, Integer> p=new Ponto(3,4);
        Ponto<Number, Number> x=new Ponto(0,0);
        System.out.println(p); // imprime (3,4)
        System.out.println(x); // imprime (0,0)
        x.copy(p);
        System.out.println(x); // imprime (3,4)
        //Ponto<String, Integer> erro= new Ponto<String,Integer>(“olá”,3); // erro de compilação
    }
}
