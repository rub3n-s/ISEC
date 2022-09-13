//
//  main.cpp
//  ex7
//
//  Created by rsantos on 29/10/2021.
//

#include "MSG.hpp"

using namespace std;

void teste(MSG &m) {
    MSG aux('y');
    cout << aux.getAsString();
}

int main(int argc, const char * argv[]) {
    MSG a('a');
    MSG b;
    MSG &c = b;
    MSG d = b;
    MSG e[2];
    
    cout << a.getAsString();
    cout << b.getAsString();
    cout << c.getAsString(); // mesma referencia que 'b', apenas é destruido uma vez
    cout << d.getAsString(); // igual a b, porem espaço de memoria diferente
    
    a = b;
    cout << a.getAsString();
    
    cout << "\nmatriz: \n";
    cout << e[0].getAsString();
    cout << e[1].getAsString() << endl;
    
    teste(b);  //letra existe apenas dentro da função
    
    MSG &f(a);
    cout << f.getAsString();
    
    return 0;
}
