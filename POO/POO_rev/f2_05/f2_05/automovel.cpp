//
//  automovel.cpp
//  f2_05
//
//  Created by rsantos on 01/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include "automovel.hpp"
#include <sstream>

string Automovel::getAsString() const {
    ostringstream os;
    os << "Marca: " << marca << "\nModelo: " << modelo << "\nMatricula: " << matricula << "\nCombustivel: " << combustivel << "\nAno: " << ano;
    return os.str();
}
