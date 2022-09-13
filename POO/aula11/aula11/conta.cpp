//
//  conta.cpp
//  aula11
//
//  Created by rsantos on 10/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "conta.hpp"
#include <sstream>

bool Conta::levanta(int quantia) {
    if (quantia < 0 || quantia > saldo)
        return false;
    saldo -= quantia;
    return true;
}

bool Conta::deposita(int quantia) {
    if (quantia < 0 || quantia > saldo)
        return false;
    saldo += quantia;
    return true;
}

string Conta::getAsString const {
    std::ostringstream os;
    
    os << titular.getAsString() << " , saldo" << saldo.getAsString();
}
