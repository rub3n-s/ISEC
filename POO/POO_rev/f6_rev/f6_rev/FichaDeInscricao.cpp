//
//  FichaDeInscricao.cpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "FichaDeInscricao.hpp"
#include <sstream>

FichaDeInscricao::FichaDeInscricao(Cidadao *i, int dest) : inscrito(i), destino(dest) {
    if (dest < 0 || dest > 2)
        dest = 0;
}

string FichaDeInscricao::getAsString() const {
    ostringstream os;
    os << "nome: " << inscrito->getNome() << ", vila: " << vilas[destino] << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const FichaDeInscricao &f) {
    os << f.getAsString();
    return os;
}
