//
//  main.cpp
//  f3_01
//
//  Created by rsantos on 20/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Ponto.hpp"
#include "Retangulo.hpp"
#include "Desenho.hpp"

int main(int argc, const char * argv[]) {
    /*Ponto a(1,2);
    Ponto b(3,4);
    
    cout << "p1 -> " << a.getAsString() << endl;
    cout << "p2 -> " << b.getAsString() << endl;
    
    cout << "distancia entre p1 e p2: " << a.distanciaPontos(b) << endl;
    
    Ponto c(5,6);
    cout << "c(" << c.getX() << ",y)" << endl;
    cout << "c(x," << c.getY() << ")" << endl;
    
    Ponto arr[3] = {{1,3},{2,4},{5,7}};
    for(auto c : arr)
        cout << c.getAsString() << " ";
    cout << endl;
    
    Ponto d;
    cout << d.getAsString() << endl; */
    
    /*---------------------------------------------------*/
    
    /* vector<int> v = {1, 2, 3, 4, 5, 6};
    auto b = v.begin();
    
    while(b != v.end()) {
        cout << *b << " ";
        ++b;
    }
    cout << endl;
    
    for (auto c : v) {
        c = c * 2;
        cout << c << " ";
    }
    cout << endl;
    
    vector<int>::const_iterator it;
    
    for(it = v.cbegin(); it < v.cend() && *it != 5; ++it)
        cout << *it << " ";
    cout << endl;
    
    vector<string> e {"como vai?", "tudo bem?"};
    e.insert(e.cbegin(), "ola!");
    for (auto f : e)
        cout << f << "\n"; */
    
    
    /*
    Ponto p1(1,2);
    Retangulo r(p1, 2, 4);
    
    cout << r.getAsString() << endl; */
    
    Desenho d("segundo");
     
     Retangulo r1({1, 5}, 4, 4);
     d.addFigura(r1);
     
     Retangulo r2({7, 2}, 3, 8);
     d.addFigura(r2);
     
     cout << "----------" << d.getAsString() << endl;
     cout << "\n\nSoma Áreas: "<<d.somaAreas() << endl;
     
     d.removeAreaMaior(15);
     cout << "----------" << d.getAsString() << endl;
    
    
    return 0;
}
