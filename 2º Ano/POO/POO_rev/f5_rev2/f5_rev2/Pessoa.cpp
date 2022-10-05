//
//  Pessoa.cpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"
#include <sstream>

Pessoa::Pessoa(string n) : nome(n) {}

string Pessoa::getAsString() const {
    ostringstream os;
    os << "nome: " << nome << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Pessoa &p) {
    os << p.getAsString();
    return os;
}
