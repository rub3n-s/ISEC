//
//  prego.hpp
//  f3_05
//
//  Created by rsantos on 05/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef prego_hpp
#define prego_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Prego{
    int x,y;
public:
    Prego(int a, int b);
    
    ~Prego();
    
    void mudaDeSitio(int a, int b);
    string getAsString() const;
    void mudaSitio(int a, int b);
    
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif /* prego_hpp */
