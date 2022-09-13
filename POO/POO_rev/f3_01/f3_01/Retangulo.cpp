//
//  Retangulo.cpp
//  f3_01
//
//  Created by rsantos on 20/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Retangulo.hpp"
#include <iostream>
#include <sstream>

Retangulo::Retangulo(const Ponto &p, double alt, double larg) : cse(p.getX(), p.getY()), altura(alt), largura(larg) {
    if (altura < 0)
        altura = -altura;
    if (largura < 0)
        largura = -largura;
    
    cout << " a construir: " << getAsString() << "\n";
}

Retangulo::~Retangulo() {
    cout << "a destruir " << getAsString() << endl;
}

string Retangulo::getAsString() const {
    ostringstream os;
    os << "retangulo com canto: " << cse.getAsString();
    os << ", largura: " << largura << ", altura: " << altura;
    return os.str();
}

void Retangulo::setCanto(const Ponto &nc) {
    cse = nc;
}
