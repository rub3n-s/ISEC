//
//  ponto.h
//  f3_01
//
//  Created by rsantos on 29/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef ponto_h
#define ponto_h

#include <string>
#include <iostream>

using namespace std;

class Ponto {
    int x, y;
    
public:
    Ponto(int x = 0, int y = 0);
    ~Ponto();
    
    int getX() const;
    int getY() const;    
    double distancia(Ponto &p) const;
    string getAsString() const;
    
    void setX(int x);
    void setY(int y);
};

#endif /* ponto_h */
