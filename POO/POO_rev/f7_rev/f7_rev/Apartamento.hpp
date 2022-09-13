//
//  Apartamento.hpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Apartamento_hpp
#define Apartamento_hpp
#include "Imovel.hpp"

#include <string>
using namespace std;

class Apartamento : public Imovel {
    int assoalhadas;
    
public:
    Apartamento(int ar, int nA, int an);
    
    int getQuartos() const { return assoalhadas; }
};

#endif /* Apartamento_hpp */
