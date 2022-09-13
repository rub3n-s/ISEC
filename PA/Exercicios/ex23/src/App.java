import frota.Frota;
import ui.FrotaUI;

public class App {
    public static void main(String[] args) throws Exception {
        Frota frota = new Frota();
        FrotaUI frotaUI = new FrotaUI(frota);
        frotaUI.start();
    }
}
