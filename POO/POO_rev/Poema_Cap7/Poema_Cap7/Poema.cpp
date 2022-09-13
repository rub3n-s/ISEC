//
//  Poema.cpp
//  Poema_Cap7
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Poema.hpp"
#include <sstream>

Poema::Poema(const string & t) : titulo(t), pVersos(nullptr), nVersos(0) { }

Poema::Poema(const Poema &p) : titulo(p.titulo), nVersos(p.nVersos) {
    //se a origem da copia for um poema sem versos
    if (p.pVersos == nullptr || p.nVersos == 0) {
        pVersos = nullptr;
        return;
    }
    
    //Reserva memoria para o nome array de strings
    pVersos = new string[p.nVersos];
    
    //Atribuir ao ponteiro auxiliar os valores que vão ser copiados
    //para o novo ponteiro
    for (int i = 0; i < nVersos; ++i)
        pVersos[i] = p.pVersos[i];
}

Poema::~Poema() {
    delete [] pVersos;
}

Poema &Poema::operator=(const Poema &p) {
    //prevenção da auto-atribuição
    if (this == &p)
        return *this;
    
    //se os dois membros da atribuição forem objetos diferentes
    titulo = p.titulo;
    nVersos = p.nVersos;
    
    //liberta a memória dinâmica usada pelo primeiro membro
    delete[] pVersos;
    pVersos = nullptr;
    
    //se a origem da copia for um poema sem versos
    if (p.pVersos == nullptr || p.nVersos == 0)
       return *this;
    
    //reserva memoria dinamica para conter uma copia exclusiva dos versos do segundo membro
    pVersos = new string[nVersos];
    
    //fazer a copia
    for (int i = 0; i < nVersos; ++i)
        pVersos[i] = p.pVersos[i];
    
    return *this;
}
void Poema::acrescentaVerso(string & verso) {
    string * aux = new string[nVersos + 1];
    
    for (int i = 0; i < nVersos; ++i)
        aux[i] = pVersos[i];
    
    aux[nVersos] = verso;
    ++nVersos;
    delete [] pVersos;
    
    pVersos = aux;
}

void Poema::eliminaVerso(int pos) {
    string * aux = new string[nVersos - 1];
    
    if (pos < 0 || pos > nVersos)
        return;
    if (nVersos == 1) {
        delete[] pVersos;
        pVersos = nullptr;
        nVersos = 0;
        return;
    }
    
    for (int i = 0; i < pos; ++i)
        aux[i] = pVersos[i];
    
    for (int i = pos; i < nVersos - 1; ++i)
        aux[i] = pVersos[i + 1];
    
    delete [] pVersos;
    --nVersos;
    pVersos = aux;
}

string Poema::getAsString() const {
    ostringstream os;
    os << "Titulo: " << titulo << "\n";
    for (int i = 0; i < nVersos; ++i)
        os << pVersos[i] << endl;
    return os.str();
}

ostream &operator<<(ostream &os, const Poema &p) {
    os << p.getAsString();
    return os;
}
