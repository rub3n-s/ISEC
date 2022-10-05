//
//  contactos.h
//  ex6
//
//  Created by rsantos on 16/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#ifndef contactos_h
#define contactos_h

#include <stdio.h>

//alinea a)
typedef struct contactos {
    char nome[100];
    char ntelemovel[10];
} contacto;

int menu();
//contacto obtem_info();
contacto* adiciona_contacto(contacto *tab, int *n); //tab e n passados como ponteiro porque o seu valor vai ser alterado
//se for apenas para visualizar o conteudo dessas variaveis faz-se umn passagem normal
void escreve_todos(contacto a[], int n);
void escreve_info(contacto a);
void verifica_nome(contacto tab[], int n);

#endif /* contactos_h */
