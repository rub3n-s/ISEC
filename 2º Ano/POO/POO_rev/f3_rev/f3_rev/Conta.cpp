//
//  Conta.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Conta.hpp"
#include <sstream>

Conta::Conta(int s, Pessoa p) : saldo(s), titular(p.getNome(), p.getBI(), p.getContribuinte()){
    if (s < 0)
        saldo = 0;
}

bool Conta::aumentaSaldo(int valor) {
    if (valor < 0)
        return false;
    saldo+=valor;
    return true;
}

bool Conta::diminuiSaldo(int valor) {
    if (valor < 0 || valor > saldo)
        return false;
    saldo-=valor;
    return true;
}

string Conta::getAsString() const {
    ostringstream os;
    os << "titular: " << titular.getNome() << ", saldo: " << saldo << endl;
    return os.str();
}
