//
//  main.cpp
//  f2_04 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
};

Caderno preenche(string ma, string co, int nF, int alt, int larg) {
    Caderno c;
    
    c.marca = ma;
    c.cor = co;
    c.nFolhas = nF;
    c.altura = alt;
    c.largura = larg;
    
    return c;
}

void getAsString(Caderno c) {
    cout << "marca: " << c.marca << ", cor: " << c.cor << ", altura: " << c.altura << ", largura: " << c.largura << endl;
}

int main(int argc, const char * argv[]) {
    Caderno c;
    
    c = preenche("Oxford", "Verde", 250, 80, 50);
    getAsString(c);
    
    return 0;
}
