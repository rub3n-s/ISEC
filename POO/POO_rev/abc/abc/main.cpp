//
//  main.cpp
//  abc
//
//  Created by rsantos on 27/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

class Erro {
public:
    virtual string what() const {
        return "quartzo; ";
    }
};

class ErroDeriv: public Erro {
public:
    string what() const override {
        return "feldspato; ";
    }
};

void testar() {
    throw ErroDeriv();
    cout << "xisto; ";
}

/*-------------------------------------*/

class Item {
    string msg;
    
public:
    Item(const string & s) : msg(s) {
        cout <<  "Constr " << msg << "; " << endl;
    }
    
    ~Item() {
        cout << "Destr " << msg << "; " << endl;
    }
};

void f() {
    Item *p1 = new Item("Girassol");
    unique_ptr<Item> a = make_unique<Item>("Magnolia");
    Item *p2 = new Item("Girassol");
}

int main(int argc, const char * argv[]) {
    /*try {
        testar();
    }
    catch (Erro &e) {
        cout << e.what();
    }
    catch (string e) {
        cout << "marmore; ";
    }
    cout << "fim; \n"; */
    
    f();
    
    return 0;
}
