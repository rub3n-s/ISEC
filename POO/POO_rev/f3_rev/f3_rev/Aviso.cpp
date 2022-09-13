//
//  Aviso.cpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Aviso.hpp"
#include <sstream>

string Aviso::getAsString() const {
    ostringstream os;
    os << "texto: " << texto << endl;
    return os.str();
}

void Aviso::penduraEm(Prego p) {
    if (!pendurado) {
        cout << "Aviso pendurado no prego: (" << p.getX() << "," << p.getY() << ")" << endl;
        pendurado = true;
    }
    else
        cout << "Este aviso já está pendurado!";
}
