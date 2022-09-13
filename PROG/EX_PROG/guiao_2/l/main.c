#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{
    ponto2D p1 = {1,1}, p2, p3={3,3};

    //alinea b)
    printPonto(p1);

    initPonto(&p2);



    printPonto(p2);

    movePonto(&p1, 3, -2);
    printPonto(p1);
    if(retaPonto(p1,p2,p3))
        printf("Os pontos pertencem a mesma reta");
    else
        printf("Os pontos nao pertencem a mesma reta");

    return 0;
}
