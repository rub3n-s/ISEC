
#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"


void printRetangulo(retangulo r)
{
    printf("\nCanto SE: (%d,%d)",r.cantoSE.x, r.cantoSE.y);
    printf("\nCanto SD: (%d,%d)",r.cantoSE.x+r.largura, r.cantoSE.y);
    printf("\nCanto IE: (%d,%d)",r.cantoSE.x, r.cantoSE.y-r.altura);
    printf("\nCanto ID: (%d,%d)",r.cantoSE.x+r.largura, r.cantoSE.y-r.altura);
}

void initRetangulo (retangulo* r)
{
    printf("\nCoordenadas canto Superior Esquerdo (x,y): ");
    scanf("%d,%d",&r->cantoSE.x,&r->cantoSE.y);
    printf("\nAltura: ");
    scanf("%d",&r->altura);
    printf("\nLargura: ");
    scanf("%d",&r->largura);
}

//alinea d)
int areaRetangulo(retangulo r)
{

}

//alinea e)
int dentroRetangulo(retangulo r, ponto2D p)
{

}


//alinea f)
void moveRetangulo(retangulo* r, int dx, int dy)
{

}

