//
//  Contacto.hpp
//  f5_08
//
//  Created by rsantos on 26/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef Contacto_hpp
#define Contacto_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Contacto {
    string nome;
    unsigned int tel;

public: 
    Contacto(string n, unsigned int t) : nome(n), tel(t) {}
    
    string getNome() const { return nome; }
    int getTel() const { return tel; }
    void setNome(string s) { nome = s; }
    void setTel(unsigned int t) { tel = t; }
};

#endif /* Contacto_hpp */
