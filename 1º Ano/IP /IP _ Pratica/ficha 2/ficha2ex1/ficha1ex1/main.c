//
//  main.c
//  ficha1ex1
//
//  Created by Rúben Mendes Santos on 16/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int raio;
    
    printf("Insira o raio: ");
    scanf("%d", &raio);
    
    printf("Área = %f\n", 3.14 * raio * raio);
    printf("Perímetro = %f\n", 2 * 3.14 * raio);
    return 0;
}
