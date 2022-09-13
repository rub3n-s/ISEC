//
//  main.cpp
//  11
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "ponto.hpp"

int main(int argc, const char * argv[]) {
    //dado1 + dado2       dado1.operator+(dado2);     operator+(dado1,dado2);
    /*
    Ponto a(10,20);
    cout << "a: " << a << "\n";
    Ponto b = ++a;
    cout << "b(=++a): " << b << "\n";
    cout << "a depois de incrementado: " << a << "\n";
    
    Ponto b(1,2);
    Ponto c(10,20);
     
    if (a == b)
        cout << "a e b são iguais!" << " " << a << " " << b << "\n";
    else
        cout << "a e b são diferentes!" << " " << a << " " << b << "\n";
    
    if (a == c)
        cout << "a e c são iguais!" << " " << a << " " << c << "\n";
    else
        cout << "a e c são diferentes!" << " " << a << " " << c << "\n";
    
    ------------------------------------------------------
    if (a == b)
        cout << "a e b são iguais!" << " " << a.getAsString() << " " << b.getAsString() << "\n";
    else
        cout << "a e b são diferentes!" << " " << a.getAsString() << " " << b.getAsString() << "\n";
    
    if (a == c)
        cout << "a e c são iguais!" << " " << a.getAsString() << " " << c.getAsString() << "\n";
    else
        cout << "a e c são diferentes!" << " " << a.getAsString() << " " << c.getAsString() << "\n";
    
    
    Ponto c = a + b;
    cout << "ponto a: " << a.getAsString() << "\nponto b: " << b.getAsString() << "\nponto c = a+b: " << c.getAsString() << endl;
    */
    
    
    Ponto b(1, 2);
    Ponto e = b + 2;
    Ponto f = 4 + b;
    cout << "ponto e = b+2: " << e.getAsString() << "\nponto f = 4+b: " << f.getAsString() << endl;
    
    
    return 0;
}
