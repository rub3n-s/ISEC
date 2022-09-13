//
//  main.c
//  ficha2ex9
//
//  Created by Rúben Mendes Santos on 17/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int n, soma = 0;
    
    printf("Número de 3 digitos: ");
    scanf("%d", &n);
    
    while (n != 0)
    {
        soma += n % 10;
        printf("\nsoma = %d\n", soma);
        
        n = n/10;
        printf("n = %d\n", n);
    }
    
    printf("\nSoma Final =%d\n", soma);

    
    return 0;
}
