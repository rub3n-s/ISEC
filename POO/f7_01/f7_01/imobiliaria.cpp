//
//  imobiliaria.cpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "imobiliaria.hpp"
#include <sstream>

bool Imobiliaria::addImovel(Imovel *i) {
    if (i == nullptr)
        return false;
    
    imoveis.push_back(i);
    return true;
}

string Imobiliaria::getAsString() const {
    ostringstream os;
    os << "nome: \n";
    
    for (auto i: imoveis)
        os << " " << *i << endl;
    
    return os.str();
}

ostream &operator<<(ostream &os, Imobiliaria &i) {
    os << i.getAsString();
    return os;
}
