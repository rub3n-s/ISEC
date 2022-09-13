//
//  main.cpp
//  teste
//
//  Created by rsantos on 12/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <type_traits>

using namespace std;

class Plant {
public:
    void feed() {
        cout << "Planta semear \n";
    }
    virtual void growUp() { cout << "Planta crescer \n"; };
    virtual ~Plant() {}
};

class Pine : public Plant {
public:
    void feed() { cout << "Feijoeiro semear \n"; }
    void growUp() override { cout << "Feijoeiro crescer \n"; }
    ~Pine() override { cout << "Destr Feijoeiro \n";}
};


class AvariaPneu {
public:
    AvariaPneu() {}
};

class AvariaMotor {
public:
    AvariaMotor() {}
};


void testar(string s) {
    try {
        if (s == "pneu") {
            throw AvariaPneu();
        }
        else if (s == "motor") {
            throw AvariaMotor();
        }
    } catch (AvariaPneu & e) {
        cout << "avaria pneu; ";
    } catch (AvariaMotor & e) {
        cout << "avaria motor; ";
        throw;
    }
    cout << "andar";
}

int main(int argc, const char * argv[]) {
    /*cout << "--------------\n";
    Plant * x = new Pine;
    x->feed();
    x->growUp();
    
    cout << "--------------\n";
    shared_ptr<Plant> c = make_shared<Pine>();
    c->growUp(); */
    
    try {
        testar("motor");
        testar("pneu");
        cout << "destino; ";
    } catch (AvariaPneu &e){
        cout << "reparar pneu; ";
    } catch (AvariaMotor &e) {
        cout << "reparar motor; ";
    }
    cout << "fim; \n";
    
    return 0;
}
