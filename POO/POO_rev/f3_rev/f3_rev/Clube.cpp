//
//  Clube.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"
#include <sstream>

Clube::Clube(string n, string ativ) : nome(n), atividade(ativ) { }

void Clube::addPessoa(Pessoa p) {
    pessoas.push_back(p);
}

string Clube::getAsString() const {
    ostringstream os;
    os << "Clube: " << nome << ", Atividade: " << atividade;
    if (pessoas.empty())
        os << ", sem membros!" << endl;
    else {
        os << ", com os membros: \n";
        for (auto p : pessoas)
            os << p.getAsString() << endl;
    }
    return os.str();
}
