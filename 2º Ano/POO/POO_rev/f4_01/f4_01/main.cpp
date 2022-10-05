//
//  main.cpp
//  f4_01
//
//  Created by rsantos on 26/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Fraccao.hpp"

int main(int argc, const char * argv[]) {
    Fraccao a(1,2);
    Fraccao b(3);
    Fraccao c(3,4);
    
    cout << "(" << a.getNumerador() << ", " << a.getDenominador()<< ")" << endl;
    cout << "(" << b.getNumerador() << ", " << b.getDenominador()<< ")" << endl;
    cout << "(" << c.getNumerador() << ", " << c.getDenominador()<< ")" << endl;
    
    a.setNumerador(2);
    
    cout << "\n'a' depois da alteração: numerador(2)" << endl;
    cout << "(" << a.getNumerador() << ", " << a.getDenominador()<< ")" << endl;
    
    a = b * c;
    cout << "a = b * c -> (" << a.getNumerador() << ", " << a.getDenominador()<< ")" << endl;
    
    cout << a;
    
    b = c;
    cout << "b = c "<<b;
    
    //b = ++a;
    b += a;
    cout << "b += a "<< b;
    return 0;
}
