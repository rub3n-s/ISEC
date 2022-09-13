//
//  caderno.cpp
//  f2_03 (1)
//
//  Created by rsantos on 11/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "caderno.hpp"

string Caderno::getAsString() const {
    ostringstream os;
    
    os << "Marca: " << marca << "\tCor: " << cor << "\tPaginas: " << nPag << "\tComprimento: " << comp << "\tLargura: " << larg;
    
    return os.str();
}

string Caderno::getMarca() const { return marca; }
string Caderno::getCor() const { return cor; }
int Caderno::getNPag() const { return nPag; }
double Caderno::getComp() const { return comp; }
double Caderno::getLarg() const { return larg; }

void Caderno::setMarca(string m) { marca = m; }
void Caderno::setCor(string c) { cor = c; }
void Caderno::setNPag(int pag) { nPag = pag; }
void Caderno::setComp(double com) { comp = com; }
void Caderno::setLarg(double lar) { larg = lar; }

string Caderno::getConteudo() const { return conteudo; }
bool Caderno::abrir() { return aberto = true; }
bool Caderno::fechar() { return aberto = false; }
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
