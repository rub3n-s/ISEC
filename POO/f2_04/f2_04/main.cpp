//
//  main.cpp
//  f2_04
//
//  Created by rsantos on 20/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "caderno.hpp"

string Caderno::getMarca() const { return marca; }
string Caderno::getCor() const { return cor; }
string Caderno::getLocal() const { return local; }
string Caderno::getConteudo() const { return conteudo; }
double Caderno::getAltura() const { return altura; }
double Caderno::getLargura() const { return largura; }
int Caderno::getNumeroPag() const { return nPag; }

Caderno::Caderno(string m, string c, int nP,double alt, double larg):
marca(m), cor(c), nPag(nP),altura(alt), largura(larg) {
    if (nP >= 1)
        nPag = nP;
    else
        nPag = 1;
    conteudo = "Pag 1:";
}

void Caderno::abrir() { aberto = true; }
void Caderno::fechar() { aberto = false; }
bool Caderno::setLocal(string loc) {
    if (!aberto) {
        local = loc;
        return true;
    }
    else
        return false;
}

/*Caderno::~Caderno() {
    cout << "tenho conteúdo: " << conteudo << " e vou desaparecer!\n" << endl;
} */

bool Caderno::escreve(string texto) {
    if (aberto && local != "") {
        conteudo += texto;
        return true;
    }
    
    return false;
}

bool Caderno::viraPagina() {
    if (aberto && pagAtual < nPag) {
        ++pagAtual;
        conteudo += "\nPag. " + to_string(pagAtual) + ": ";
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    Caderno c("Oxford", "Verde", 80, 50, 30);
    
    /*
    cout << "Marca do caderno: " << c.getMarca() << "\n";
    cout << "Número de páginas: " << c.getNumeroPag() << "\n";
    
    
    c.abrir(); //quando está aberto não dá para mudar o local
    
    if (c.setLocal("prateleira 2A"))
        cout << "Arrumei o caderno.\n";
    else
        cout << "Não consegui mudar.\n";
    */
    
    c.abrir();
    c.escreve("Estava um dia escuro de tempestade\n");
    c.viraPagina();
    c.escreve("E no outro dia choveu outra vez\n");
    cout << c.getConteudo() << endl;
    
    return 0;
}
