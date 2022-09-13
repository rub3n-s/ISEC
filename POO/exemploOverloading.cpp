/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
using namespace std;

void xpto(int valor){
    cout << "Xpto 1ª versão\n";
}


int xpto(string str){
    cout << "Xpto 2ª versão\n";
}

int xpto(int valor, char c){
    cout << "Xpto 3ª versão\n";
}
//Intelisense
void xpto2(){
    cout << "Vazio1\n";
}

void xpto2(char c, char a='a', char b='b'){ //ERRO! Os valores por omissão
                                            //devem vir no início da lista
    cout << "c:" << c << "\ta:" << a << "\tb:" << b << endl;
}
void incrementa(int *var){ //ponteiro
    cout << "Versão ponteiro!\n";
    (*var)++;
}

void incrementa(int &var){ //referência
    var++;
}


int main(){
    xpto(2);
    cin.get();
    xpto(2, 'a');
    cin.get();
    xpto("olá");
    cin.get();
    xpto('a');
    int i='a';
    string str="b";
    
    xpto2(); //O que aparece?
    xpto2('A'); //O que aparece? A a b
    xpto2('A', 'C'); //O que aparece? A C b
    
    int a1=10;
    incrementa(&a1);
    cout << "a1 modificado =" << a1;
    
    int a2=10;
    incrementa(a2);
    cout << "a2 modificado =" << a2;
    
    
    return 0;
}