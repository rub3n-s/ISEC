//
//  Aquario.cpp
//  f6_01
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Aquario.hpp"

bool Aquario::addPeixe(Peixe *p) {
    if (p == nullptr)
        return false;
    if (p->ligaAaquario(this) == false)
        return false;
    peixes.push_back(p);
    return true;
}
