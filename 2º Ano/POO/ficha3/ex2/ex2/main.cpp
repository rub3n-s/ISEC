//
//  main.cpp
//  ex2
//
//  Created by rsantos on 03/11/2021.
//

#include <iostream>
#include "Triangulo.hpp"

int main(int argc, const char * argv[]) {
    Ponto a(1,2);
    Ponto b(3,4);
    Ponto c(5,6);
    Triangulo q(a,b,c);
    
    cout << q.getAsString();
    
    cout << "retornar ponto a (triangulo q): " << q.getPonto(a) << endl;
    
    return 0;
}
