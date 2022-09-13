package sistemas;

import java.util.ArrayList;
import java.util.Collection;
import java.util.EnumMap;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Sistemas {
    //Map<String,ArrayList<String>> sis;
    Map<String,HashMap<String,ArrayList<String>>> sis;

    public Sistemas() {
        sis = new HashMap<>();
    }

    public boolean newSystem(String sistema) {
        if (sis.containsKey(sistema)) {
            System.out.println("Esse sistema já existe!\n");
            return false;
        } else if (sistema == null) {
            System.out.println("Input inválido!\n");
            return false;
        }
        //sis.put(sistema,new ArrayList<String>());
        sis.put(sistema,new HashMap<String,ArrayList<String>>());
        sis.get(sistema).put("Planeta", new ArrayList<>());
        sis.get(sistema).put("Estrela", new ArrayList<>());
        return true;
    }

    public boolean addPlanet(String sistema, String planeta) {
        if (sistema == null || planeta == null)
            return false;
        if (sis.containsKey(sistema)) {
            //sis.get(sistema).add(planeta);
            sis.get(sistema).get("Planeta").add(planeta);
            return true;
        }
        return false;
    }

    public boolean addStar(String sistema, String estrela) {
        if (sistema == null || estrela == null)
            return false;
        if (sis.containsKey(sistema)) {
            //sis.get(sistema).add(estrela);
            sis.get(sistema).get("Estrela").add(estrela);
            return true;
        }
        return false;
    }

    public String getPlanet(String sistema, int pos) {
        //return sis.get(sistema).get(pos);
        return sis.get(sistema).get("Planeta").get(pos);
    }

    public String getStars(String sistema) {
        //return sis.get(sistema).toString();
        return sis.get(sistema).get("Estrela").toString();
    }

    public boolean existsSystem(String sistema) {
        if (sis.containsKey(sistema))
            return true;
        return false;
    }
}
