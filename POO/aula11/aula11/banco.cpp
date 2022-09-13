//
//  banco.cpp
//  aula11
//
//  Created by rsantos on 10/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "banco.hpp"
#include <sstream>

string Banco::getAsString() const {
    ostringstream os;
    
    os << nome << " ";
    for (auto c: contas)
        os << " \n" << c.getAsString();
    
    return os.str();
}

//Falta - verificar se a conta é unica
bool Banco::addConta(Conta c) {
    contas.push_back(c);
    return true;
}
