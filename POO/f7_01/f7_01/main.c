//
//  main.c
//  f7_01
//
//  Created by rsantos on 17/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream.h>
#include "apartamento.hpp"
#include "loja.hpp"

int main(int argc, const char * argv[]) {
    Apartamento apartB(120, 2, 3);
    cout << "Apartamento B: " << apartB << endl;
    
    Loja lojaA(100);
    cout << "loja A: " << lojaA << endl;
    return 0;
}
