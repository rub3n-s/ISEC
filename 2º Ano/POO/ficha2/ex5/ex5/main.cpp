//
//  main.cpp
//  ex5
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>

using namespace std;

struct Automovel {
    string matricula;
    string marca;
    string modelo;
    string cor;
    int combustivel;
} automovel;

Automovel criaAutomovel(string m, string ma, string mo, string c, int co) {
    Automovel a;
    if (m == "")
        a.matricula = "00-AA-00";
    else
        a.matricula = m;
    a.marca = ma;
    a.modelo = mo;
    a.cor = c;
    a.combustivel = co;
    return a;
}

void mostraAutomovel(Automovel a) {
    cout << "Matricula: " << a.matricula << ", Marca: " << a.marca << ", Modelo: " << a.modelo << ", Cor: " << a.cor << ", Combustivel: " << a.combustivel << endl;
}
int main(int argc, const char * argv[]) {
    Automovel a;
    
    a = criaAutomovel("99-AA-55","mercedes", "c220", "vermelho", 60);
    mostraAutomovel(a);
    cout << a.marca << endl;
    return 0;
}
