//
//  Retangulo.hpp
//  ex3
//
//  Created by rsantos on 03/11/2021.
//

#ifndef Retangulo_hpp
#define Retangulo_hpp

#include "Ponto.hpp"
#include <vector>

class Retangulo {
    Ponto cantoSE;
    
    int comprimento;
    int altura;
    
public:
    Retangulo(Ponto cse, int comp, int alt);
    
    string getAsString() const;
};
#endif /* Retangulo_hpp */
