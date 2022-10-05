//
//  main.cpp
//  f7_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Loja.hpp"
#include "Apartamento.hpp"
#include "Imobiliaria.hpp"

int main(int argc, const char * argv[]) {
    Imobiliaria a("ABC");
    Imovel *a1 = new Apartamento(100, 5, 2);
    Imovel *a2 = new Apartamento(200, 3, 4);
    Imovel *a3 = new Apartamento(50, 6, 2);
    
    Imovel *l1 = new Loja(100);
    Imovel *l2 = new Loja(50);
    Imovel *l3 = new Loja(200);
    
    a.addImovel(a1);
    a.addImovel(a2);
    a.addImovel(a3);
    a.addImovel(l1);
    a.addImovel(l2);
    a.addImovel(l3);
    
    cout << a;
    
    cout << "\nlistar andar 2: -------------------------\n";
    a.listarAndar(2);
    
    cout << "\napartamento 2: ---------------------------\n";
    a.getImovel("apartamento2");
    
    return 0;
}
