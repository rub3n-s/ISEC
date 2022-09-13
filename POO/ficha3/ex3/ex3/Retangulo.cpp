//
//  Retangulo.cpp
//  ex3
//
//  Created by rsantos on 03/11/2021.
//

#include "Retangulo.hpp"

Retangulo::Retangulo(Ponto cse, int comp, int alt) : cantoSE(cse), comprimento(comp), altura(alt) {
    
}

string Retangulo::getAsString() const {
    ostringstream os;
    os << "altura: " << altura << "; comprimento: " << comprimento << "\n" << endl;
    os << "(" << cantoSE.getX() << "," << cantoSE.getY() << ")\t\t(" << cantoSE.getX() + comprimento << "," << cantoSE.getY() << ")" << endl;
    os << "(" << cantoSE.getX()-altura << "," << cantoSE.getY() << ")\t\t(" << cantoSE.getX() << "," << cantoSE.getY() + comprimento << ")" <<endl;
    return os.str();
}
