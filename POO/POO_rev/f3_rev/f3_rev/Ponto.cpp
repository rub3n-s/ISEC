//
//  Ponto.cpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Ponto.hpp"
#include <cmath>
#include <sstream>

Ponto::Ponto(int xx, int yy) : x(xx), y(yy) { }

double Ponto::distancia(Ponto p) {
    double dist = 0;
    dist = sqrt((this->getY() - this->getX()) * (this->getY() - this->getX()) + (p.getY() - p.getX()) * (p.getY() - p.getX()));
    return dist;
}

string Ponto::getAsString() const {
    ostringstream os;
    os << "(" << x << "," << y << ")" << endl;
    return os.str();
}
