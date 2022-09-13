//
//  main.c
//  ficha4ex4
//
//  Created by Rúben Mendes Santos on 29/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m, n, resultado, soma, i, digito;
    
    do {
        printf("x, y: \n");
        scanf("%d, %d", &m, &n);
    } while(!(m >= 100 || n <= 999 || m < n));
    
    for (i = m; i<= n; i++) {
        resultado = i;
        soma = 0;
        
        do {
            digito = resultado % 10;
            resultado /= 10;
            soma += digito * digito * digito;
        } while(resultado > 0);
        
        if (soma == i) {
            printf("soma = %d\n", i);
        }
    }
    
    return 0;
}
