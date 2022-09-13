#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED

//alinea a)
typedef struct ret
{
    ponto2D cantoSE;
    int altura;
    int largura;
}retangulo;

void printRetangulo(retangulo r);

void initRetangulo (retangulo* r);

int areaRetangulo(retangulo r);
int dentroRetangulo(retangulo r, ponto2D p);
void moveRetangulo(retangulo* r, int dx, int dy);
#endif // RETANGULO_H_INCLUDED
