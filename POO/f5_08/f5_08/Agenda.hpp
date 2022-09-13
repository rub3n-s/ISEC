//
//  Agenda.hpp
//  f5_08
//
//  Created by rsantos on 26/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef Agenda_hpp
#define Agenda_hpp

#include <stdio.h>
#include <vector>
#include "Contacto.hpp"

class Agenda {
    vector<Contacto *> lista;  // os elementos não usados ficarão a NULL
    
    bool repetido(const string &nome);
    
public:
    Agenda() {}
    Agenda (const Agenda &a) { *this = a; }
    ~Agenda();
    
    Agenda &operator=(const Agenda &a);
    
    bool gravaAgenda(const string &nomeFich);
    string getAsString() const;
    bool adicionaContacto(const string &nome, unsigned int tel);
    
    static Agenda leAgenda(const string &nomeFich);
};

ostream &operator<<(ostream &os, const Agenda &a);

#endif /* Agenda_hpp */
