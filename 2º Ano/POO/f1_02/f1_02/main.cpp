//
//  main.cpp
//  f1_02
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#define N 50

using namespace std;

int main(int argc, const char * argv[]) {
    char nome[N];
    int idade;
    
    cout << "Introduza o nome: ";
    cin >> nome;
    
    cout << "Introduza a idade: ";
    cin >> idade;
    
    cout << "\nNome: " << nome << "\nIdade: " << idade << endl;
    
    return 0;
}
