//
//  ABC.cpp
//  f5_02
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "ABC.hpp"


//Estas duas funções são uma alternativa porque o codigo pode dar erro em Windows
void copiaCaracteres(char *d, const char *o) {
    size_t tam = strlen(o);
    
    for(size_t i = 0; i < tam; i++)
        d[i] = o[i];
    d[tam] = o[tam];
}

ABC::ABC(const char *s) {
    p  = new char[strlen(s) + 1];
    copiaCaracteres(p, s);
}

ABC::~ABC() {
    delete[] p;
}

ABC &ABC::operator=(const ABC &a) {
    if (this == &a)
        return *this;
    
    
    char *copia = new char[strlen(a.p) + 1];
    copiaCaracteres(copia, a.p);
    
    if (p != nullptr)
        delete p;
    
    p = copia;
    
    return *this;
}

ABC::ABC(const ABC &o) {
    p = nullptr;
    *this = o;
}
