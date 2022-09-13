//
//  ex5_6.hpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ex5_6_hpp
#define ex5_6_hpp

#include <string>

using namespace std;

class Automovel {
    string matricula;
    int combustivel;
    string marca;
    string modelo;
    
public:
    Automovel(string mat, int comb, string ma, string mo);
    
    string getAsString() const;
    
    string getMatricula() const { return matricula; }
    int getCombustivel() const { return combustivel; }
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    
    void setMatricula(string mat) { matricula = mat; }
    void setCombustivel(int c) { combustivel = c; }
    void setMarca(string ma) { marca = ma; }
    void setModelo(string mo) { modelo = mo; }
};

#endif /* ex5_6_hpp */
