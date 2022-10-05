//
//  main.c
//  ex1
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

int main(int argc, const char * argv[]) {
//    
//    ponto2D p1 = {1,1}, p2, p3={3,3};
//
//    //alinea b)
//    printPonto(p1);
//
//    initPonto(&p2);
//
//
//
//    printPonto(p2);
//
//    //movePonto(&p1, 3, -2);
//    
//    printPonto(p1);
//    
//    if(retaPonto(p1,p2,p3))
//        printf("Os pontos pertencem a mesma reta\n");
//    else
//        printf("Os pontos nao pertencem a mesma reta\n");

    
//    exercicio retangulo
    retangulo r1 = {{2,2}, 3, 6}, r2;
    printRetangulo(r1);
    
    initRetangulo(&r2);
    return 0;
}
