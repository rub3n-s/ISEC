//
//  main.cpp
//  f1_07
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <sstream> //deve estar no inicio do ficheiro
#include <iostream>

using namespace std;

void verifica() {
    istringstream s2("Rúben Silva Santos");
    string palavra, aux;
    
    while(s2 >> palavra) {
        cout << palavra << endl;
        
        if(palavra == "Silva")
            aux = palavra;
    }
    
    if (aux == "Silva")
        cout << "Conheço este nome!" << endl;
    
    cout << "Guardado em s2: " << s2.str() << endl;
    
    s2.str("Novo texto!"); //outro valor guardo em s2
    cout << "Guardado em s2: " << s2.str() << endl;
    
}

void verifica_v2() {
    string nome;
    
    cout << "Nome: ";
    getline(cin,nome);
    
    istringstream s2(nome);
    string palavra;
    bool silva = false;
    
    while(s2 >> palavra) {
        cout << palavra << endl;
        
        if (palavra == "Silva") {
            silva = true;
        }
    }
    
    if (silva)
        cout << "Conheço este nome!" << endl;
}

int main(int argc, const char * argv[]) {
    
    verifica();
    cout << endl;
    verifica_v2();
    
    return 0;
}
