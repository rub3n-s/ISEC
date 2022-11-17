
public class Main {

    public static < E > void printArray(E[] tab){
        for(E element : tab)
            System.out.println(">"+element);
    }
    //comparacao entre 3 tipos
    public static <T extends Comparable> T maxim(T x, T y,T z){
        T max = x;
        if(y.compareTo(max)>0)
            max = y;
        if(z.compareTo(max)>0)
            max = z;
        return max;
    }

    public static < T > boolean comp1(T m[],T chave){
        int cont=0;
        for(int i = 0;i<m.length;i++){
            if(m[i] == chave)
                cont++;
            if(cont == 2)
                return true;
        }
        return false;
    }
    public static < T extends Comparable> boolean comp2(T m[],T chave){
        int cont=0;
        for(int i = 0;i<m.length;i++){
            if(m[i].compareTo(chave) == 0)
                cont++;
            if(cont == 2)
                return true;
        }
        return false;
    }

    public static < Retangulo ,E extends Retangulo> boolean comp111(Figura fig,Retangulo ret){


        return false;
    }
    public static < E > boolean search(E[] m,Comparable <? super E> chave){
        for(int i=0;i<m.length;i++){
            if(chave.compareTo(m[i]) < 0)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Integer[] tabi={1,24,5,24,67,7};
        Double[] tabd = {1.3,123.5,13.4};
        Integer num = 24;
        String[] tab1 = {"Ana","Ana","Maria","Jose"};
        String chave = "Ana";
        //System.out.println(comp2(tab1,chave));
        //System.out.println(comp2(tabi,num));
        Retangulo a = new Retangulo(3,4);
        Retangulo b = new Retangulo(3,7);
        Triangulo c = new Triangulo(3,8);
        //System.out.println(a.compareTo(c));
        /*ex4
        Integer m[]={3,2,6,3};
        String n[]={"Ada", "Albino"};
        System.out.println(search(m,2)); // true
        System.out.println(search(n,"Francisco")); // false
        */

        Ponto<Integer, Integer> p=new Ponto< >(3,4);
        Ponto<Number, Number> x=new Ponto<>(0,0);
        System.out.println(p); // imprime (3,4)
        System.out.println(x); // imprime (0,0)
        x.copy(p);
        System.out.println(x); // imprime (3,4)
        //Ponto<String, Integer> erro=
        //        new Ponto<String,Integer>(“olá”,3);
        // erro de compilação
    }


}