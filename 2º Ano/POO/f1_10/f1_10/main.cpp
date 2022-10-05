//
//  main.cpp
//  f1_10
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

string verifica() {
    string arrayNum[10] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
    string numExt;
    int num;
    
    cout << "Numero p/ Extenso: ";
    cin >> numExt;
    
    cout << "Numero Decimal: ";
    cin >> num;
    
    if (num > 0 && num <= 10) {
        for (int i = 0; i < 10; i++) {
            if (i == num-1 && arrayNum[i] == numExt) {
                return "Certo!";
            }
        }
    }
    
    return "Errado!";
}
int main(int argc, const char * argv[]) {
    
    cout << verifica() << endl;
    
    return 0;
}
