//
//  main.cpp
//  f5_02
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "ABC.hpp"

void gastaMem() {
    ABC temp("Texto temporário que ocupa espaço"); // Etc. Tanto faz.
}

void func(ABC x) {
    // tanto faz
}
void func() {
    ABC a("aaa");
    ABC b("bbb");
    a = b;
}

int main(int argc, const char * argv[]) {
    
    /*for (unsigned int i=0; i<100000000; i++)
        gastaMem();
    cout << "o programa ja deve terminado por falta de memória "; */
    
    ABC y("ola");
    func(y);
    cout << y.getConteudo(); // se não rebentar experimentar outra func(y) cout << "o programa já deve ter rebentado";
    func();
    cout << "o programa já deve ter rebentado novamente";
    
    return 0;
}
