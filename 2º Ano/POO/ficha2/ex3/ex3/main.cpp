//
//  main.cpp
//  ex3
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>

using namespace std;
struct Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
} caderno;

Caderno preencheCaderno(string m, string co, int nF, int al, int lar) {
    Caderno c;
    c.marca = m;
    c.cor = co;
    c.nFolhas = nF;
    c.altura = al;
    c.largura = lar;
    return c;
}

string getMarca(Caderno c) { return c.marca; }
string getCor(Caderno c) { return c.cor; }
int getNF(Caderno c) { return c.nFolhas; }
int getAltura(Caderno c) { return c.altura; }
int getLargura(Caderno c) { return c.largura; }

Caderno setMarca(Caderno c, string m) {
    c.marca = m;
    return c;
}

void mostraCaderno(Caderno c) {
    cout << "marca: " << c.marca << ", cor: " << c.cor << ", n. folhas: " << c.nFolhas << ", altura: " << c.altura << ", largura: " << c.largura << endl;
}
int main(int argc, const char * argv[]) {
    Caderno c;
    
    c = preencheCaderno("Oxford", "Verde", 120, 80, 40);
    mostraCaderno(c);
    
    c = setMarca(c, "XPTO");
    mostraCaderno(c);
    
    return 0;
}
