//
//  main.c
//  ficha4ex9
//
//  Created by Rúben Mendes Santos on 22/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int num = 0, num_max = 0, posicao_max = 0, tamanho = 0;
    
    do {
        printf("Número: ");
        scanf("%d", &num);
        
        tamanho++;
        
        if(num > num_max) {
            posicao_max = tamanho;
            num_max = num;
        }
    } while(num > 0);
    
    printf("Máximo: %d | Posição Maximo: %d | Tamanho da sequencia: %d \n", num_max, posicao_max, tamanho - 1);
    return 0;
}
