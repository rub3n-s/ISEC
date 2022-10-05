//
//  Pessoa.hpp
//  f5_rev
//
//  Created by rsantos on 10/02/2021.
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
    
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Pessoa &p);

#endif /* Pessoa_hpp */
