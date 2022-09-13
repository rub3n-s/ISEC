package dicionario;

import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Dictionary {
    private final Map<String,Map<String,String>> dict_of_dict;
    private String lingua;

    public Dictionary() {
        dict_of_dict = new HashMap<>();
        lingua = new String();
    }

    public boolean add(String linguagem, String conceito, String traducao) {
        if (linguagem!=null && conceito!=null && traducao!=null) {
                HashMap<String,String> val = new HashMap<>();
                val.put(conceito, traducao);
                if (dict_of_dict.containsKey(linguagem))
                    dict_of_dict.get(linguagem).put(conceito, traducao);
                else
                    dict_of_dict.put(linguagem,val);
            return  true;
        }
        return false;
    }

    public boolean defineLingua(String lingua) {
        if (lingua != null) {
            this.lingua = lingua;
            return true;
        }
        return false;
    }

    public String get(String palavra) {
        if (this.lingua != null && dict_of_dict.containsKey(this.lingua)) {
            StringBuilder sb = new StringBuilder("\nTraducao '" + palavra + "' (lang: " + this.lingua + "):\n");
            for (Map.Entry<String, Map<String, String>> entry : dict_of_dict.entrySet()) {
                if (entry.getKey().equals(this.lingua)) {
                    sb.append(entry.getValue().get(palavra)+"\n");
                }
            }
            return sb.toString();
        }
        return "\n[ERRO]\n";
    }
}
