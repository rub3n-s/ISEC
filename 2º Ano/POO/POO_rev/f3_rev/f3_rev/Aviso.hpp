//
//  Aviso.hpp
//  f3_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Aviso_hpp
#define Aviso_hpp
#include "Prego.hpp"
#include <string>

class Aviso {
    string texto;
    bool pendurado = false;
    
public:
    Aviso(string t) : texto(t) {
        cout << "construindo: " << getAsString();
    }
    
    string getAsString() const;
    void penduraEm(Prego p);
};

#endif /* Aviso_hpp */
