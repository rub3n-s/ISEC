//
//  Pessoa.hpp
//  f5_rev2
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <string>
using namespace std;

class Pessoa {
    string nome;
    
public:
    Pessoa(string n);
    
    //string getNome() const { return nome; }
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Pessoa &p);

#endif /* Pessoa_hpp */
