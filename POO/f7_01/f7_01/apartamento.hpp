//
//  apartamento.hpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef apartamento_hpp
#define apartamento_hpp

#include "imovel.hpp"

class Apartamento : public Imovel {
    int assoalhadas;
    
public:
    Apartamento(int area, int andar, int quartos) :
        Imovel(10 * area, area, andar, "apartamento"), assoalhadas(quartos) {}
    int getQuartos() const { return assoalhadas; }
};
#endif /* apartamento_hpp */
