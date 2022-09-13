//
//  Ponto.cpp
//  ex1
//
//  Created by rsantos on 03/11/2021.
//

#include "Ponto.hpp"


Ponto::Ponto(int x, int y) : xCor(x), yCor(y) {}

int Ponto::getX() const { return xCor; }

int Ponto::getY() const { return yCor; }

void Ponto::setX(int x) { xCor = x; }

void Ponto::setY(int y) { yCor = y; }

double Ponto::distancia(Ponto a) {
    double distancia = 0;
    distancia = sqrt((a.getX()-xCor)*((a.getX()-xCor) + (a.getY()-yCor)*(a.getY()-yCor)));
    return distancia;
}

string Ponto::getAsString() const {
    ostringstream os;
    os << "(" << xCor << "/" << yCor << ")" << endl;
    return os.str();
}
