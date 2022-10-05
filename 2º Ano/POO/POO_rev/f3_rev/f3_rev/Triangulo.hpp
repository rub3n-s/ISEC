//
//  Triangulo.hpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef Triangulo_hpp
#define Triangulo_hpp
#include <string>
#include "Ponto.hpp"

class Triangulo {
    string nome;
    Ponto verticeIE;
    Ponto verticeID;
    Ponto verticeSUP;
    
public:
    Triangulo(string n, Ponto vID, Ponto vIE, Ponto vSUP);
    
    void setVID(Ponto vID) { verticeID = vID; }
    void setVIE(Ponto vIE) { verticeIE = vIE; }
    void setVSUP(Ponto vSUP) { verticeID = vSUP; }
    
    string getAsString() const;
};

#endif /* Triangulo_hpp */
