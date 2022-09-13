//
//  MSG.cpp
//  f2_07 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "MSG.hpp"
#include <iostream>
#include <sstream>

int MSG::proxNumero = 1;

MSG::MSG(char c) : letra(c), numero(proxNumero++) {
    cout << "criado: \nletra: " << letra << ", numero: " << numero << endl;
}

MSG::MSG(const MSG &c) {
    letra = c.letra;
    numero = c.proxNumero;
    cout << "criado por cópia:\n letra: " << letra << " numero: " << numero << endl;
}

MSG::~MSG() {
    cout << "a destruir -> letra: " << letra << " numero: " << numero << endl;
}

string MSG::getAsString() const {
    ostringstream os;
    os << "letra: " << letra << " numero: " << numero << endl;
    return os.str();
}
