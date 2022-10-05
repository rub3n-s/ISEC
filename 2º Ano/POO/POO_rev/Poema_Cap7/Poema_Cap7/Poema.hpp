//
//  Poema.hpp
//  Poema_Cap7
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Poema_hpp
#define Poema_hpp

#include <string>
#include <iostream>

using namespace std;

class Poema {
    string titulo; //titulo do poema
    string * pVersos; //array dinamico de strings
    int nVersos; //numero de versos
    
public:
    Poema(const string & t); //construtor
    Poema(const Poema &p); //construtor por cópia
    ~Poema(); //destrutor
    
    Poema &operator=(const Poema &p);
    
    void acrescentaVerso(string & verso);
    void eliminaVerso(int ordem);
    string getAsString() const;
};

ostream &operator<<(ostream &os, const Poema &p);
#endif /* Poema_hpp */

