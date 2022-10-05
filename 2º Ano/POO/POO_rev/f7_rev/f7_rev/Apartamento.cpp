//
//  Apartamento.cpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "Apartamento.hpp"
#include <sstream>

Apartamento::Apartamento(int ar, int nA, int an) : Imovel(10 * ar, ar, an, "apartamento"), assoalhadas(nA) {}
