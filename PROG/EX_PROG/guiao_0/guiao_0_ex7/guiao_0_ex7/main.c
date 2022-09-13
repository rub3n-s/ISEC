//
//  main.c
//  guiao_0_ex7
//
//  Created by rsantos on 20/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define DIM 5

#include <stdio.h>
#include <math.h>

float stdDev(int dim) {
    int tab[dim];
    float sd = 0, media = 0, soma = 0;
    
    for (int i = 1; i <= DIM; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &tab[i]);
        
        media += tab[i];
    }
    
    media /= dim;
    
    for (int i = 1; i <= DIM; i++) {
        soma += pow(media-tab[i],2);
    }
    
    sd = sqrt(soma/DIM);
    
    return sd;
}


int main(int argc, const char * argv[]) {
    
    printf("\nDesvio Padrão: %f\n\n", stdDev(DIM));
    
    return 0;
}
