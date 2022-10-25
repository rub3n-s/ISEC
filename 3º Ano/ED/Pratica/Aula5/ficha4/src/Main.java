public class Main {
    public static void main(String[] args) throws Exception {
        double[] arr = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
        double[] arr_2 = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0};
        DezReais dezReais = new DezReais();
        DezReais dezReaisException = new DezReais();
        
        // Tentativa 1 - Sem excepcao   ----------------------------------
        // inserir valores na tabela
        for (var a : arr)
            dezReais.add(a);

        // mostrar valores da tabela
        dezReais.getList();

        // Tentativa 2 - Com excepcao   ----------------------------------
        // inserir valores na tabela
        for (var a : arr_2)
            dezReaisException.add(a);

        // mostrar valores da tabela
        dezReaisException.getList();
    }
}
