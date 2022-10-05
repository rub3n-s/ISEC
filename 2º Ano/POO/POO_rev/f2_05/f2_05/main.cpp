//
//  main.cpp
//  f2_05
//
//  Created by rsantos on 01/12/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "automovel.hpp"

int main(int argc, const char * argv[]) {
    
    Automovel a("Mercedes-Benz", "C200", "12-AA-21", 60, 2003);
    
    cout << a.getAsString() << "\n";
    
    cout << "\n";
    
    cout << a.getAno() << "\n";
    
    a.setAno(2020);
    
    cout << a.getAno() << "\n";
    
    return 0;
}
