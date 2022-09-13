package pt.isec.pa.ex29_v2;

// Para adicionar a biblioteca
// Botão direito do rato sobre o projeto > Open Module Settings > Global Libraries >> Add module
// Run > Add VM Options > --module-path /Library/Java/JavaVirtualMachines/javafx-sdk-17/lib --add-modules javafx.controls

import javafx.application.Application;
import pt.isec.pa.ex29_v2.ui.gui.MainJFX;

public class Main {
    public static void main(String[] args) {
        Application.launch(MainJFX.class, args);
    }
}
