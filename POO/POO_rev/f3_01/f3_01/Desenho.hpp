//
//  Desenho.hpp
//  f3_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Desenho_hpp
#define Desenho_hpp

#include "Retangulo.hpp"
#include <vector>

class Desenho {
    vector<Retangulo> figuras;
    string nome;
    
public:
    Desenho(string n);
    
    bool addFigura(Retangulo r);
    string getAsString() const;
    double somaAreas();
    void removeAreaMaior(double a);
};

#endif /* Desenho_hpp */
