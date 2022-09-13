//
//  imovel.cpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "imovel.hpp"
#include <sstream>

int Imovel::conta = 1;

string Imovel::getAsString() const {
    ostringstream os;
    os << "codigo: " << codigo << ", area: " << area << ", andar: " << andar << ", preco: " << preco;
    return os.str();
}

ostream &operator<<(ostream &os, const Imovel &i) {
    os << i.getAsString();
    return os;
}
