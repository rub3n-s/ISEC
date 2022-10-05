//
//  peixe.h
//  f6_01
//
//  Created by rsantos on 10/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef peixe_h
#define peixe_h

#include <string>
#include <iostream>
#include <sstream>
class Aquario;

using namespace std;

class Peixe {
    string especie;
    string cor;
    int peso;
    unsigned int numSerie;
    static unsigned int conta;
    Aquario *aquario = nullptr;
    bool indigestao = false;
    unsigned int resta = 4; // eventos de alimentação até morrer
    
protected:
    bool setPeso(int g);
    int getPeso() const { return peso; }
    
public:
    Peixe(string es, string co = "cinzento");
    Peixe(const Peixe &p);
    
    bool desligaAquario(Aquario *a);
    unsigned int getNserie() const { return numSerie; }
    bool isVivo() const { return (resta > 0); }
    virtual void come(unsigned int c);
    bool ligaAaquario(Aquario*);
    virtual string getAsString() const;
    
    virtual ~Peixe() { cout << "A destruir peixe\n"; }
};

ostream &operator<<(ostream &, const Peixe &);

#endif /* peixe_h */
