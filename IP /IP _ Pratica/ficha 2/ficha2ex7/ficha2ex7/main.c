//
//  main.c
//  ficha2ex7
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float freq1, freq2, trab, nota_final;
    
    do {
        printf("1 Frequencia (0 - 20):");
        scanf("%f", &freq1);
    } while(freq1 < 0 || freq1 > 20);
    
    do {
        printf("2 Frequencia (0 - 20):");
        scanf("%f", &freq2);
    } while(freq2 < 0 || freq2 > 20);
    
    do {
        printf("Trabalho(0-100):");
        scanf("%f", &trab);
    } while(trab < 0 || trab > 100);
    
    nota_final = 0.4 * freq1 + 0.4 * freq2 + 0.02 * trab;
    
    printf("F1 = %.2f\n", freq1);
    printf("F2 = %.2f\n", freq2);
    printf("T = %.2f\n", trab);
    
    printf("\n\nNota Final = %f", nota_final);
    
    return 0;
}
