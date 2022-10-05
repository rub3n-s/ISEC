//
//  fraccao.cpp
//  f4_01
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "fraccao.hpp"


Fraccao::Fraccao(int num, int den) : numerador(num), denominador(den) {
    if (denominador <= 0)
        denominador = 1;
    
}

bool Fraccao::setDenominador(int d) {
    if (d <= 0)
        return false;
    
    denominador = d;
    return true;
}

Fraccao Fraccao::operator*(const Fraccao &f) {
    Fraccao m(numerador * f.numerador, denominador * f.denominador);
    
    return m;
}

/*Fraccao operator*(const Fraccao &a, const Fraccao &f) {
    Fraccao m(a.getNumerador() * f.getNumerador(), a.getDenominador() * f.getDenominador());    
    return m;
}*/

ostream &operator<<(ostream &os, Fraccao f) {
    os << "(" << f.getNumerador() << ", " << f.getDenominador() << ")\n";
    return os;
}

Fraccao &Fraccao::operator++() {
    numerador += denominador;
    return *this;
}

