//
//  main.c
//  ex7
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//
#define TAM 5

#include <stdio.h>
#include <math.h>

float calculaDesvio(int tam) {
    int tab[TAM];
    float media = 0, soma = 0, desvio = 0;
    
    for (int i = 0; i < TAM; i++) {
        printf("Posição %d: ", i + 1);
        scanf("%d", &tab[i]);
        
        media+=tab[i];
    }
    
    media = media/TAM;
    
    for (int i = 0; i < TAM; i++) {
        soma += pow(media - tab[i], 2);
    }
    
        
    desvio = sqrt(soma/TAM);
    
    return desvio;
}

int main(int argc, const char * argv[]) {
    
    printf("\n%f\n\n",calculaDesvio(TAM));
    
    return 0;
}
