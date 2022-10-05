//
//  main.cpp
//  complexos
//
//  Created by rsantos on 17/11/2021.
//

#include <iostream>

using namespace std;


// SEE: https://www.ibm.com/docs/en/zos/2.1.0?topic=only-overloading-operators

class Complexo {
private:
    int real, imag;
public:
    Complexo(int r = 0, int i = 0) { real = r;   imag = i; }

  
    Complexo operator + (Complexo const& obj) {
        Complexo res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + " << imag << "i" << endl; }
};

int main()
{
   
    Complexo c1(10, 5), c2(2, 4);
    Complexo c3 = c1 + c2;
    c3.print();
}
