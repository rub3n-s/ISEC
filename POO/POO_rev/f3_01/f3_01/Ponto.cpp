//
//  Ponto.cpp
//  f3_01
//
//  Created by rsantos on 20/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Ponto.hpp"
#include <cmath>
#include <iostream>
#include <sstream>

Ponto::Ponto(int xx, int yy) : x(xx), y(yy) {}

double Ponto::distanciaPontos(Ponto p2) {
    double distancia;
    distancia = sqrt((p2.getX() - x)*(p2.getX() - x) + (p2.getY() - y)*(p2.getY() - y));
    
    return distancia;
}

Ponto::~Ponto() {}

string Ponto::getAsString() const {
    return "( " + to_string(x) + ", " + to_string(y) + " ) ";
}
