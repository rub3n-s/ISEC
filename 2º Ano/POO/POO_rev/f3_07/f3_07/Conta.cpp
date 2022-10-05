//
//  Conta.cpp
//  f3_07
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Conta.hpp"
#include <sstream>

Conta::Conta(int s, Pessoa p) : saldo(s), titular(p.getNome(), p.getBI(), p.getContribuinte()) {}

string Conta::getAsString() const {
    ostringstream os;
    os << "Conta de '" << titular.getNome() << "', com saldo: " << saldo << endl;
    return os.str();
}
