#include <iostream>
#include <sstream>
#include <vector>
#include <initializer_list>

using namespace std;

class Televisao {
    static const int MAX_CANAIS = 10;
    vector<string> canais;
    bool ligada;
    int som = 0;
    int canalAtual;
    int numCanais = 0;

public:
    Televisao(initializer_list<string> ca);

    void ligaTV();
    void desligaTV();
    void aumentaSom();
    void diminuiSom();
    void getCanais() const;
    //void getCanalAtual() const { return canalAtual; };
    void setCanal(int c);

    string getAsString() const;
};

Televisao::Televisao(initializer_list<string> ca) {
    for (auto c : ca) {
        if (numCanais < MAX_CANAIS) {
            canais.push_back(c);
            numCanais++;
        }
    }
    ligada = false;
    som = 5;
    
    if (!canais.empty())
        canalAtual = 1;
}
void Televisao::ligaTV() {
    if (!ligada)
        ligada = true;
    else
        cout << "A Tv já está ligada!\n";
}

void Televisao::desligaTV() {
    if (ligada)
        ligada = false;
    else
        cout << "A Tv já está desligada!\n";
}

void Televisao::aumentaSom() {
    if (som < 10)
        som++;
    else
        cout << "Som já está no máximo ( 10 )";
}

void Televisao::diminuiSom() {
    if (som > 0)
        som--;
    else
        cout << "Som já está no mínimo";
}

void Televisao::getCanais() const {
    for (auto c : canais)
        cout << c << endl;
}

void Televisao::setCanal(int c) {
    if (c >= 0 && c < numCanais)
        canalAtual = c;
}

string Televisao::getAsString() const {
    ostringstream os;
    
    if (ligada)
        os << "Tv ligada, ";
    else
        os << "Tv desligada, ";

    if (!canais.empty())
        os << "no canal " << canalAtual << ": " << canais[canalAtual-1];

    os << ", com o som no volume: " << som << "." << endl;

    return os.str();
}
int main() {
    //vector<string> canais = {"rtp1", "rpt2", "sic", "tvi"};

    Televisao t({"rtp1", "rpt2", "sic", "tvi"});

    cout << t.getAsString();

    return 0;
}
