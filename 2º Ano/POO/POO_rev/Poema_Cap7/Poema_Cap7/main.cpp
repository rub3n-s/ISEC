//
//  main.cpp
//  Poema_Cap7
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Poema.hpp"

int main(int argc, const char * argv[]) {
    Poema a("Os Lusiadas");
    string frase = "abcsaodkas aosdkasfd";
    a.acrescentaVerso(frase);
    cout << a;
    
    a.eliminaVerso(1);
    cout << a;
    return 0;
}
