#include <iostream>
#include <sstream>
using namespace std;

class Automovel {
    string matricula = "00-AA-00";
    float combustivel = 0;
    string marca;
    string modelo;

public:
    Automovel(string in_matr, string mar, string mod) :
        matricula(in_matr), marca(mar), modelo(mod) {}
    
    string getMatricula() const;
    string getMarca() const;
    string getModelo() const;
    float getCombustivel() const;
    bool setMatricula(string novaM);

    string getAsString() const;
};
string Automovel::getMarca() const { return marca; }
string Automovel::getModelo() const { return modelo; }
string Automovel::getMatricula() const { return matricula; }
float Automovel::getCombustivel() const { return combustivel; }

bool Automovel::setMatricula(string nova) {
    if (nova == "00-AA-00")
        return false;
    matricula = nova;
    return true;
}

string Automovel::getAsString() const {
    ostringstream os;
    os << "Marca: " << marca << " Modelo: " << modelo << " Matricula: "
        << matricula << " Combustivel: " << combustivel;
    return os.str();
}

int main() {

    Automovel honda("12-OI-69", "Honda", "civic");

    cout << honda.getMatricula() << endl;
    
    honda.setMatricula("00-AA-00");

    cout << honda.getAsString() << endl;

    return 0;
}
