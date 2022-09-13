//
//  Fraccao.cpp
//  f4_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Fraccao.hpp"
#include <sstream>

Fraccao::Fraccao(int n, int d) : numerador(n), denominador(d) {
    if (d <= 0)
        denominador = 1;
}

string Fraccao::getAsString() const {
    ostringstream os;
    os << numerador << "/" << denominador << endl;
    return os.str();
}

Fraccao operator*(const Fraccao &a, const Fraccao &b) {
    Fraccao aux(a.getNum() * b.getNum(), a.getDen() * b.getDen());
    return aux;
}

/*Fraccao Fraccao::operator*(Fraccao &c) {
    Fraccao aux(numerador * c.getNum(), denominador * c.getDen());
    return aux;
} */

Fraccao &Fraccao::operator++() {
    numerador += denominador;
    return *this;
}

ostream &operator<<(ostream &os, const Fraccao &f) {
    os << f.getAsString();
    return os;
}

Fraccao operator==(const Fraccao &a, const Fraccao &f) {
    Fraccao aux(f.getNum(), f.getDen());
    return aux;
}

/*Fraccao &operator+=(const Fraccao &a, const Fraccao &f) {
    Fraccao aux(a.getNum() + f.getNum(), a.getDen() + f.getDen());
    return aux;
}*/

Fraccao &Fraccao::operator*=(const Fraccao &a) {
    numerador *= a.getNum();
    denominador *= a.getDen();
    return *this;
}
