//
//  main.cpp
//  ex1
//
//  Created by rsantos on 03/11/2021.
//

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    string file = "/Users/rubensantos/Desktop/POO/ficha3/teste2.txt";
    ifstream fin(file.c_str());
    
    string i;
    int j, k;
    string line;
    istringstream iss;
    while(getline(fin, line)) {
        iss.clear();
        iss.str(line);
        iss >> i >> j >> k;
        cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
    }
    return 0;
}
