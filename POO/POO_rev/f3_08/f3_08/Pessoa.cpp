//
//  Pessoa.cpp
//  f3_08
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"
#include <sstream>

Pessoa::Pessoa(string n, int bi, int cont) : nome(n), numBI(bi), numContribuinte(cont) {}

string Pessoa::getAsString() const {
    ostringstream os;
    os << "Nome: " << nome << ", BI: " << numBI << ", Contribuinte: " << numContribuinte;
    return os.str();
}
