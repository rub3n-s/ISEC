#include <iostream>
#include <string>

using namespace std;

class Ponto {
    int x;
    int y;
public:
    Ponto(int xx, int yy) {
        cout << "Construindo..." << "\n";
        x = xx;
        y = yy;
    }

    ~Ponto() { cout << "Destruindo..." << "\n"; }

    void imprime() {
        cout << x << "," << y << "\n";
    }
};

int main()
{
    Ponto* p = new Ponto[3]{ Ponto(2,3),Ponto(1,3),Ponto(2,3)};
    for (int i = 0; i < 3; i++)
    {
        p[i].imprime();
    }
    
    delete [] p;

}
