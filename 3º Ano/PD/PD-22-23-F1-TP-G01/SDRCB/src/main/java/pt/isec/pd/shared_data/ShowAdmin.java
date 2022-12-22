package pt.isec.pd.shared_data;

import java.io.Serial;
import java.io.Serializable;

public class ShowAdmin extends Show {
    public ShowAdmin(
            int id,
            String description,
            String type,
            String dateHour,
            int duration,
            String location,
            String locality,
            String country,
            String ageClassification,
            boolean visible) {
        super(id,description,type,dateHour,duration,location,locality,country,ageClassification,visible);
    }

    @Override
    public String toString() {
        return super.toString() + "Visível: " + (visible ? "sim" : "não");
    }
}
