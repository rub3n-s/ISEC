//
//  main.cpp
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "apartamento.hpp"
#include "loja.hpp"
#include "imobiliaria.hpp"

int main(int argc, const char * argv[]) {
    Apartamento apartB(120, 2, 3);
    cout << "Apartamento B: " << apartB << endl;
    
    Loja lojaA(100);
    cout << "loja A: " << lojaA << endl;
    
    Imobiliaria x("ERA");
    
    x.addImovel(&lojaA);
    x.addImovel(&apartB);
    cout << x << endl;
    
    return 0;
}
