import java.util.ArrayList;
import java.util.Map;

public class Turma {
    Map<String,ArrayList<Integer>> alunos;

    public Turma() {
        alunos = new HashMap<>();
    }

    public boolean addAluno(String nome, int numero) {
        if (nome != null && numero > 0 && !alunos.containsKey(nome)) {
            alunos.put(nome, numero);
            return true;
        }
        return false;
    }

    public boolean addNota(String nome, int nota) {
        if (nome != null && nota >= 0 && nota <= 100 && alunos.containsKey(nome)) {
            for (var a : alunos.entrySet())
                if (a.getKey()==nome)
                    a.setValue(nota);
            return true;
        }
        return false;
    }

    public int getNotaTeste(String nome, int teste) {
        for (var a: alunos.entrySet())
            if (a.getKey()==nome)
                return a.getValue().name().indexOf(teste);
    }
}
