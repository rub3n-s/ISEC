//
//  Retangulo.cpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Retangulo.hpp"
#include "Ponto.hpp"
#include <sstream>

Retangulo::Retangulo(int alt, int larg, Ponto cantoSE) : altura(alt), largura(larg), cse(cantoSE) {
    if (alt <= 0 || larg <= 0) {
        altura = 1;
        largura = 1;
    }
    cout << "contruindo: " << getAsString();
}

Retangulo::~Retangulo() {
    cout << "a destruir..." << getAsString();
}

string Retangulo:: getAsString() const {
    ostringstream os;
    //os << "altura: " << altura << ", largura: " << largura << ", CSE: (" << cse.getX() << "," << cse.getY() << ")" << endl;
    os << "altura: " << altura << ", largura: " << largura << ", CSE: " << cse.getAsString();
    return os.str();
}
