//
//  MSG.cpp
//  ex7
//
//  Created by rsantos on 29/10/2021.
//

#include "MSG.hpp"

int MSG::nObj = 0;

MSG::MSG() : letra('x'), numero(++nObj) {}

MSG::MSG(char l) : letra(l), numero(++nObj) {}

MSG::MSG(const MSG &z) {
    cout << "A contruir por copia... letra: " << letra << ", numero: " << -numero << endl;
}

MSG::~MSG() {
    cout << "A destruir -> letra: " << letra << ", numero: " << numero << endl;
}
string MSG::getAsString() const {
    ostringstream os;
    os << "letra: " << letra << ", numero: " << numero << endl;
    return os.str();
}
