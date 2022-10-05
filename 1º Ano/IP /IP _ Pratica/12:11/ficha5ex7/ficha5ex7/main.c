//
//  main.c
//  ficha5ex7
//
//  Created by rsantos on 12/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int MostraTringuloInvertido(int num_linhas) {
    int i, j;
    
    //num_linhas fora do limite
    if (num_linhas <= 1 || num_linhas > 9) {
        printf("Numero de linhas fora dos limites!");
        return 0;
    }
    
    //ciclo para escrever linhas
    for (i = num_linhas; i >= 1 ; i--) {
        
        //ciclo para imprimir espaços
        for (j = 1; j <= (num_linhas - i); j++) {
            printf("  ");
        }
        
        //ciclo para números crescentes
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        //ciclo para números decrescentes
        for(j = (i - 1); j >= 1; j--) {
            printf("%d ", j);
        }
        
        printf("\n");
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {

    int linhas, sucesso;
    
    printf("Linhas: \n");
    scanf("%d", &linhas);
    
    sucesso = MostraTringuloInvertido(linhas);
    
    return sucesso;
}
