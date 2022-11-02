package ficha4;

import java.util.Iterator;

public class Main {
    public Double maiorValor(Iterable<Double> d) {
        Iterator<Double> it = d.iterator();
        Double m, temp = 0.0;

        m = it.next();

        while(it.hasNext()) {
            temp = it.next();
            if (temp > m)
                m = temp;            
        }            
        return temp;
    }

    public static <T extends Comparable<? super T> > T maiorValorG(Iterable<T> d) {
        Iterator<T> it = d.iterator();
        T m, temp;

        m = it.next();

        while(it.hasNext()) {
            temp = it.next();
            if (temp.compareTo(m) > 0)
                m = temp;            
        }            
        return m;
    }

    public static void main(String[] args) throws Exception {
        double[] arr = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
        DezReais dezReais = new DezReais();
        ItDezReais itDezReais = new ItDezReais(dezReais);
        int j = 0;

        //--------------------- ADD - Ex1_Ex2 ---------------------
        //---------------- Sem excepcao ------------------
        // inserir valores na tabela
        for (var a : arr)
            dezReais.add(a);

        // mostrar valores da tabela
        while(itDezReais.hasNext())
            System.out.print(dezReais.get(j++) + " ");
        System.out.println();

        //---------------- Com excepcao ------------------
        // inserir valores na tabela
        /*
        double[] arr_2 = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0};
        DezReais dezReaisException = new DezReais();

        for (var a : arr_2)
            dezReaisException.add(a);

        // mostrar valores da tabela
        dezReaisException.getList();*/

        //--------------------- REMOVE - Ex4 ---------------------
        /*DezReaisMutavel drm = new DezReaisMutavel();
        ItDezReaisMutavel idrm = new ItDezReaisMutavel(drm);

        for (j = 0; j < 10; j++)
            drm.add(j*0.1 + 5.0);

        j = 0; 
        Double dbl;

        while(idrm.hasNext() && (dbl = idrm.next()) < 5.4)
            System.out.println(j++ + ": ultimo:" + dbl);
        
        idrm.remove();

        ItDezReaisMutavel idrm2 = new ItDezReaisMutavel(drm);
        j = 0;
        while (idrm2.hasNext())
            System.out.println((j++) + ": Sem 5.4" + idrm.next()); */
    }
}
