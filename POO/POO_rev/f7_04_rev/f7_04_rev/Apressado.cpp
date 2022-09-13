//
//  Apressado.cpp
//  f7_04_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Apressado.hpp"
#include <sstream>

int Apressado::calculaPagamento() {
    int dur = 0, total = 0;
    size_t n = getNumTreinos();
    
    for (size_t i = 0; i < n; ++i)
        dur += getDuracaoTreinoI(i);
    
    if (dur <= 10)
        total += 10;
    else if (dur <= 20)
        total += 15;
    else
        total += 25;
    
    apagaTreinos();
    return total;
}

string Apressado::getAsString() const {
    ostringstream os;
    os << "Apressado: " << Tarifario::getAsString();
    return os.str();
}

ostream &operator<<(ostream &os, const Apressado &a) {
    os << a.getAsString();
    return os;
}
