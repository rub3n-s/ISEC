//
//  cliente.cpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//
#include <sstream>
#include "cliente.hpp"

Cliente &Cliente::operator=(const Cliente &c) {
    if (this == &c)
        return *this;
    if(tarifario) {
        delete tarifario;
        tarifario = nullptr;
    }
    nome = c.nome;
    cc = c.cc;
    inicio = c.inicio;
    aTreinar = c.aTreinar;
    if (c.tarifario)
        tarifario = c.tarifario->clone();
    return *this;
}

Cliente::Cliente(const Cliente &c) {
    *this = c;
}

string Cliente::getAsString() const {
    ostringstream os;
    
    os << nome << "\tcc: " << cc << " ";
    if (tarifario)
        os << *tarifario;
    
    return os.str();
}

ostream &operator<<(ostream &os, const Cliente &c) {
    os << c.getAsString();
    return os;
}

bool Cliente::iniciaTreino(int i) {
    if (aTreinar)
        return false;
    inicio = i;
    aTreinar = true;
    return true;
}

bool Cliente::terminaTreino(int f) {
    if (!aTreinar || !tarifario || f < inicio)
        return false;
    aTreinar = false;
    tarifario->acrescentaTreinos(f - inicio);
    return true;
}

int Cliente::paga() {
    if (!tarifario)
        return -1;
    return tarifario->calculaPagamento();
}
