import turma.*;

public class App {
    public static void main(String[] args) throws Exception {
        Turma t = new Turma();
        t.addAluno("José", 201301); //nome, nº de aluno
        t.addAluno("Luis", 201303);
        t.addAluno("Ana", 201302);
        t.addNota("Luis", 65); //nota do 1º teste do Luis
        t.addNota(201303, 80); //nota do 2º teste do Luis
        t.addNota("Luis", 85); //nota do 3º teste do Luis
        System.out.println(t.getNotaTeste(201303, 3)); //nota do 3º teste do Luis
        System.out.println(t.getNotaTeste("Luis", 2)); //nota do 2º teste do Luis
    }
}
