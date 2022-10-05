//
//  main.c
//  ex6
//
//  Created by rsantos on 16/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "contactos.h"

int main(int argc, const char * argv[]) {
    contacto *tab = NULL;
    int total = 0;
    int op;

    do {
        op = menu();
        
        switch(op) {
            case 1:
                tab = adiciona_contacto(tab, &total);
                break;
            case 2:
                
                break;
            case 3:
                escreve_todos(tab, total);
                break;
            case 4:
                verifica_nome(tab, total);
                break;
            case 5:
                
                break;
            case 6:
                printf("Fim do programa\n");
                break;
            default:
                printf("Digitou uma opcao invalida\n");
                break;
        }
    } while(op != 6);
    
    free(tab); //libertar a memória, essencial no final da execução do programa
    return 0;
}
