#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Poema
{

public:
    Poema (const string &t);
    ~Poema ();

    void acrescentaVerso(const string& verso);
    void eliminaVerso(int ordem);

    Poema & operator=(const Poema & ob);
    
    string getAsString() const;

private:
    string titulo;
    string* pVersos;
    int nVersos = 0;

};

Poema ::Poema (const string& tVerso) : titulo(tVerso) {}

Poema ::~Poema ()
{
}

string Poema::getAsString() const {
    ostringstream os;
    os << "Titulo: " << titulo << endl;
    os << "Versos: " << endl;
    for (int i = 0; i < nVersos; i++)
        os << pVersos[i] << endl;
    return os.str();
}

void Poema:: acrescentaVerso(const string& verso) {
    string *aux = new string[nVersos+1];
    
    if (pVersos == nullptr || nVersos == 0) {
        pVersos[nVersos] = verso;
        ++nVersos;
        return;
    }
    
    for (int i = 0; i < nVersos; i++)
        aux[i] = pVersos[i];
    
    aux[nVersos] = verso;
    ++nVersos;
    delete [] pVersos;
    pVersos = aux;
}

void Poema::eliminaVerso(int ordem) {
    if (ordem < 0 || ordem >= nVersos) { return; }
    
    if (nVersos == 1) {
        delete [] pVersos;
        pVersos = nullptr;
        nVersos = 0;
        return;
    }
    
    string *aux = new string[nVersos - 1];
    for (int i = 0; i < ordem; i++) {
        aux[i] = pVersos[i];
    }
    
    for (int i = ordem; i < nVersos - 1; i++) {
        aux[i] = pVersos[i + 1]; // compensar o facto de haver um no meio que tem de se retirar
    }
    
    --nVersos;
    delete[] pVersos;
    pVersos = aux;
}

Poema & Poema::operator= (const Poema & ob)
{
    if (this == &ob)
    {
        return *this;
    }
    // se os dois membros da atribuição forem objetos diferentes
    titulo = ob.titulo;
    nVersos = ob.nVersos;
    // libertar a memoria dinamica usada exclusivamente pelo primeiro membro
    delete[] pVersos;
    pVersos=nullptr;
    // se a origem da copia for de um poema sem versos
    if (ob.pVersos == nullptr || ob.nVersos == 0) {
        return *this;
    }
    // reservar memoria dinamica para conter uma copia exclusiva dos versos do segundo membro
    pVersos = new string[ob.nVersos];
    // fazer a cópia
    for  (int i = 0; i < ob.nVersos; i++)
    {
        pVersos[i] == ob.pVersos[i];
    }
    return *this;

}


int main()
{
    cout << "Construtor por cópia:\n";
    Poema a("Liberdade");
    Poema b(a);
    cout << b.getAsString() << endl;
    
    b.acrescentaVerso("hello asd");
    cout << b.getAsString() << endl;
}
