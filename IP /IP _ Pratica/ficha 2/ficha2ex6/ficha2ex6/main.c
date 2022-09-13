//
//  main.c
//  ficha2ex6
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    float duracao, velocidade, distancia_perc, consumo;
    
    printf("Duração da viagem (H): ");
    scanf("%f", &duracao);
    
    printf("Velocidade (KM/H): ");
    scanf("%f", &velocidade);
    
    distancia_perc = velocidade * duracao;
    consumo = distancia_perc / 6.5;
    
    printf("\nLitros consumidos: %f\n", consumo);
    printf("Distância percorrida: %f\n", distancia_perc);
    
    return 0;
}
