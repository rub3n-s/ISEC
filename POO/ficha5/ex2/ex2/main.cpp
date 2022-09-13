//
//  main.cpp
//  ex2
//
//  Created by rsantos on 03/12/2021.
//

#include <iostream>
#include <string>

using namespace std;

class ABC {
   char * p;
public:
    ABC(char * s) {
      p = new char[strlen(s)+1];
      strcpy(p,s);
      cout << "a construir..." << p << endl;
    }
    ~ABC() {
        cout << "a destruir..." << endl;
        //delete [] p;
    }
    const char * getConteudo() const { return p; }
};

void gastaMem() {
      ABC temp("Texto temporário que ocupa espaço");
      // Etc. Tanto faz.
}

void func(ABC x) {
  // tanto faz
}

void func() {
   ABC a("aaa");
   ABC b("bbb");
   a = b;
}


int main(int argc, const char * argv[]) {
    /*ABC *str = new ABC("ola mundo");
    delete str;
    
    for (unsigned int i=0; i<100000000; i++)
        gastaMem();
        cout << "o programa ja deve terminado por falta de memória ";
    
    cout << str->getConteudo(); */
    
    ABC y("ola");
    func(y);
    cout << y.getConteudo(); // se não rebentar experimentar outra func(y) cout << "o programa já deve ter rebentado";
    func();
    cout << "o programa já deve ter rebentado novamente";
    
    return 0;
}
