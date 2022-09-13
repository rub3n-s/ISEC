//
//  aviso.cpp
//  f3_05
//
//  Created by rsantos on 05/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "aviso.hpp"
#include <iostream>
#include <sstream>

Aviso::Aviso(string s, Prego *pre): msg(s), p(pre) {
    cout << "construindo " << getAsString();
}

Aviso::~Aviso() {
    cout << "destruindo " << getAsString();
}

string Aviso::getAsString() const {
    ostringstream os;
    
    os << "Aviso: " << msg << " em " << this->p->getAsString();
    
    return os.str();
}

string Aviso::getLocal() const {
    ostringstream os;
        
    os << "(" << this->p->getX() << ", " << this->p->getY() << ")\n";
    
    return os.str();
}
