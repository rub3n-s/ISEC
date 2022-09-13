//
//  main.cpp
//  ex1
//
//  Created by rsantos on 03/12/2021.
//

#include <iostream>

using namespace std;

class MSG {
    
public:
//MSG() { /*cout << "olaC\n";*/ }
MSG(const char * p) { cout << "ola" << p << "\n"; }
~MSG() { cout << "Adeus\n"; }
};

void func(MSG *a, MSG *b) {
    a = new MSG("A2");
    b = new MSG("B2");
}

int main(int argc, const char * argv[]) {
    /*MSG *a = new MSG("A");
    MSG *b = new MSG("B");
    
    delete a;
    delete b; */
    
    MSG *a = nullptr;
    MSG *b = nullptr;
    func(a,b);
    delete a;
    delete b;
    
    //MSG *c = new MSG[3];
    MSG *c = new MSG[3]{MSG("a"),MSG("b"),MSG("c")};
    delete [] c;
    
    return 0;
}
