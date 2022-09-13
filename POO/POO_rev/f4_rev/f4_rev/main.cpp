//
//  main.cpp
//  f4_rev
//
//  Created by rsantos on 09/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Fraccao.hpp"

int main(int argc, const char * argv[]) {
    Fraccao a(1,2);
    Fraccao b(3);
    const Fraccao c(3,4);
    
    cout << a.getAsString();
    cout << b.getAsString();
    cout << c.getAsString();
    
    a.setDen(4);
    cout << a.getAsString();
    //c.setDen(5); é constante, não se pode alterar
    
    //a = b * c;
    //cout << a;
    
    a *= c;
    cout << a;
    
    return 0;
}
