//
//  ParOrdenado.cpp
//  11
//
//  Created by rsantos on 17/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "ParOrdenado.h"

ostream &operator<<(ostream &os, const ParOrdenado &p) {
    os << "<" << p.getA() << ", " << p.getB() << ">";
    return os;
}
