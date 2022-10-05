//
//  apressado.cpp
//  f7_04
//
//  Created by rsantos on 05/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "apressado.hpp"
#include <sstream>

int Apressado::calculaPagamento() {
    int total = 0, dur;
    int n = getNumTreinos();
    
    for(size_t i = 0; i < n; i++) {
        dur = getDuracoesTreinosI(i);
        
        if (dur <= 10)
            total += 10;
        else if (dur <= 20)
            total += 15;
        else // (dur > 20)
            total += 25;
    }
    
    apagaTreinos();
    return total;
}

string Apressado::getAsString() const {
    ostringstream os;
    os << "Apressado: " << Tarifario::getAsString();
    return os.str();
}

ostream &operator<<(ostream &os, const Apressado &t) {
    os << t.getAsString();
    return os;
}
