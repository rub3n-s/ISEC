//
//  caderno.hpp
//  f2_04
//
//  Created by rsantos on 20/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef caderno_hpp
#define caderno_hpp

#include <stdio.h>
using namespace std;

class Caderno {
    string marca;
    string cor;
    double altura;
    double largura;
    int nPag;
    string local;
    string conteudo;
    bool aberto = false;
    
public:
    //construtor
    Caderno(string marca, string cor, int nPag,double altura, double largura);
    
    //destrutor
    //~Caderno();
    
    //acessores
    string getMarca() const;
    string getCor() const;
    double getAltura() const;
    double getLargura() const;
    int getNumeroPag() const;
    string getLocal() const;
    string getConteudo() const;
    int pagAtual;
    
    //modificadores
    void abrir();
    void fechar();
    bool setLocal(string loc);
    bool escreve(string texto);
    bool viraPagina();
};

#endif /* caderno_hpp */
