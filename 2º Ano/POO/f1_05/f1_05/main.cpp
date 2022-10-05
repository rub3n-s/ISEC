//
//  main.cpp
//  f1_05
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>

using namespace std;


int soma() {
    int s = 0;
    return s;
}

int soma(int a = 1) {
    int s = 0;
    s+=a;
    return s;
}

int soma(int a, int b = 2) {
    int s = 0;
    s = a+b;
    return s;
}

int soma(int a, int b, int c = 3) {
    int s = 0;
    s = a+b+c;
    return s;
}
int main(int argc, const char * argv[]) {
    cout << "\n" << soma() << soma(1);
    cout << soma(1,2) << soma(1,2,3) << endl;
    return 0;
}
