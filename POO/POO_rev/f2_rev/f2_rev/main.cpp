//
//  main.cpp
//  f2_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include "ex1.hpp"
#include "ex3_4.hpp"
#include "ex5_6.hpp"
#include "ex7.hpp"
#include "ex9.hpp"

void teste() {
    MSG aux('y');
    cout << aux.getAsString();
}

int main(int argc, const char * argv[]) {
    /*Tabela t(5);
    //t.preenche(5);
    t.mostra();
    
    t.alteraElemento(2, 3);
    t.mostra();
    
    t.elementoEm_v2(2) = 15;
    t.mostra();
    
    Tabela t2;
    t2.mostra(); */
    
    //Caderno c;
    //c = preenche("Oxford", "Verde", 100, 50, 20);
    //mostra(c);
    
    /* Caderno c("Oxford", "Verde", 100, 50, 20);
    cout << c.getAsString();
    
    cout << c.getMarca() << endl;
    c.setMarca("ABC");
    cout << c.getMarca() << endl;
    */
    
    /*Automovel a("12-AB-01", 60, "Mercedes", "C270");
    cout << a.getAsString();
    
    Automovel b("", 50, "BMW", "M3");
    cout << b.getAsString();*/
    
    /* MSG a('a');
    MSG b;
    
    cout << a.getAsString();
    cout << b.getAsString();
    
    MSG c(b);
    cout << c.getAsString();
    
    MSG d = b;
    cout << d.getAsString();
    
    a = b;
    cout << a.getAsString();
    
    teste();
    */
    
    vector<string> canais = {"rtp1", "rtp2", "sic", "tvi"};
    Televisao t1(canais);
    
    cout << t1.getAsString();
    
    t1.aumentaSom();
    t1.ligaCanal(1);
    
    t1.ligaTV();
    cout << t1.getAsString();
    
    t1.ligaCanal(1);
    t1.aumentaSom();
    cout << t1.getAsString();
    
    t1.ligaCanal(2);
    cout << t1.getAsString();
    
    return 0;
}
