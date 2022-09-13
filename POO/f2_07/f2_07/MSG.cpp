//
//  MSG.cpp
//  f2_07
//
//  Created by rsantos on 22/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "MSG.h"
#include <iostream>
#include <sstream>

using namespace std;

int MSG::proxNumero = 1;

MSG::MSG(char c): letra(c), numero(proxNumero++) {
    cout << "criado: letra: " << letra << " numero " << numero << endl;
}

MSG::~MSG() {
    cout << "destruido: letra: " << letra << " numero " << numero << endl;
}

MSG::MSG (const MSG &z) {
    letra = z.letra;
    numero = z.numero;
    cout << "criado por copia: letra: " << letra << " numero " << numero << endl;
}

string MSG::getAsString() const {
    ostringstream os;
    os << "Letra: " << letra << " numero " << numero;
    return os.str();
}
