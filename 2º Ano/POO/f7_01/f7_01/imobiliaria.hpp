//
//  imobiliaria.hpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef imobiliaria_hpp
#define imobiliaria_hpp

#include <vector>
#include "imovel.hpp"

class Imobiliaria {
    string nome;
    vector<Imovel *> imoveis;

public:
    Imobiliaria(string n) : nome(n) {}
    
    bool addImovel(Imovel *i);
    string getAsString() const;
};

ostream &operator<<(ostream &os, Imobiliaria &i);

#endif /* imobiliaria_hpp */
