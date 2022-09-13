//
//  Triangulo.cpp
//  ex2
//
//  Created by rsantos on 03/11/2021.
//

#include "Triangulo.hpp"

//int Triangulo::identificador = 0;

Triangulo::Triangulo(Ponto a, Ponto b, Ponto c) : x(a), y(b), z(c) {
    cout << "a construir..." << endl;
}
Triangulo::~Triangulo() {
    cout << "a destruir..." << endl;
}

string Triangulo::getPonto(Ponto p) { return p.getAsString(); }

string Triangulo::getAsString() const {
    ostringstream os;
    os << "Triangulo " << x.getAsString() << ", " << y.getAsString() << ", " << z.getAsString() << endl;
    return os.str();
}
