//
//  desenho.hpp
//  f3_01
//
//  Created by rsantos on 03/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef desenho_hpp
#define desenho_hpp

#include <stdio.h>
#include "retangulo.hpp"
#include <vector>

using namespace std;

class Desenho {
    string nome;
    vector<Retangulo> figuras;
        
public:
    Desenho(string n): nome(n) {}
    
    string getAsString() const;
    void removeAreaMaior(double a);
    bool addFigura(Retangulo r);
};

#endif /* desenho_hpp */
