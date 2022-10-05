//
//  Pessoa.cpp
//  f3_06
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Pessoa.hpp"
#include <sstream>
#include <iostream>

Pessoa::Pessoa(string n, int b, int c) : nome(n), bi(b), contribuinte(c) {}

string Pessoa::getAsString() const {
    ostringstream os;
    os << "Nome: " << nome << ", BI: " << bi << ", Contribuinte: " << contribuinte << endl;
    return os.str();
}
