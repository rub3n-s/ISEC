//
//  main.cpp
//  f4_01
//
//  Created by rsantos on 12/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "fraccao.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    /*Fraccao a(1, 2);
    Fraccao b(3);
    const Fraccao c(3, 4);
    
    cout << "a: " << "(" << a.getNumerador() << ", " << a.getDenominador() << ")" << "\n";
    cout << "b: " << "(" << b.getNumerador() << ", " << b.getDenominador() << ")" << "\n";
    cout << "c: " << "(" << c.getNumerador() << ", " << c.getDenominador() << ")" << "\n";
    //a.setNumerador(5);
    cout << "a depois de alterado: " << " (" << a.getNumerador() << ", " << a.getDenominador() << ")\n";
    
    //a = b * c;
    //cout << "a(=b*c) " << "(" << a.getNumerador() << ", " << a.getDenominador() << ")" << "\n";
    
    Fraccao d = a * b * c;
    cout << "d(=a*b*c) " << "(" << d.getNumerador() << ", " << d.getDenominador() << ")" << "\n";*/
    
    Fraccao a(1, 2);
    cout << "a: " << a << "\n";
    
    Fraccao b = ++a;
    const Fraccao c(3, 4);    
    
    cout << "b (=++a): " << b << "\n";
    cout << "c: " << c << "\n";
    
    return 0;
}
