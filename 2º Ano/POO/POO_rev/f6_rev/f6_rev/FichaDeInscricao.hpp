//
//  FichaDeInscricao.hpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef FichaDeInscricao_hpp
#define FichaDeInscricao_hpp

#include "Cidadao.hpp"
#include <vector>
#include <string>

class FichaDeInscricao {
    vector<string> vilas = {"Tocha","Mira","Febres"};
    int destino;
    Cidadao *inscrito;
    
public:
    FichaDeInscricao(Cidadao *i, int dest);
    
    string getAsString() const;
};

ostream &operator<<(ostream &os, const FichaDeInscricao &f);

#endif /* FichaDeInscricao_hpp */
