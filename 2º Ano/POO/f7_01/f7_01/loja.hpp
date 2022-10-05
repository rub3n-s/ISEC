//
//  loja.hpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef loja_hpp
#define loja_hpp

#include "imovel.hpp"

class Loja : public Imovel {
public:
    Loja(int area) : Imovel(15 * area, area, 0, "loja") {}
    };
    
#endif /* loja_hpp */
