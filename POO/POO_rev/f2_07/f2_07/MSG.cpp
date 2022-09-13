//
//  MSG.cpp
//  f2_07
//
//  Created by rsantos on 01/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "MSG.hpp"
#include <sstream>
#include <iostream>

int MSG::proxNumero = 1;

string MSG::getAsString() const {
    ostringstream os;
    os << "letra: " << letra << " numero: " << proxNumero;
    return os.str();
}

MSG::MSG(char c) : letra(c), numero(proxNumero++){
    cout << "criado -> letra: " << letra << " numero: " << numero << "\n";
}

MSG::MSG(const MSG &z) {
    letra = z.letra;
    numero = z.numero;
    cout << "criado por cópia -> letra: " << letra << " numero: " << numero << "\n";
}

MSG::~MSG() {
    cout << "destruido -> letra: " << letra << " numero: " << numero << "\n";
}
