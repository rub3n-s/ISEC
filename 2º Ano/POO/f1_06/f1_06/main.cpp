//
//  main.cpp
//  f1_06
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

/*void troca(int *a, int *b) { // versão 1
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
} */

void troca(int &a, int &b) { // versão 2
    int aux;
    
    aux = a;
    a = b;
    b = aux;
}

int main(int argc, const char * argv[]) {
    int a = 5, b  = 10;
    
    //troca(&a,&b); // versão 1
    
    troca(a,b); // versão 2
    
    cout << "a: " << a << "\nb: " << b << endl;
    
    return 0;
}
