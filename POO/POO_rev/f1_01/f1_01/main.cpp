//
//  main.cpp
//  f1_01
//
//  Created by rsantos on 08/01/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void imprime(string a) {
    cout << a;
}

void imprime(string a, int b) {
    cout << a << " " << b;
}

void imprime(int b, string a) {
    cout << b << " " << a;
}

/*int soma(int a = 0) {
    int soma = 0;
    soma+=a;
    return soma;
} */

int soma(int a = 0, int b = 0, int c = 0) {
    int soma = 0;
    soma = a + b + c;
    return soma;
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void troca(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void imprimeNome(string nome) {
    for(int i = 0; i < nome.length(); i++) {
        if (nome[i] == ' ')
            cout << "\n";
        else
            cout << nome[i];
    }
}

void testaPalavra() {
    string palavra;
    size_t i;
    int k, l;
    int cont;
    
    do {
        cout << "palavra: ";
        cin >> palavra;
        
        for (i = 0; i < palavra.size(); i++) {
            cout << palavra[i];
        }
        cout << endl;
        for (i = palavra.size(); i > 0; i--)
            cout << palavra[i-1];
        cout << "\n";

        k = 0;
        l = palavra.size();
        
        do {
            cont = 0;
            cout << "k=" << k << "\tl=" << l << endl;
            if (palavra[k] == palavra[5])
                cont++;
            cout << palavra[k];
            cout << palavra[l];
            k++; l--;
        } while(cont < palavra.size());
        
        /*for(i = 0; i < palavra.size(); i++) {
            for (j = palavra.size(); j > 0; j--)
                if (palavra[i] == palavra[j-1])
                    cont++;
        } */
        
        if (cont == palavra.size())
            cout << "capicua!" << endl;
        else
            cout << "não é capicua!" << endl;
        
        
    } while(palavra != "fim");
}

string numExt(int n) {
    string num[] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
    
    if (n<=0 || n > 10)
        return 0;
    
    return num[n-1];
}

int numInt(string ext) {
    string num[] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};
    for (int i = 0; i < 10; i++) {
        if (num[i] == ext)
            return i+1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    /* --------- ex1,2,3 ---------
    string nome;
    int idade;
    
    cout << "nome: ";
    cin >> nome;
    
    cout << "idade: ";
    cin >> idade;
    
    cout << "nome: " << nome << "\tidade: " << idade << endl; */
    
    /* --------- ex4 ---------
    imprime("ola");
    cout << "\n";
    
    imprime("a idade é: ", 25);
    cout << "\n";
    
    imprime(100, "euros");
    cout << "\n";
    */
    
    /* --------- ex5 ---------
    cout << "\n" << soma() << soma(1);
    cout << soma(1,2) << soma(1,2,3) << endl;
    */
    
    /* --------- ex6 ---------
    int a = 5, b = 10;
    //troca(&a,&b);
    troca(a,b);
    cout << "\na = " << a << "\nb = " << b << endl;
    */
    
    /* --------- ex7 ---------
    imprimeNome("Ruben Mendes Santos");
    cout << "\n";
    */
    
    /* --------- ex8 ---------
    testaPalavra();
     */
    
     /* --------- ex9 --------- */
    cout << numExt(1) << endl;
    cout << numInt("dois") << endl;
    return 0;
}
