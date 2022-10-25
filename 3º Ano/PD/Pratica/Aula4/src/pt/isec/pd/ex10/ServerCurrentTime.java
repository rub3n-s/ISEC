package pt.isec.pd.ex10;

import java.io.Serial;
import java.io.Serializable;

public class ServerCurrentTime implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private int horas;
    private int minutos;
    private int segundos;

    public ServerCurrentTime(int horas, int minutos, int segundos) {
        this.horas = horas;
        this.minutos = minutos;
        this.segundos = segundos;
    }

    public void setHoras(int hora) { this.horas = hora; }
    @Override
    public String toString() {
        return horas + ":" + minutos + ":" + segundos;
    }
}
