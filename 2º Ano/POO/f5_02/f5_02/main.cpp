//
//  main.cpp
//  f5_02
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "ABC.hpp"

void gastaMem() {
    ABC temp("Texto temporário que ocupa espaço");
}

void func(ABC x) {
   //tanto faz
}

void func() {
    ABC a("aaa");
    ABC b("bbb");
    
    a = b;
}

int main(int argc, const char * argv[]) {
    for (unsigned int i = 0; i < 100000000; i++)
        gastaMem();
    cout << "o programa já deve ter terminado por falta de memória\n";
    
    /*
    ABC y("ola");
    func(y);
    cout << y.getConteudo(); */
    
    func();
    cout << "o programa já deve ter rebentado novamente\n";
    
    return 0;
}
