//
//  Triangulo.cpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Triangulo.hpp"
#include <sstream>

Triangulo::Triangulo(string n, Ponto vID, Ponto vIE, Ponto vSUP) : nome(n), verticeID(vID), verticeIE(vIE), verticeSUP(vSUP) {
    cout << "construindo: " << getAsString();
}

string Triangulo::getAsString() const {
    ostringstream os;
    os << "nome: " << nome << ", vertice IE: (" << verticeIE.getX() << "," << verticeIE.getY() << ")" << ", vertice ID: (" << verticeID.getX() << "," << verticeID.getY() << ")" << ", vertice SUP: (" << verticeSUP.getX() << "," << verticeSUP.getY() << ")" << endl;
    return os.str();
}
