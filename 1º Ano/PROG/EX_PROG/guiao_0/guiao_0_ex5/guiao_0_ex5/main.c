//
//  main.c
//  guiao_0_ex5
//
//  Created by rsantos on 20/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define DIM 5

#include <stdio.h>

int encontraNum(int tab[], int dim, int num) {
    for (int i = 1; i <= dim; i++) {
            if (num == tab[i])
                return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int tabela[DIM] = {1,2,3,4,5};
    int numero;
    
    printf("Número: ");
    scanf("%d", &numero);
    
    printf("%d\n", encontraNum(tabela, DIM, numero));
    
    return 0;
}
