//
//  Prego.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Prego_hpp
#define Prego_hpp

#include <iostream>

using namespace std;

class Prego{
    int x,y;
    
public:
    Prego(int a, int b) {
        x = a; y = b;
        cout << "construindo prego em " << x << "," << y << "\n";
    }
    
    ~Prego() { cout << "construindo prego em " << x << "," << y << "\n"; }
    
    void mudaDeSitio(int a, int b) {
        x = a; y = b;
    }
    
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif /* Prego_hpp */
