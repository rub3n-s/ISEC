//
//  aquario.cpp
//  f6_01
//
//  Created by rsantos on 10/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <stdio.h>
#include "aquario.h"

string Aquario::getAsString() const {
    ostringstream os;
    
    if (peixes.size() == 0)
        os << "Aquario vazio.";
    else {
        os << "Peixes no aquario: \n";
        for (auto p: peixes)
            os << " " << p->getAsString() << "\n";
    }
    
    return  os.str();
}

Aquario::~Aquario() {
    for (auto p : peixes)
        delete p;
    peixes.clear();
}

ostream &operator<<(ostream &os, const Aquario &p) {
    os << p.getAsString();
    return os;
}

bool Aquario::addPeixe(Peixe *p) {
    if (p == nullptr)
        return false;
    if (p->ligaAaquario(this) == false)
        return false;
    
    peixes.push_back(p);
    return true;
}

void Aquario::alimentaPeixes(unsigned int c) {
    auto tam = peixes.size();
    for(auto i = 0; i < tam; i++) {
        peixes[i]->come(c);
    }
}

void Aquario::selfClean() {
    auto it = peixes.begin();
    while(it < peixes.end()) {
        if ((*it)->isVivo()) {
            ++it;
        } else {
            delete (*it);
            it = peixes.erase(it);
        }
    }
}

bool Aquario::peixeExiste(unsigned int n) const {
    for (auto p : peixes) {
        if (p->getNserie() == n)
            return true;
    }
    return false;
}

Peixe *Aquario::removePeixe(unsigned int n) {
    auto it = peixes.begin();
    while (it < peixes.end()) {
        if((*it)->getNserie() == n) {
            Peixe *out = *it;
            
            if ((*it)->desligaAquario(this) == false)
                return nullptr;
            
            peixes.erase(it);
            return out;
        }
        ++it;
    }
    
    return nullptr;
}
