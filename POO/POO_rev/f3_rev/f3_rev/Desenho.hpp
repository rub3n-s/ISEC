//
//  Desenho.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
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
    int somaAreas();
    void removeAreaMaior(int a);
};

#endif /* Desenho_hpp */
