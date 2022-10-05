//
//  contactos.c
//  ex6
//
//  Created by rsantos on 16/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include "contactos.h"
#include <stdlib.h>
#include <string.h>

contacto obtem_info() {
    contacto t;
    
    printf("Nome: ");
    scanf("%s", t.nome);
    printf("Nº Telemóvel: ");
    scanf("%s", t.ntelemovel);
    printf("\n");
    
    return t;
}

int menu() {
    int op;
    
    printf("Introduza o numero da opção pretendida\n");
    printf("1 - Adicionar Contacto\n");
    printf("2 - Eliminar Contacto\n");
    printf("3 - Listar Contacto\n");
    printf("4 - Verifica Nome\n");
    printf("5 - \n");
    printf("6 - Terminar\n");
    printf("Opção: ");
    scanf("%d", &op);
    printf("\n");
    
    return op;
}

contacto* adiciona_contacto(contacto *tab, int* n) {
    contacto *aux;
    int i, existe_contacto = 0;
    
    if (*n == 0) {
        tab = malloc(sizeof(contacto));
        
        if(tab == NULL) {
            printf("Erro na alocação!");
            return 0;
        }
        tab[*n] = obtem_info();
        
        (*n)++;
    } else {
        aux = realloc(tab, sizeof(contacto) * (*n+1));
        if (aux != NULL)
            tab = aux;
        
        do { //este 'do'  serve apenas para verificar se o contacto já existe
            existe_contacto = 0;
            tab[*n] = obtem_info();
            for (i = 0; i < *n && strcmp(tab[*n].nome, tab[i].nome) != 0; i++);
            
            if (i < *n) {
                printf("Contacto já existe\n");
                existe_contacto = 1;
            }
        } while(existe_contacto);
        
        (*n)++;
    }
    
    return tab;
}

void escreve_todos(contacto tab[], int n) {
    for (int i = 0; i < n; i++)
        escreve_info(tab[i]);
}

void escreve_info(contacto a) {
    printf("Nome: %s\nNº Telemóvel: %s\n\n", a.nome, a.ntelemovel);
}

void verifica_nome(contacto tab[], int n) {
    char nome[10];
    
    printf("Insira o nome da pessoa: ");
    scanf("%s", nome);
    
    for (int i = 0; i < n; i++) {
        if (strcmp(nome, tab[i].nome))
            printf("Nº Telemovel: %s", tab[i].ntelemovel);
    }
}
