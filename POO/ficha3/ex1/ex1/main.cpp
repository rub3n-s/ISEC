//
//  main.cpp
//  ex1
//
//  Created by rsantos on 03/11/2021.
//

#include <iostream>
#include "Ponto.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Ponto a(1,2);
    Ponto b(3,4);
    const Ponto c(5,6);
    Ponto d[3] = {{1,3}, {2,4}, {5,7}};
    Ponto f;
    
    cout << a.getY() << endl;
    cout << a.getAsString();
    cout << b.getAsString();
    
    cout << "distancia entre 'a' e 'b' = " << a.distancia(b) << endl;
    
    cout << c.getX() << endl;
    
    //c.setX(5); // não é possivel devido a ser constante o seu valor nao pode ser alterado
    
    for (auto c : d)
        cout << c.getAsString();
    
    cout << f.getAsString();
    
    return 0;
}
