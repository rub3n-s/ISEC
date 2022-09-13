//
//  Ponto.hpp
//  f3_01
//
//  Created by rsantos on 20/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Ponto_hpp
#define Ponto_hpp

#include <string>
using namespace std;

class Ponto {
    int x;
    int y;
    
public:
    Ponto(int xx = 0, int yy = 0);
    ~Ponto();
    
    string getAsString() const;
    int getX() const { return x;}
    int getY() const { return y;}
    void setX(int xx) { x = xx; }
    void sety(int yy) { y = yy; }
    double distanciaPontos(Ponto p2);
};

#endif /* Ponto_hpp */
