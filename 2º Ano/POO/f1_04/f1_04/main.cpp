//
//  main.cpp
//  f1_04
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

void imprime(string a) {
    cout << a << endl;
}

void imprime(string a, int b) {
    cout << a << b << endl;
}

void imprime(int a, string b) {
    cout << a << b << endl;
}

int main(int argc, const char * argv[]) {
    imprime("ola");
    imprime("a idade é: ", 25);
    imprime(100, "Euros");
    
    return 0;
}
