//
//  main.cpp
//  ex4
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#define N 5

using namespace std;

class Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
    
public:
    Caderno(string m, string co, int nF, int alt, int larg) : marca(m), cor(co), nFolhas(nF), altura(alt), largura(larg) {}
    
    void mostraCaderno() const;
    
    string getMarca() const { return marca; }
    string getCor() const { return cor; }
    int getNFolhas() const { return nFolhas; }
    int getAltura() const { return largura; }
    
    void setMarca(string m) { marca = m; }
    void setCor(string c) { cor = c; }
    void setNFolhas(int nf) { nFolhas = nf; }
    void setAltura(int alt) { altura = alt; }
    void setLargura(int larg) { largura = larg; }
};

void Caderno::mostraCaderno() const {
    cout << "marca: " << marca << ", cor: " << cor << ", n. Folhas: " << nFolhas << ", altura: " << altura << ", largura: " << largura << endl;
}

int main(int argc, const char * argv[]) {
    Caderno c("Oxford", "Verde", 120, 80 ,40);
    
    c.mostraCaderno();
    c.setCor("Azul");
    c.getCor();
    
    return 0;
}
