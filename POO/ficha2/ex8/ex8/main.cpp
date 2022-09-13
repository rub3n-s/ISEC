//
//  main.cpp
//  ex8
//
//  Created by rsantos on 27/10/2021.
//

#include <iostream>
#include <sstream>

using namespace std;

class Pessoa {
    char genero;
    string nome;
    int idade;
    int altura;
    
    bool temCarta = false;
    bool estuda = false;
    
public:
    Pessoa(char g, string n, int i, int a) : genero(g), nome(n), idade(i), altura(a) {
        if (a < 0)
            altura = 150;
        if (i < 0)
            idade = 0;
        if (genero != 'F' && genero && 'M')
            cout << "M/F" << endl;
    }
    
    string getAsString() const;
    
    void temCartaCarro();
    void pessoaEstuda();
    
    char getGenero() const { return genero; }
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    int getAltura() const { return altura; }
};

void Pessoa::temCartaCarro() {
    if (idade >= 18)
        temCarta = true;
    else {
        cout << "Ainda é menor de idade!\n";
    }
}

void Pessoa::pessoaEstuda() {
    estuda = true;
}
string Pessoa::getAsString() const {
    ostringstream os;
    os << "genero: " << genero << ", nome: " << nome << ", idade: " << idade << ", altura: " << altura;
    if (temCarta)
        os << ", já tem carta de carro. ";
    else
        os << ", ainda não tem carta de carro ";
    if (estuda)
        os << "e estuda\n";
    else
        os << "e não estuda\n";
    return os.str();
}
int main(int argc, const char * argv[]) {
    Pessoa p1('F', "Ana", 22, 164);
    
    p1.pessoaEstuda();
    cout << p1.getAsString();
    
    return 0;
}
