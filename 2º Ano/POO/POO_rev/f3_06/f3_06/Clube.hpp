//
//  Clube.hpp
//  f3_06
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Clube_hpp
#define Clube_hpp

#include <vector>
#include "Pessoa.hpp"

class Clube {
    string nome;
    string descricao;
    vector<Pessoa> pessoas;
    
public:
    Clube(string n, string desc);
    
    string getAsString() const;
    void addPessoa(Pessoa p);
};

#endif /* Clube_hpp */
