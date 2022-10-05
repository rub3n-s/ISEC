//
//  main.c
//  ex5
//
//  Created by rsantos on 30/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

void duplicaConteudo(FILE* origem, FILE* destino) {
    char ler[100];
    FILE *f = fopen(origem, "rt");
    
    if (!f) {
        fprintf(stderr, "Não foi possivel abrir o ficheiro origem");
        return;
    }
    
    FILE *g = fopen(destino, "wt");
    
    if(!g) {
        printf("Não foi possivel abrir o ficheiro destino!\n");
        fclose(f);
        return;
    }
    
    while (fgets(ler,TAM,f))
        fputs(ler,g);
    
    fclose(f);
    fclose(g);
}

void mostra_fich(char* nome) {
    char linha[TAM+1];
    FILE *f = fopen(nome, "rt");
    
    if(!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n", nome);
        return;
    }
    
    while(fgets(linha,TAM,f))
        fputs(linha,stdout);
    
    fclose(f);
}

int main(int argc, const char * argv[]) {
    
    printf("\n---------------------Duplica Ficheiro---------------------\n");
    duplicaConteudo("ex4.txt","ex5.txt");
    
    printf("\n----------------------Mostra Ficheiro---------------------\n");
    mostra_fich("ex5.txt");
    
    return 0;
}
