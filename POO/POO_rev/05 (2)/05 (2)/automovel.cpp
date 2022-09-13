//
//  automovel.cpp
//  05 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "automovel.hpp"
#include <iostream>
#include <sstream>

/*Automovel preenche(string mat, string m, string mo, int co) {
    Automovel a;
    
    a.matricula = mat;
    a.marca = m;
    a.modelo = mo;
    a.combustivel = co;
    
    return a;
}

void mostra(Automovel a) {
    cout << "matricula: " << a.matricula << ", marca: " << a.marca << ", modelo: " << a.modelo << ", combustivel: " << a.combustivel << endl;
} */

Automovel::Automovel(string mat, string m, string mo, int co) :
    matricula(mat), marca(m), modelo(mo), combustivel(co) {
        if (mat == "")
            matricula = "00-AA-00";
    }

string Automovel::getAsString() const {
    ostringstream os;
    os << "matricula: " << matricula << ", marca: " << marca << ", modelo: " << modelo << ", combustivel: " << combustivel << endl;
    
    return os.str();
}
