#include "Mundo.h"

initializer_list <int> cpPlanicie = {1,1,1,1,1,1,2,2,2,2,2,2};
initializer_list <int> coPlanicie = {1,1,1,1,1,1,1,1,1,1,1,1};
initializer_list <int> cpMontanha = {0,0,1,1,1,1,1,1,1,1,1,1};
initializer_list <int> coMontanha = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> cpFortaleza = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> coFortaleza = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> cpMina = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> coMina = {1,1,1,2,2,2,1,1,1,2,2,2};
initializer_list <int> cpDuna = {1,1,1,1,1,1,1,1,1,1,1,1};
initializer_list <int> coDuna = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> cpCastelo = {3,3,0,0,0,0,3,3,0,0,0,0};
initializer_list <int> coCastelo = {1,1,1,1,1,1,1,1,1,1,1,1};
initializer_list <int> cpPescaria = {2,2,2,2,2,2,4,4,4,4,4,4};
initializer_list <int> coPescaria = {0,0,0,0,0,0,0,0,0,0,0,0};
initializer_list <int> cpRefugio = { 0,0,0,0,0,0,0,0,0,0,0,0 };
initializer_list <int> coRefugio = { 1,1,1,1,1,1,1,1,1,1,1,1 };

Mundo::Mundo() {

}

bool Mundo::carregaFich(string nome) {
    ifstream dados(nome);
    if (!dados) {
        cout << " Error";
        return false;
    }
	
    return true;
}

//CRIACAO DO MUNDO, ILHAS E CONTINENTES****************************************************************************************************
void Mundo::contaIlha(string nome, int& aux) {
    string ax;
    string sub;
    auto iti = ilhas.begin();
    while (iti != ilhas.end()) {
        ax = (*iti)->getNome();
        ax = ax.substr(0, ax.size() - 1);
        if (nome == ax) {
            aux++;
        }
        iti++;
    }
}

void Mundo::contaContinente(string nome,int &aux) {
    string ax;
    string sub;
    auto itc = continente.begin();
       while (itc != continente.end()) {
           ax = (*itc)->getNome();
           ax = ax.substr(0, ax.size() - 1);
           if (nome == ax) {
               aux++;
           }
           itc++;
       }
}

void Mundo::recebeIlha(string ilha, int num) {
    int aux = 1;                                             //Aux representa o poss�vel id do territorio
    if (ilha == "refugio") {
        contaIlha(ilha, aux);                 //Verifica quandos objetos j� estao criados no vetor
        while (num != 0) {
            Territorio* t = new Territorio(ilha, aux, 9, cpRefugio, coRefugio, 2);
            criaIlha(t);
            num--;                                        //ciclo num quantos objetos foram requisitados
            aux++;                                        //cada objeto vai incrementar o proximo id;
        }
    }
    if (ilha == "pescaria") {
        contaIlha(ilha, aux);
        while (num != 0) {
            Territorio* t = new Territorio(ilha, aux, 6, cpPescaria, coPescaria, 2);
            criaIlha(t);
            num--;
            aux++;
        }
    }
}

void Mundo::recebeContinente(string continente,int num) {
    int aux=1;                                             //Aux representa o poss�vel id do territorio
    if (continente == "planicie") {      
        contaContinente(continente, aux);                 //Verifica quandos objetos j� estao criados no vetor
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 5, cpPlanicie, coPlanicie, 1);
            criaContinente(t);
            num--;                                        //ciclo num quantos objetos foram requisitados
            aux++;                                        //cada objeto vai incrementar o proximo id;
        }
    }
    if (continente == "montanha") {
        contaContinente(continente, aux);
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 6, cpMontanha, coMontanha, 1);
            criaContinente(t);
            num--;
            aux++;
        }
    }
    if (continente == "fortaleza") {
        contaContinente(continente, aux);
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 8, cpFortaleza, coFortaleza, 1);
            criaContinente(t);
            num--;
            aux++;
        }
    }
    if (continente == "mina") {
        contaContinente(continente, aux);
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 5, cpMina, coMina, 1);
            criaContinente(t);
            num--;
            aux++;
        }
    }
    if (continente == "duna") {
        contaContinente(continente, aux);
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 4, cpDuna, coDuna, 1);
            criaContinente(t);
            num--;
            aux++;
        }
    }
    if (continente == "castelo") {
        contaContinente(continente, aux);
        while (num != 0) {
            Territorio* t = new Territorio(continente, aux, 7, cpCastelo, coCastelo, 1);
            criaContinente(t);
            num--;
            aux++;
        }
    }
}


void Mundo::criaContinente(Territorio *t) {
    continente.push_back(t);
}
void Mundo::criaIlha(Territorio* t) {
    ilhas.push_back(t);
}

string Mundo::listaContinente()const {
    ostringstream oss;
    auto itc = continente.begin();
    while (itc != continente.end()) {
        oss << (*itc)->getNome()<<endl;
        itc++;
    }
    return oss.str();
}
string Mundo::listaIlha()const {
    ostringstream oss;
    auto iti = ilhas.begin();
    while (iti != ilhas.end()) {
        oss << (*iti)->getNome() << endl;
        iti++;
    }
    return oss.str();
}
