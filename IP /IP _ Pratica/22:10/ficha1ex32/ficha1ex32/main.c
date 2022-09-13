//
//  main.c
//  ficha1ex32
//
//  Created by Rúben Mendes Santos on 22/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num, soma = 0, digito;
    
    printf("Introduza numero: ");
    scanf("%d", &num);
    
    do {
        digito = num % 10;
        num = num / 10;
        
        printf("Digito: %d\n", digito);
        
        soma = soma + digito;
    } while (num > 0);
    
    printf("Soma = %d\n", soma);
    
    return 0;
}
