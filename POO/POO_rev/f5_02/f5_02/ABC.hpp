//
//  ABC.hpp
//  f5_02
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ABC_hpp
#define ABC_hpp
#include <string>

using namespace std;

class ABC {
    char * p;
    
public:
    ABC(char * s) {
        p = new char[strlen(s)+1];
        strcpy(p,s);
    }
    
    ~ABC() {
        delete []p;
    }
    
    const char * getConteudo() const { return p; }
};

#endif /* ABC_hpp */
