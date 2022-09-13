//
//  Imovel.cpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Imovel.hpp"
#include <sstream>

int Imovel::conta = 1;

Imovel::Imovel(int pr, int ar, int an, string tipo) : preco(pr), area(ar), andar(an), codigo(tipo+to_string(conta++)) {}


string Imovel::getAsString() const {
    ostringstream os;
    os << "codigo: " << codigo << ", area: " << area << ", preco: " << preco << ", andar: " << andar << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Imovel &i) {
    os << i.getAsString();
    return os;
}
