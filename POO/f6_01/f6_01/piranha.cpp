//
//  piranha.cpp
//  f6_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "piranha.hpp"

ostream &operator<<(ostream &os, const Piranha &p) {
    os << p.getAsString() << " ,comprimento: " << p.getComprimento() << endl;
    return os;
}

string Piranha::getAsString() const {
    ostringstream os;
    os << Peixe::getAsString() << ", comprimento " << comprimento;
    return os.str();
}
