//
//  main.cpp
//  f3_08
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Pessoa.hpp"
#include "Turma.hpp"

void borrega() {
    string resposta;
    cout << "A Catarina é borrega?" << endl;
    cin >> resposta;
    if (resposta == "sim")
        cout << "Parabéns miserável, acertou!" << endl;
}
int main(int argc, const char * argv[]) {
    //Pessoa p1("Artur", 123, 345612346);
    //cout << p1.getAsString() << endl;
    
    // Turma 1
    Pessoa professor_1("Prof. Artur", 123456789, 125358376);
    Turma t1("Matemática", professor_1);
    cout << t1.getAsString() << endl; // turma vazia
    
    Pessoa a1("Rúben", 123456789, 125358376);
    Pessoa a2("Jeremias", 987654321, 063645272);
    Pessoa a3("Manuela", 123456789, 756478234);
    
    t1.addAluno(a1);
    t1.addAluno(a2);
    t1.addAluno(a3);
    
    cout << t1.getAsString() << endl; // turma com 3 alunos
    
    // Turma 2
    Pessoa professor_2("Prof. Tó", 123456789, 125358376);
    Turma t2("Portugês", professor_2);
    cout << t2.getAsString() << endl; // turma vazia
    
    Pessoa b1("Pedro", 123456789, 125358376);
    Pessoa b2("Matilde", 987654321, 063645272);
    Pessoa b3("Maria", 123456789, 756478234);
    
    t2.addAluno(b1);
    t2.addAluno(b2);
    t2.addAluno(b3);
    
    cout << t2.getAsString() << endl; // turma com 3 alunos
    
    return 0;
}
