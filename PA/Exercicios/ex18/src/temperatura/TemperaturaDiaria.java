package temperatura;

public class TemperaturaDiaria {
    private int temperaturasHorarias[];
    private String responsavelMedicoes;
    private String localMedicao;

    public TemperaturaDiaria(int[] temps, String resp, String local) {
        responsavelMedicoes = resp;
        localMedicao = local;
        temperaturasHorarias = new int[temps.length];
        for (int i = 0; i < temperaturasHorarias.length; i++) {
            temperaturasHorarias[i] = temps[i];
        }
    }

    public boolean equals(Object o) {
        if (!(o instanceof TemperaturaDiaria)) {
            return false;
    }

    TemperaturaDiaria outro = (TemperaturaDiaria) o;
        return getMaximo() == outro.getMaximo()
        && getMinimo() == outro.getMinimo();
    }

    public int hashCode() {
        int s = 0;
        for (int t : temperaturasHorarias) {
            s += t;
        }

        return s;
    }

    int getMaximo() {
        int max = temperaturasHorarias[0];
        for (int t : temperaturasHorarias) {
            if (t > max) {
                max = t;
            }
        }
        return max;
    }

    int getMinimo() {
        int min = temperaturasHorarias[0];
        for (int t : temperaturasHorarias) {
            if (t < min) {
                min = t;
            }
        }
        return min;
    }
}