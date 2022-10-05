#include <iostream>
#include <fstream>
#include <string>
#include "pessoa.h"
#include "conta.h"
#include "banco.h"


bool getDadosPessoa(std::istream &is, string &s, string &bi, int &nif) {
    std::getline(is, s);
    is >> s >> nif;
    if (is.fail() == true) {
        is.clear();
        s = "";
        bi = "";
        nif = -1;
        return false;
    }
    return true;
}

int main()
{
    Banco b("Banco XPTO");
//    std::cout << "Banco b: " << b.getAsString() << "\n";
    
    string nomeP, ccP;
    int numCont;
    std::ifstream f("dados.txt");
    std::cout << getDadosPessoa(f, nomeP, ccP, numCont)<< "\n";
    f.close();
    //    getDadosPessoa(std::cin, nomeP, ccP, numCont);
    Pessoa p(nomeP, ccP, numCont);
    std::cout << "Pessoa p: " << p.getAsString() << "\n";

    
    /*
    //    Conta c(&p);
//    std::cout << "Conta c: " << c.getAsString() << "\n";
    b.addConta(c);
    Pessoa p2("Jose Manuel", "1234567891TR1", 123345567);
    Conta c2(&p2);
    b.addConta(c2);
    std::cout << "Banco b, depois de adicionar contas: " << b.getAsString() << "\n";
    b.deposita(p2.getCC(), 100);
    b.delConta(p2.getCC());
    std::cout << "Banco b, depois de apagar: " << b.getAsString() << "\n";

    /*   c.deposita(100);
    std::cout << "Conta c depois do deposita: " << c.getAsString() << "\n";
    c.levanta(50);
    std::cout << "Conta c depois do levanta: " << c.getAsString() << "\n";
    std::cout << "Titular da Conta c: " << c.getTitular().getAsString() << "\n";
*/}
