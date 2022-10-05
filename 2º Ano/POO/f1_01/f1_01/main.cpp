//
//  main.cpp
//  f1_01
//
//  Created by rsantos on 16/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <iostream>
#define N 50

int main(int argc, const char * argv[]) {
    char nome[50];
    int idade;
    
    printf("Nome: ");
    scanf("%s", nome);
    
    printf("Idade: ");
    scanf("%d", &idade);
    
    printf("\nNome: %s \nIdade: %d\n", nome, idade);
    
    return 0;
}
