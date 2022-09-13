//
//  main.cpp
//  f2_07
//
//  Created by rsantos on 22/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "MSG.h"
#include <string> //necessário para usar o getline()

using std::cout;
using std::endl;

MSG teste() {
    MSG aux('y');
    
    string s;
    getline(cin,s);
    
    return aux;
}

int main(int argc, const char * argv[]) {
    MSG a('a');
    MSG b;
    MSG &c = b; // não é nenhum objeto novo, porque nao foi criado nem destruido
    
    MSG d = b; // criado por copia
    //a = b; // não cria nenhum objeto
    //MSG m[2] = {'c', 'd'};
    
    teste();
    
    string s;
    getline(cin, s);
    
    //cout << b.getAsString() << endl;
    
    return 0;
}
