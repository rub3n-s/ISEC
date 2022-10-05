//
//  caderno.hpp
//  f2_03 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef caderno_hpp
#define caderno_hpp

#include <string>

using namespace std;

class Caderno {
    string marca;
    string cor;
    int nFolhas;
    int altura;
    int largura;
    
public:
    Caderno(string m, string c, int nF, int alt, int larg);
    
    string getAsString() const;
    
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
};

#endif /* caderno_hpp */
