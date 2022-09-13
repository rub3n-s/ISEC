//
//  Pessoa.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"
#include <sstream>
#include <iostream>

Pessoa::Pessoa(string n, int b, int c) : nome(n), bi(b), contribuinte(c) { }

string Pessoa::getAsString() const {
    ostringstream os;
    os << "nome: " << nome << ", bi: " << bi << ", contribuinte: " << contribuinte;
    return os.str();
}
