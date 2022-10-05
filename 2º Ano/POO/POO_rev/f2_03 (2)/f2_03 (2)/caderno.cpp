//
//  caderno.cpp
//  f2_03 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "caderno.hpp"
#include <sstream>

Caderno::Caderno(string m, string c, int nF, int alt, int larg)
    :  marca(m), cor(c), nFolhas(nF), altura(alt), largura(larg) {}

string Caderno::getAsString() const {
    ostringstream os;
    os << "marca: " << marca << ", cor: " << cor << ", nFolhas: " << nFolhas << ", altura: " << altura << ", largura: " << largura;
    return os.str();
}
