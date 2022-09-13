//
//  main.cpp
//  ex6
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#include <sstream>

using namespace std;

class Automovel {
    string matricula;
    string marca;
    string modelo;
    string cor;
    int combustivel;
    bool ligado;
    
public:
    Automovel(string mat, string m, string mo, string c, int co) : matricula(m), marca(m), modelo(mo), cor(c), combustivel(co) {
        if (m == "")
            matricula = "00-AA-00";
        ligado = false;
    }
    
    void mostraCarro() const;
    string getAsString() const;
    void ligarCarro();
    void desligarCarro();
};

void Automovel::mostraCarro() const {
    cout << "Matricula: " << matricula << ", Marca: " << marca << ", Modelo: " << modelo << ", Cor: " << cor << ", Combustivel: " << combustivel << endl;
}

string Automovel::getAsString() const {
    ostringstream os;
    os << "Carro está ";
    if (ligado)
        os << "ligado, ";
    else
        os << "desligado, ";
    os << "com as caracteristicas: \n";
    os << "Matricula: " << matricula << ", Marca: " << marca << ", Modelo: " << modelo << ", Cor: " << cor << ", Combustivel: " << combustivel << endl;
    return os.str();
}

void Automovel::ligarCarro() {
    if (ligado)
        cout << "carro ja esta ligado\n";
    else
        ligado = true;
}

void Automovel::desligarCarro() {
    if (!ligado)
        cout << "carro ja esta desligado\n";
    else
        ligado = false;
}

int main(int argc, const char * argv[]) {
    Automovel a("", "mercedes", "c220", "amarelo", 60);
    
    //a.desligarCarro();
    a.ligarCarro();
    cout << a.getAsString();
    
    return 0;
}
