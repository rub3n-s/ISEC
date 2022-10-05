//
//  Peixe.hpp
//  f6_01
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Peixe_hpp
#define Peixe_hpp
#include <string>
#include <iostream>

class Aquario;

using namespace std;

class Peixe {
    string especie;
    string cor;
    int peso;
    int numSerie;
    bool indigestao = false;
    unsigned int resta = 4; // eventos de alimentação até morrer
    static unsigned int conta;
    Aquario *aquario = nullptr;
    
protected:
    bool setPeso(int g);
    int getPeso() const { return peso; }
    
public:
    Peixe(string es, string c = "cinzento");
    Peixe(Peixe &p);
    
    string getAsString() const;
    int getNSerie() const { return numSerie; }
    bool isVivo() const { return (resta > 0); }
    bool desligaAquario(Aquario *a);
    bool ligaAaquario(Aquario *a);
    
    virtual ~Peixe() { cout << "a destruir peixe\n"; }
};

ostream &operator<<(ostream &os, const Peixe &p);

#endif /* Peixe_hpp */
