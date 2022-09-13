//
//  Clube.cpp
//  f3_06
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Clube.hpp"
#include <sstream>
#include <iostream>

Clube::Clube(string n, string desc) : nome(n), descricao(desc) {}

void Clube::addPessoa(Pessoa p) {
    for (auto c : pessoas) {
        if (c.getBI() == p.getBI()) {
            cout << "Esta pessoa já está associada a um clube!" << endl;
            return;
        }
    }

    pessoas.push_back(p);
}

string Clube::getAsString() const {
    ostringstream os;
    os << "Clube: " << nome << endl;
    os << "Pessoas: " << endl;
    if (pessoas.empty())
        os << "Lista de pessoas vazia!" << endl;
    else
        for (auto p : pessoas)
            os << "\t" << p.getNome() << endl;
    return os.str();
}
