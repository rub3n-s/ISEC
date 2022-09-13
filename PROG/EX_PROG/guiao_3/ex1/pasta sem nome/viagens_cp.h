//
//  viagens_cp.h
//  ex1
//
//  Created by rsantos on 23/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#ifndef viagens_cp_h
#define viagens_cp_h

#include <stdio.h>

typedef struct paragem {
    char nome[50];
    int minutos;
} Paragem;

void mostra_percurso(char* nomefich);
void percurso_completo(char* nomefich);

#endif /* viagens_cp_h */
