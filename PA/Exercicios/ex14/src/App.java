import sistemas.*;

public class App {
    public static void main(String[] args) throws Exception {
        Sistemas d = new Sistemas();
        d.newSystem("Sistema Solar"); //nome do sistema
        d.addStar("Sistema Solar", "Sol"); // acrescenta estrela a sistema
        d.addPlanet("Sistema Solar", "Mercurio"); //acrescenta primeiro planeta
        d.addPlanet("Sistema Solar", "Venus"); //acrescenta segundo planeta
        d.addPlanet("Sistema Solar", "Terra"); //acrescenta terceiro planeta
        d.newSystem("Alfa Centauri");
        d.addStar("Alfa Centauri", "Proxima Centauri");
        d.addStar("Alfa Centauri", "Alfa Centauri A");
        d.addStar("Alfa Centauri", "Alfa Centauri B");
        d.addPlanet("Alfa Centauri", "Alfa Centauri Bb");
        System.out.println(d.getPlanet("Sistema Solar", 2)); // venus
        System.out.println(d.getStars("Alfa Centauri"));
        // [Proxima Centauri , Alfa Centauri A, Alfa Centauri B]
        System.out.println(d.existsSystem("Xanadu")); //false
        System.out.println(d.existsSystem("Sistema Solar")); //true
    }
}
