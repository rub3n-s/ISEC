//
//  main.cpp
//  05 (2)
//
//  Created by rsantos on 19/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "automovel.hpp"

int main(int argc, const char * argv[]) {
    /*Automovel a;
    a = preenche("00-AA-00", "Mercedes-Benz", "C200", 60);
    mostra(a); */
    
    Automovel a("CI-12-54", "Mercedes-Benz", "C200", 60);
    cout << a.getAsString();
    
    Automovel b("", "Opel", "Corsa", 25);
    cout << b.getAsString();
    return 0;
}
