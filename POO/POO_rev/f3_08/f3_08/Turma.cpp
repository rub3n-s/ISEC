//
//  Turma.cpp
//  f3_08
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Turma.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Turma::Turma(string t, const Pessoa &prof) : turma(t), professor(prof) {}

string Turma::getAsString() const {
    ostringstream os;
    os << "Turma: " << turma << endl;
    os << "Professor: " << professor.getNome() << endl;
    os << "Alunos: " << endl;
    if (alunos.empty())
        os << "\nLista de alunos vazia.\n";
    for (auto a: alunos)
        os << a.getAsString() << endl;
    return os.str();
}

void Turma::removeAluno(int bi) {
    auto i = this->alunos.begin();
    while (i != this->alunos.end()) {
        if (i->getBI() == bi)
            this->alunos.erase(i);
        else
            ++i;
    }
}

void Turma::addAluno(Pessoa p) {
    alunos.push_back(p);
}
