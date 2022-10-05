//
//  Imobiliaria.hpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Imobiliaria_hpp
#define Imobiliaria_hpp

#include <vector>
#include "Imovel.hpp"

class Imobiliaria {
    string nome;
    vector<Imovel *> imoveis;
    
public:
    Imobiliaria(string n) : nome(n) {}
    
    bool addImovel(Imovel *i);
    void getImovel(string codigo);
    void listarAndar(int an);
    
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Imobiliaria &i);
    
#endif /* Imobiliaria_hpp */
