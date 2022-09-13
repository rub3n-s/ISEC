//
//  main.c
//  ficha1ex2
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c, l;
    
    printf("Insira o comprimento: ");
    scanf("%d", &c);
    
    printf("Insira a largura: ");
    scanf("%d", &l);
    
    printf("Área = %d\n", c * l);
    return 0;
}

