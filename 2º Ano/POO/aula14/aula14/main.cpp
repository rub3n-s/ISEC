//
//  main.cpp
//  aula14
//
//  Created by rsantos on 19/11/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    
    //delete i; //erro porque i não é um ponteiro
    //delete pi1; // o objeto para onde pi1 aponta não foi alocado dinamicamento, erro!!
    if (pi2 != nullptr)
        delete pi2;
    delete pd;
    
    /* int *pi = new int(1024);
    string *ps = new string(5, '9');
    vector<int> *pv = new vector<int> { 1, 2, 3, 4, 5, 6, 7 };
    //vector<int> *pv = new vector<int> { 1, 2, 3, 4, 5, 6, 7 };
    int *qi = new int();
    
    cout << *pi << " " << *ps << " " << *qi << endl;

    delete pi; */
    
    return 0;
}
