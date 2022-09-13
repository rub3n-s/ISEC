//
//  Agenda.cpp
//  f5_08
//
//  Created by rsantos on 26/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "Agenda.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

bool Agenda::repetido(const string &nome) {
    for (auto c : lista)
        if (c->getNome() == nome)
            return true;
    return false;
}

bool Agenda::adicionaContacto(const string &nome, unsigned int tel) {
    if (repetido(nome))
        return false;
    
    lista.push_back(new Contacto(nome, tel));
    return true;
}

Agenda::~Agenda() {
    for (auto c : lista)
        delete c;
    
    cout << "A destruir...\n";
}

Agenda &Agenda::operator=(const Agenda &a) {
    if (this == &a)
        return *this;
    
    for (auto v: lista) //eliminar os objetos
        delete v;
    
    lista.clear(); //retirar os ponteiros da lista
   
    for (auto v: a.lista) {
        Contacto *pc = new Contacto(*v);
        lista.push_back(pc);
    }
    
    return *this;
}
string Agenda::getAsString() const {
    ostringstream os;
    
    for (auto c : lista)
        os << " " << c->getNome() << " " << c->getTel() << "\n";
    
    return os.str();
}

ostream &operator<<(ostream &os, const Agenda &a) {
    os << a.getAsString();
    return os;
}

bool Agenda::gravaAgenda(const string &nomeFich) {
    ofstream of(nomeFich);
    
    if (!of)
        return false;
    
    of << *this;
    of.close();
    
    return true;
}
