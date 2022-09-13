//
//  Aquario.hpp
//  f6_01
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Aquario_hpp
#define Aquario_hpp

#include "Peixe.hpp"
#include <vector>

class Aquario {
    string nome;
    vector<Peixe *> peixes;
    
public:
    Aquario() = default;
    Aquario(const Aquario &) = delete;
    
    
    bool addPeixe(Peixe *p);
};

#endif /* Aquario_hpp */
