//
//  Agenda.hpp
//  ex6
//
//  Created by rsantos on 10/12/2021.
//

#ifndef Agenda_hpp
#define Agenda_hpp

#include <iostream>
#include <sstream>

using namespace std;

class Contacto {
    string nome;
    unsigned int tel;
public:
    Contacto(string n, unsigned int t) : nome(n), tel(t) {}
    Contacto(const Contacto & ob) { *this = ob; }
    string getNome() const { return nome; }
    int getTel() const { return tel; }
    void setNome(string s) { nome = s; }
    void setTel(unsigned int t) { tel = t; }
    Contacto &operator=(const Contacto & ob) {
        if (this == &ob)
            return *this;
        
        for (unsigned int i=0; i<30; i++)
            delete(lista[i]);
        
        nome = ob.nome;
        tel = ob.tel;
        
        return *this;
    }
};

class Agenda {
    Contacto * lista[30];  // os elementos não usados ficarão a NULL
    int nContactos = 0;
public:    
    Agenda() {
        for (unsigned int i=0; i<30; i++)
        lista[i]= NULL;
    }
    
    ~Agenda() {
        cout << "a destruir lista...\n";
        for (unsigned int i=0; i<30; i++)
            delete(lista[i]);
    }
    
    void adicionaContacto(string nome, unsigned int tel, int pos) {
        if (lista[pos] == NULL)
            lista[pos] = new Contacto(nome, tel);
        nContactos++;
    }
    
    void listarPos(int pos) {
        cout << "nome: " << lista[pos]->getNome() << ", telefone: " << lista[pos]->getTel();
    }
    
    void atualizarPos(string nome, int tel, int pos) {
        lista[pos]->setNome(nome);
        lista[pos]->setTel(tel);
    }
    
    string getAsString() const {
        ostringstream os;
        os << "Agenda com os contactos: " << endl;
        for (int i = 0; i < nContactos; i++)
            os << "nome: " << lista[i]->getNome() << ", telefone: " << lista[i]->getTel() << endl;
        return os.str();
    }
};

#endif /* Agenda_hpp */
