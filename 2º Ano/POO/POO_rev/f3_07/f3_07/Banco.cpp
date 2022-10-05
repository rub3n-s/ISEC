//
//  Banco.cpp
//  f3_07
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Banco.hpp"
#include <sstream>

Banco::Banco(string n) : nome(n) {}

void Banco::addConta(Conta c) {
    contas.push_back(c);
}

string Banco::getAsString() const {
    ostringstream os;
    os << "Banco: " << nome << endl;
    os << "Contas: " << endl;
    for (auto c : contas)
        os << c.getAsString();
    return os.str();
}

void Banco::getConta(int b) {
            
}

void Banco::deposito(int quant) {
    c.saldo += quant;
}
