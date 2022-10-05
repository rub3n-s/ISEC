//
//  Fraccao.cpp
//  f4_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Fraccao.hpp"
#include <sstream>

Fraccao::Fraccao(int num, int den) : numerador(num), denominador(den) {
    if (denominador <= 0)
        denominador = 1;
}

bool Fraccao::setDenominador(int den) {
    if (den <= 0)
        return false;
    denominador = den;
    return true;
}

Fraccao Fraccao::operator*(const Fraccao &f) {
    Fraccao m(numerador * f.numerador, denominador * f.denominador);
    return m;
}

/*Fraccao Fraccao::operator*(const Fraccao &a, const Fraccao &b) {
    Fraccao f(a.getNumerador() * b.getNumerador(), a.getDenominador() * b.getDenominador());
    return f;
} */

ostream &operator<<(ostream &os, const Fraccao f) {
    os << "(" << f.getNumerador() << "," << f.getDenominador() << ")" << endl;
    return os;
}

Fraccao operator==(const Fraccao &a, const Fraccao &f) {
    Fraccao m(f.getNumerador(), f.getDenominador());
    return m;
}

/*Fraccao &Fraccao::operator++() {
    numerador += denominador;
    return *this;
} */

Fraccao &Fraccao::operator+=(const Fraccao &a) {
    numerador += a.getNumerador();
    denominador += a.getDenominador();
    return *this;
}
