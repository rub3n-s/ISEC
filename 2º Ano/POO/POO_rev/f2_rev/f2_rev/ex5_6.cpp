//
//  ex5_6.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex5_6.hpp"
#include <sstream>

Automovel::Automovel(string mat, int comb, string ma, string mo) :
    matricula(mat), combustivel(comb), marca(ma), modelo(mo) {
        if (combustivel < 0)
            combustivel = 0;
        if (matricula == "")
            matricula = "00-AA-00";
    }

string Automovel::getAsString() const {
    ostringstream os;
    os << "Matricula: " << matricula << ", Combustivel: " << combustivel << ", Marca: " << marca << ", Modelo: " << modelo << endl;
    return os.str();
}
