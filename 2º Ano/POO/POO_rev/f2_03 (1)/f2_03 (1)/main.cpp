//
//  main.cpp
//  f2_03 (1)
//
//  Created by rsantos on 11/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "caderno.hpp"

int main(int argc, const char * argv[]) {
    
    Caderno a("Oxford", "Verde", 120, 80, 50);
    
    cout << a.getAsString() << endl;
    
    a.setCor("Vermelho");
    cout << a.getCor() << endl;
    
    
    
    Caderno c("ABC", "Amarelo", 120, 80, 50);
    
    c.setLocal("local: ");
    c.abrir();
    c.escreve("Estava um dia escuro de tempestade\n");
    c.viraPagina();
    c.escreve("E no outro dia choveu outra vez\n");
    cout << c.getConteudo() << endl;
    
    return 0;
}
