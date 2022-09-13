//
//  main.c
//  ex4
//
//  Created by rsantos on 30/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#define TAM 100

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

void mostra_fich1(char* nome) {
    char linha[TAM+1];
    FILE *f = fopen(nome, "rt");
    
    if(!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n", nome);
        return;
    }
    
    while(fgets(linha,TAM,f))
        printf("%s", linha);
    
    fclose(f);
}

void mostra_fich2(char* nome) {
    char c;
    FILE *f = fopen(nome, "rt");
    
    if(!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n", nome);
        return;
    }
    
    while((c = fgetc(f)) != EOF)
        putchar(c);
    
    fclose(f);
}

int main(int argc, const char * argv[]) {
    
    mostra_fich("ex4.txt");
    puts("\n----------------------------------------------------------------\n");
    
    mostra_fich1("ex4.txt");
    puts("\n----------------------------------------------------------------\n");

    mostra_fich2("ex4.txt");
    puts("\n----------------------------------------------------------------\n");
    
    return 0;
}
