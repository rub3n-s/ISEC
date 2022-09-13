//
//  ponto.cpp
//  11
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "ponto.hpp"
#include <sstream>



istream &operator>>(istream &is, Ponto &p) {
    is >> p.x >> p.y;
    if (is.fail() == true) {
        p.x = 0;
        p.y = 0;
    }
    return is;
}

Ponto Ponto::operator++(int) { // incremento pós-fixo
    Ponto antes = *this;
    ++(*this);
    return antes;
}

Ponto &Ponto::operator+=(const Ponto &p) {
    *this = (*this) + p;
    return *this;
}

Ponto &Ponto::operator++() { // incremento pré-fixo
    ++x;
    ++y;
    
}

string Ponto::getAsString() const {
    ostringstream os;
    os << "(" << x << ", " << y << ")";
    return os.str();
}

Ponto operator+(const Ponto &a, const Ponto &b) {
    Ponto soma(a.getX() + b.getX(), a.getY() + b.getY());
    
    return soma;
}

bool operator==(const Ponto &a, const Ponto &b) {
    return ((a.getX() == b.getX() && a.getY() == b.getY()));
}

bool operator!=(const Ponto &a, const Ponto &b) {
    return !(a == b);
}

ostream &operator<<(ostream &os, const Ponto &p) {
    os << p.getAsString();
    return os;
}

Ponto &Ponto::operator++() {
    ++x;
    ++y;
    return *this;
}
