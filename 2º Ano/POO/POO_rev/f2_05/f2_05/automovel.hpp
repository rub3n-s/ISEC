//
//  automovel.hpp
//  f2_05
//
//  Created by rsantos on 01/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#ifndef automovel_hpp
#define automovel_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Automovel {
    string matricula;
    string marca;
    string modelo;
    int combustivel;
    int ano;

public:
    Automovel(string mar, string mod, string mat, int com, int a) : marca(mar), modelo(mod), matricula(mat), combustivel(com), ano(a) {
        if (matricula == "")
            matricula = "00-AA-00";
        
        if(ano < 1980 || ano > 2020)
            ano = 2020;
    }
    
    string getAsString() const;
    
    string getMatricula() { return matricula; }
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    int getCombustivel() { return combustivel; }
    int getAno() { return ano; }
    
    void setMatricula(string mat) { matricula = mat; }
    void setMarca(string mar) { marca = mar; }
    void setModelo(string mod) { matricula = mod; }
    void setCombustivel(int c) { combustivel = c; }
    void setAno(int a) { ano = a; }
};

#endif /* automovel_hpp */
