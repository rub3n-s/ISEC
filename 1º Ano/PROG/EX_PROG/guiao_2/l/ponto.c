
#include <stdio.h>
#include "ponto.h"

// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D* p){
    printf("\nCoordenadas ponto p2 (x,y): ");
    scanf("%d,%d",&p->x,&p->y);
    //(*p).x=1;
    //(*p).y=2;
    //p->x=1;
    //p->y=2;
}
// alinea d)
void movePonto(ponto2D* p, int dx, int dy){
    p->x+=dx;
    p->y+=dy;
}

//alinea c)

int retaPonto(ponto2D p1, ponto2D p2, ponto2D p3)
{
    int det;

    det = p1.x*p2.y+p1.y*p3.x+p2.x*p3.y-p2.y*p3.x-p1.y*p2.x-p3.y*p1.x;
    if(!det)
        return 1;
    else
        return 0;
}
