//
//  Ponto.hpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Ponto_hpp
#define Ponto_hpp

#include <iostream>

using namespace std;

class Ponto {
    int x;
    int y;
    
public:
    Ponto(int xx = 0, int yy = 0);
    
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int xx) { x = xx; }
    void setY(int yy) { y = yy; }
    
    double distancia(Ponto p);
    string getAsString() const;
};

#endif /* Ponto_hpp */
