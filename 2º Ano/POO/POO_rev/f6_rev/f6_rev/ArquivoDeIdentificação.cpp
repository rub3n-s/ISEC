//
//  ArquivoDeIdentificação.cpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ArquivoDeIdentificação.hpp"
#include <iostream>

ArquivoDeIdentificação::ArquivoDeIdentificação(string n, int b) : Cidadao(n,b){
    cidadaos.push_back(this);
}

ArquivoDeIdentificação::~ArquivoDeIdentificação() {
    cout << "a destruir...";
}
