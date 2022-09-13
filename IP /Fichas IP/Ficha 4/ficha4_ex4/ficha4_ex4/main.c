//
//  main.c
//  ficha4_ex4
//
//  Created by rsantos on 11/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m, n, soma_cubos;
    int primeiro_digito, segundo_digito, terceiro_digito;
    
    do {
        printf("m: ");
        scanf("%d", &m);
        
        printf("n: ");
        scanf("%d", &n);
    } while(!(m >= 100 && m < n && n <= 999));
        
    for (int i = m; i <= n; i++) {
        primeiro_digito = i / 100;
        segundo_digito = (i / 10) % 10;
        terceiro_digito = i % 10;
        
        soma_cubos = primeiro_digito * primeiro_digito * primeiro_digito +
                     segundo_digito * segundo_digito * segundo_digito +
                     terceiro_digito * terceiro_digito * terceiro_digito;
        
        if (i == soma_cubos)
            printf("%d\n", i);
    }
    
    return 0;
}
