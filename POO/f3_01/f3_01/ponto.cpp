//
//  ponto.cpp
//  f3_01
//
//  Created by rsantos on 29/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <math.h>
#include "ponto.h"

using namespace std;

Ponto::Ponto(int xx, int yy): x(xx), y(yy) {
    //cout << " a construir " << getAsString() << "\n";
}

Ponto::~Ponto() {
    //cout << " a destruir " << getAsString() << "\n";
}

string Ponto::getAsString() const {
    return "( " + to_string(x) + ", " + to_string(y) + " ) ";
}

double Ponto::distancia(Ponto &p) const {
    double dist;
    
    dist = sqrt(((this->x - p.x) * (this->x - p.x)) + (this->y - p.y) * (this->y - p.y));
    
    return dist;
}

int Ponto::getX() const { return x; }
int Ponto::getY() const { return y; }

void Ponto::setX(int xx) { x = xx; }
void Ponto::setY(int yy) { y = yy; }
