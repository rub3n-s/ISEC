//
//  main.cpp
//  ex10
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#include <vector>
#include <initializer_list>
#include <sstream>
using namespace std;

class Eleitor {
    int numEleitores = 0;
    int maiorNum = 0;
    int menorNum = 0;
    vector<int> eleitores;
    
public:
    Eleitor(initializer_list<int> el){
        for (auto e : el) {
            if (e >= 1000 & e <= 9999) {
                eleitores.push_back(e);
                ++numEleitores;
            }
            else
                cout << "Eleitor '" << e << "' está fora dos limites!" << endl;
        }
        
        if (eleitores.empty())
            cout << "lista vazia\n";
    }
    Eleitor(int x);
    
    void removeEleitor(int x);
    void removeEleitorEntre(int x, int y);
    void getMaiorNum();
    void getMenorNum();
    
    string getAsString() const;
};

Eleitor::Eleitor(int x) {
    if (x >= 1000 && x <= 9999) {
        eleitores.push_back(x);
        ++numEleitores;
    }
    else
        cout << "\nEleitor '" << x << "' fora dos limites!\n" << endl;
}

void Eleitor::removeEleitor(int x) {
    int i = 0;
    for (auto e : eleitores) {
        if (x == e)
            eleitores.erase(eleitores.begin() + i);
        i++;
    }
}

void Eleitor::removeEleitorEntre(int x, int y) {
    int i = 0;
    for (auto e : eleitores) {
        if (e >= x && e <= y) {
            eleitores.erase(eleitores.begin() + i);
            i = 0;
        }
        i++;
    }
}

string Eleitor::getAsString() const {
    ostringstream os;
    os << "\nLista de Eleitores: \n";
    for (auto e : eleitores)
        os << "\t" << e << endl;
    os << "\nNúmero Total de Eleitores: " << numEleitores << endl;
    os << "Maior numero: " << maiorNum << endl;
    os << "Menor numero: " << menorNum << endl;
    return os.str();
}

int main(int argc, const char * argv[]) {
    //vector<string> eleitores = {"Jose", "Manel", "Joao", "Pedro", "Antonio"};
    Eleitor e({1000, 999, 1223, 4145, 5653, 5312, 9877, 123});
    
    cout << e.getAsString();
    
    Eleitor x(100);
    cout << e.getAsString();
    
    e.removeEleitor(1000);
    cout << e.getAsString();
    
    e.removeEleitorEntre(1000, 7146);
    cout << e.getAsString();
    
    return 0;
}
