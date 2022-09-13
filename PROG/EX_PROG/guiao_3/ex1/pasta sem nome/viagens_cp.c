//
//  viagens_cp.c
//  ex1
//
//  Created by rsantos on 23/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include "viagens_cp.h"

void mostra_percurso(char* nomefich) {
    Paragem par;
    
    FILE *f = fopen(nomefich,"rb");
    
    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return;
    }
    
    while (fread(&par, sizeof(Paragem), 1, f) == 1)
        printf("%-25s %3d\n", par.nome, par.minutos);
    
    fclose(f);
}

void percurso_completo(char* nomefich) {
    Paragem par;
    int duracao_total = 0;
    
    FILE *f = fopen(nomefich,"rb");
    
    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return;
    }
    
    while (fread(&par, sizeof(Paragem), 1, f) == 1)
        duracao_total += par.minutos;
    
    fclose(f);
}
