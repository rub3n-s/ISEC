//
//  retangulo.c
//  ex1
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

void printRetangulo(retangulo r) {
    printf("\nCanto SE: (%d, %d)", r.cantoSE.x, r.cantoSE.y);
    printf("\nCanto SD: (%d, %d)", r.cantoSE.x + r.largura, r.cantoSE.y);
    printf("\nCanto IE: (%d, %d)", r.cantoSE.x, r.cantoSE.y - r.altura);
    printf("\nCanto ID: (%d, %d)", r.cantoSE.x + r.largura, r.cantoSE.y - r.altura);
}

void initRetangulo(retangulo* r) {
    printf("Coordernadas do Canto SE (x,y): ");
    scanf("%d %d", &r->cantoSE.x, &r->cantoSE.y);
    
    printf("Altura: ");
    scanf("%d", &r->altura);
    
    printf("Largura: ");
    scanf("%d", &r->largura);
}
