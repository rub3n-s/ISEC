//
//  main.c
//  guiao_0_ex13
//
//  Created by rsantos on 27/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define TAM 50

#include <stdio.h>
#include <string.h>

void comparaFrases(char frase1[TAM], char frase2[TAM], char resultado[TAM]) {
    if(!strcmp(frase1, frase2))
        strcpy(resultado, "Conteudo Igual!");
    else if (strlen(frase1) == strlen(frase2))
        strcpy(resultado, "Tamanho Igual");
    else {
        if (strlen(frase1) <= strlen(frase2)) {
            strcat(resultado, frase1);
            strcat(resultado, " ");
            strcat(resultado, frase2);
        }
        else {
            strcat(resultado, frase2);
            strcat(resultado, " ");
            strcat(resultado, frase1);
        }
    }
    
    puts(resultado);
}

int main(int argc, const char * argv[]) {
    char frase1[TAM];
    char frase2[TAM];
    char res[TAM];
    
    printf("Primeira frase: ");
    gets(frase1);
    
    printf("Segunda frase: ");
    gets(frase2);
    
    comparaFrases(frase1, frase2, res);
    
    return 0;
}
