//
//  ex3_4.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex3_4.hpp"
#include <iostream>
#include <sstream>

/*Caderno preenche(string marca, string cor, int nFolhas, int altura, int largura) {
    Caderno c;
    c.marca = marca;
    c.cor = cor;
    c.nFolhas = nFolhas;
    c.altura = altura;
    c.largura = largura;
    return c;
}

void mostra(Caderno c) {
    cout << "Marca: " << c.marca << ", Cor: " << c.cor << ", Folhas: " << c.nFolhas <<
    ", Altura: " << c.altura << ", Largura: " << c.largura << endl;
} */

Caderno::Caderno(string m, string c, int nF, int alt, int larg)
: marca(m), cor(c), nFolhas(nF), altura(alt), largura(larg) { }

string Caderno::getAsString() const {
    ostringstream os;
    os << "Marca: " << marca << ", Cor: " << cor << ", nFolhas: " << nFolhas << ", Altura: " << altura << ", Largura: " << largura << endl;
    return os.str();
}
