//
//  Imobiliaria.cpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Imobiliaria.hpp"
#include <sstream>
#include <iostream>
#include <string>

bool Imobiliaria::addImovel(Imovel *i) {
    if (i == nullptr)
        return false;
    imoveis.push_back(i);
    return true;
}


void Imobiliaria::getImovel(string codigo) {
    for (auto i : imoveis) {
        if (i->getCodigo() == codigo)
            cout << *i << endl;
    }
}

void Imobiliaria::listarAndar(int an) {
    for (auto i : imoveis) {
        if (i->getAndar() == an)
            cout << *i;
    }
}

string Imobiliaria::getAsString() const {
    ostringstream os;
    os << "nome: " << nome << endl;
    for (auto i : imoveis)
        os << *i;
    return os.str();
}

ostream &operator<<(ostream &os, const Imobiliaria &i) {
    os << i.getAsString();
    return os;
}
