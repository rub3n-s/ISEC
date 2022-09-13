//
//  ex7.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex7.hpp"
#include <sstream>
#include <iostream>

MSG::MSG(char l) : letra(l), num(++contador) {
    cout << "a construir..." << endl;
}

MSG::MSG(const MSG &c) {
    cout << "construindo por copia: " << endl;
    letra = c.letra;
    num = ++contador;
}

string MSG::getAsString() const {
    ostringstream os;
    os << "letra: " << letra << ", num: " << num << endl;
    return os.str();
}
