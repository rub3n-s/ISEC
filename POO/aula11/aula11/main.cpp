//
//  main.cpp
//  aula11
//
//  Created by rsantos on 10/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "conta.hpp"
#include "banco.hpp"

int main(int argc, const char * argv[]) {
    Banco b("Banco XPTO");
    std::cout << "Banco b: " << b.getAsString() << "\n";
    
    
    return 0;
}
