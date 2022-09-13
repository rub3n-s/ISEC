//
//  main.cpp
//  f2_03
//
//  Created by rsantos on 21/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

class Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
    
public:
    Caderno(string marca, string cor, int nFolhas, int altura, int largura);
    
    void mostraCaderno() const;
    
    string setMarca(string novoNome);
    string setCor(string novaCor);
    int setFolhas(int novoNF);
    int setAltura(int novaAlt);
    int setLargura(int novaLarg);
};

Caderno::Caderno(string m, string c, int nF, int alt, int larg):
marca(m), cor(c), nFolhas(nF),altura(alt), largura(larg) {
    if (nF >= 1)
        nFolhas = nF;
    else
        nFolhas = 1;
    //conteudo = "Pag 1:";
}

void Caderno::mostraCaderno() const{
    cout << "Marca: " << marca << "\nCor: " << cor << "\nFolhas: " << nFolhas << "\nAltura: "
    << altura << "\nLargura: " << largura << endl;
}

string Caderno::setMarca(string novoNome) {
    return marca = novoNome;
}

string Caderno::setCor(string novaCor) {
    return cor = novaCor;
}

int Caderno::setFolhas(int novoNF) {
    return nFolhas = novoNF;
}

int Caderno::setAltura(int novaAlt) {
    return nFolhas = novaAlt;
}

int Caderno::setLargura(int novaLarg) {
    return nFolhas = novaLarg;
}

int main(int argc, const char * argv[]) {
    Caderno c("Oxford", "Verde", 80, 20, 10);
    
    c.mostraCaderno();
    cout << endl;
    
    c.setCor("Amarelo");
    c.mostraCaderno();
    
    return 0;
}
