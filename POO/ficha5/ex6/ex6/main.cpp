//
//  main.cpp
//  ex6
//
//  Created by rsantos on 10/12/2021.
//

#include <iostream>
#include "Agenda.hpp"

int main(int argc, const char * argv[]) {
    Agenda a;
    a.adicionaContacto("A",123456789,0);
    a.adicionaContacto("B",542131789,1);
    a.adicionaContacto("C",65432423,2);
    
    cout << a.getAsString() << endl;
    
    return 0;
}
