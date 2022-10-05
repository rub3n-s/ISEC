//
//  main.cpp
//  f5_08
//
//  Created by rsantos on 26/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Agenda.hpp"

int main(int argc, const char * argv[]) {
    
    Agenda a;
    
    a.adicionaContacto("Pedro", 123);
    a.adicionaContacto("Maria", 456);
    a.adicionaContacto("Jose", 789);
    a.adicionaContacto("Filomena", 467);
    cout << "Agenda A:\n" << a << "\n";
    
    a.gravaAgenda("agenda.txt");
    
    Agenda d = Agenda::leAgenda("agenda.txt");
    
    Agenda c = a;
    cout << "Agenda C:\n" << c << "\n";
    
    Agenda b(a);
    cout << "Agenda B:\n" << b << "\n";
    
    return 0;
}
