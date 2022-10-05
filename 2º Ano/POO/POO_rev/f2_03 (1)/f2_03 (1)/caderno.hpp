//
//  caderno.hpp
//  f2_03 (1)
//
//  Created by rsantos on 11/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef caderno_hpp
#define caderno_hpp

#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Caderno {
    string marca;
    string cor;
    int nPag;
    double comp;
    double larg;
    string conteudo;
    string local;
    bool aberto = false;
    int pagAtual;
    
public:
    Caderno(string m, string c, int nP, double co, double la) :
        marca(m), cor(c), nPag(nP), comp(co), larg(la) {
            if (nP >= 1)
                nPag = nP;
            else
                nPag = 1;
            conteudo = "Pag. 1: ";
        }
    
    //~Caderno();
    
    string getAsString() const;    
    
    //obter cada dado
    string getMarca() const;
    string getCor() const;
    int getNPag() const;
    double getComp() const;
    double getLarg() const;
    
    
    //modificar cada dado
    void setMarca(string m);
    void setCor(string c);
    void setNPag(int pag);
    void setComp(double com);
    void setLarg(double lar);
    
    bool abrir();
    bool fechar();
    bool setLocal(string loc);
    bool escreve(string texto);
    bool viraPagina();
    string getConteudo() const;
};

#endif /* caderno_hpp */
