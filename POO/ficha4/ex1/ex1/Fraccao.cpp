//
//  Fraccao.cpp
//  ex1
//
//  Created by rsantos on 17/11/2021.
//

#include "Fraccao.hpp"

Fraccao::Fraccao() {
    numerador = 0;
    denominador = 1;
}

Fraccao::Fraccao(int n, int d) : numerador(n), denominador(d) {
    if (d <= 0)
        denominador = 1;
}

Fraccao Fraccao::operator+(const Fraccao& f) {
    Fraccao r;
    r.numerador = (numerador*f.denominador) + (f.numerador*denominador);
    r.denominador = (f.denominador*denominador);
    return r;
}

Fraccao Fraccao::operator*(const Fraccao& f) {
    Fraccao r;
    r.numerador = (numerador*f.numerador);
    r.denominador = (f.denominador*denominador);
    return r;
}

string Fraccao::getAsString() const {
    ostringstream os;
    os << "Fraccao " << numerador << "/" << denominador << "\n";
    return os.str();
}

void Fraccao::setNumerador(int n) { numerador = n; }
void Fraccao::setDenominador(int d) { denominador = d; }
int Fraccao::getNumerador() const { return numerador; }
int Fraccao::getDenominador() const { return denominador; }
