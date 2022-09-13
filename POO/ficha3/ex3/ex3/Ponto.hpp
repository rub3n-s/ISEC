//
//  Ponto.hpp
//  ex3
//
//  Created by rsantos on 03/11/2021.
//

#ifndef Ponto_hpp
#define Ponto_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

class Ponto {
    int xCor;
    int yCor;
    
public:
    Ponto(int x, int y);
    ~Ponto();
    
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    double distancia(Ponto a);
    string getAsString() const;
};

#endif /* Ponto_hpp */
