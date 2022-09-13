//
//  ex3_4.hpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ex3_4_hpp
#define ex3_4_hpp
#include <string>

using namespace std;

/*struct Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
};

Caderno preenche(string marca, string cor, int nFolhas, int altura, int largura);
void mostra(Caderno c);*/

class Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
    
public:
    Caderno(string m, string c, int nF, int alt, int larg);
    
    string getMarca() const { return marca; }
    string getCor() const { return cor; }
    int getNFolhas() const { return nFolhas; }
    int getAltura() const { return altura; }
    int getLargura() const { return largura; }
    
    void setMarca(string m) { marca = m; }
    void setCor(string c) { cor = c; }
    void setNFolhas(int nF) { nFolhas = nF; }
    void setAltura(int alt) { altura = alt; }
    void setLargura(int larg) { largura = larg; }
    
    string getAsString() const;
};


#endif /* ex3_4_hpp */
