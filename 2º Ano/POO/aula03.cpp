#include <iostream>
#include <string>
using namespace std;

//7. Escreva um programa em C++ que peça o nome completo do utilizador e 
//depois imprima os vários nomes desse utilizador, cada um numa linha 
//diferente.
void confirma_nome() {
    string s = "";

    cout << "Insira o seu nome Completo: ";
    getline(cin, s);

    string p = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ') {
            p += s[i];
        }
        else if (s[i] == ' ') {
            cout << p << endl;
            if (p == "Silva")
                cout << "Conheco o Nome Silva";
            p.clear();
        }
    }
    cout << p << endl;
    if (p == "Silva")
        cout << "Conheco o Nome Silva";
}

void verifica() {
    string nome;
    cout << "Insira o seu nome Completo: ";
    getline(cin, nome);
    for (int i = 0; i < nome.length(); i++) {
        if (nome[i] == ' ' && i > 0 && nome[i-1] != ' ') {
            cout << "\n";
        } else
            cout << nome[i];
    }
}
#include <sstream> //devia ser no início do ficheiro
void exemplo1() {
    istringstream ss;
    istringstream s2("Bom    dia   amigo");
    string palavra;
    while (s2 >> palavra)
        cout << palavra << endl;

    cout << "guardado em s2: " << s2.str() << endl;

    s2.str("outra frase diferente");
    cout << "guardado em s2: " << s2.str() << endl;
}
void f1e07() {
    cout << "Nome: ";
    string nome;
    getline(cin, nome);
    istringstream s2(nome);
    string palavra, aux = "";
    bool silva = false;
    while (s2 >> palavra) {
        cout << palavra << endl;
        if (palavra == "Silva")
            silva = true;
    }
    if (silva)
        cout << "Conheco o nome Silva" << endl;
}
string intToString(int n) {
    string numeros[10] = { "um", "dois", "tres", "quatro",
        "cinco", "seis", "sete", "oito", "nove", "dez" };
    if (n < 1 || n > 10) //entrada inválida
        return "";
    else
        return numeros[n-1];
}
int stringToInt(string s) { 
    string numeros[10] = { "um", "dois", "tres", "quatro",
        "cinco", "seis", "sete", "oito", "nove", "dez" };
    for (int i = 0; i < 10; i++)
        if (s == numeros[i])
            return (i + 1);
    return 0;
}
void f1e09() {
    bool fim = false;
    int numero;
    string palavra;
    while (!fim) {
        cout << "\nIntroduza um inteiro entre 1 e 10 (FIM para terminar): ";
        if (cin >> numero) {
            palavra = intToString(numero);
            if (palavra == "")
                cout << "invalido!" << endl;
            else
                cout << palavra << endl;
        }
        else {
            cin.clear();
            cin >> palavra;
            if (palavra == "FIM")
                fim = true;
            else {
                numero = stringToInt(palavra);
                if (numero == 0)
                    cout << "invalido!" << endl;
                else
                    cout << numero << endl;
            }
        }
    }
}
struct Dados_venda {
    string numero_livro;
    unsigned unidades_vendidas;
    double receita;
};
#define N 15 //Tamanho da matriz da tabela. Devia estar no início do ficheiro
struct Tabela {
    int mat[N];
};
void preenche(Tabela &t, int n) {
    for (int i = 0; i < N; i++) {
        t.mat[i] = n;
    }
}
void listar(Tabela t) {
    for (int i = 0; i < N; i++) {
        cout << t.mat[i] << "  ";
    }
    cout << endl;
}
int elementoAt(Tabela t, int pos) {
    if (pos >= 0 && pos < N)
        return t.mat[pos];
    else
        return 0;
}
Tabela modifyAt(Tabela t, int pos, int num) {
    if (pos >= 0 && pos < N) {
        t.mat[pos] = num;
        return t;
    }
}
string &maisCurta(string &s1, string &s2) {
    if (s1.size() < s2.size())
        return s1;
    else
        return s2;
}
int &elementoEm(Tabela &t, int pos) {
    if (pos >= 0 && pos < N)
        return t.mat[pos];
    else
        return t.mat[0];
}
int main() {
    Tabela a;
    cout << elementoEm(a, 10) << endl; // aparece um determinado valor
    elementoEm(a, 10) = 15; // notar que a chamada à função fica
    // do lado esquerdo da atribuição
    cout << elementoEm(a, 10) << endl; // aparece 15
    
    /*
    string mc = "mais curta", mcc = "mais comprida";
    string s = maisCurta(mc, mcc);

    cout << s << endl;
    cout << "mc: " << mc << endl;

    maisCurta(mc, mcc) = "ola";
    cout << "mc: " << mc << endl;
    */
    /*Tabela tab;
    preenche(tab, 5);
    listar(tab);
    tab = modifyAt(tab, 0, 1);
    listar(tab);
    */
/*    listar(tab);
    cout << elementoAt(tab, -1) << endl;
    cout << elementoAt(tab, 1) << endl;
    */

   //Dados_venda livro1;
   //livro1.numero_livro = "12EA4";
    
    //f1e09();
    //exemplo1();
    //verifica();
    //confirma_nome();
}

