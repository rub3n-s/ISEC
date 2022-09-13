//
//  main.cpp
//  ex1
//
//  Created by rsantos on 17/11/2021.
//

#include <iostream>
#include "Fraccao.hpp"

int main(int argc, const char * argv[]) {
    int numerador = 0, denominador = 0;
    Fraccao f1(1,2), f2(1,3);
    Fraccao f3 = f1 + f2;
    cout << "f3: " << f3.getAsString();
    
    cout << "numerador: "; cin >> numerador;
    cout << "denominador: "; cin >> denominador;
    Fraccao f4(numerador, denominador);
    cout << "f4: " << f4.getAsString();
    
    Fraccao f5 = f1 * f2;
    cout << "f5: "<< f5.getAsString();
    return 0;
}
