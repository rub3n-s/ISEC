//
//  Turma.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Turma.hpp"
#include <sstream>

Turma::Turma(const Pessoa p) : professor(p) {}

bool Turma::addAluno(Pessoa a) {
    if (contador < 20) {
        contador++;
        alunos.push_back(a);
        return true;
    }
    else
        return false;
}

string Turma::getAsString() const {
    ostringstream os;
    os << "Professor: " << professor.getNome();
    if (alunos.empty())
        os << ", sem alunos!" << endl;
    else {
        os << ", com os alunos: \n";
        for (auto a : alunos)
            os << a.getNome() << endl;
    }
    return os.str();
}

void Turma::removeAluno(int bi) {
    auto i = alunos.begin();
    while (i != alunos.end()) {
        if (i->getBI() == bi)
            alunos.erase(i);
        else
            ++i;
    }
}
