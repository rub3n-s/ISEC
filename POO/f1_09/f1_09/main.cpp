//
//  main.cpp
//  f1_09
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;

string intToString(int num) {
    string numExt[10] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
    
    /*if (num >= 0 && num < 10) {
        for (int i = 0; i < 10; i++) {
            if (num == i)
                return numExt[num-1];
        }
     
        return "";
    }*/
    
    if (num >= 0 && num < 10)
        return numExt[num-1];
    else
        return "";
}

int stringToInt(string num) {
    string numExt[10] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
    
    for (int i = 1; i <= 10; i++)
        if (num == numExt[i])
            return i+1;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    cout << intToString(3) << endl;
    
    cout << stringToInt("tres") << endl;
    
    return 0;
}
