//
//  ABC.hpp
//  f5_02
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef ABC_hpp
#define ABC_hpp

#include <stdio.h>
#include <string>

using namespace std;

class ABC {
    char *p;
    
public:
    ABC(const char *s);/* {
        p  = new char[strlen(s) + 1];
        strcpy(p, s);
    } */
    ABC(const ABC &o);
    ~ABC();
    
    ABC &operator=(const ABC &a);
    
    const char *getConteudo() const { return p; }
};

#endif /* ABC_hpp */
