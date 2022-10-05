//
//  Peixe.hpp
//  f6_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Peixe_hpp
#define Peixe_hpp
#include <string>

using namespace std;

class Aquario;

class Peixe {
    string especie;
    string cor;
    int peso;
    int nSerie;
    static unsigned int conta;
    unsigned int resta = 4;
    bool indigestao = false;
    Aquario *aquario = nullptr;
    
public:
    Peixe(string e, string c = "cinzento");
    Peixe(const Peixe &p);
    //~Peixe();
    
    virtual void come(int g);
    bool isVivo();
    int getNSerie() const { return nSerie; }
    bool ligaAaquario(Aquario *a);
    bool desligaAquario(Aquario *a);
    
    virtual string getAsString() const;
};

ostream &operator<<(ostream &os, const Peixe &p);

#endif /* Peixe_hpp */
