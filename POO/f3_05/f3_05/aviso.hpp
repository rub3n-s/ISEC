//
//  aviso.hpp
//  f3_05
//
//  Created by rsantos on 05/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef aviso_hpp
#define aviso_hpp

#include <string>
#include <stdio.h>
#include "prego.hpp"

using std::string;

class Aviso {
    string msg;
    //Prego &p;
    Prego *p;
    
public:
    //Aviso(string s, Prego &pre);
    Aviso(string s, Prego *pre);
    ~Aviso();
    
    string getAsString() const;
    string getLocal() const;
};
        
#endif /* aviso_hpp */
