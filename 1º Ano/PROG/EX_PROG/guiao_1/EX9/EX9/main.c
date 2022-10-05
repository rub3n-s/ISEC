//
//  main.c
//  EX9
//
//  Created by rsantos on 06/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

void verifica(char *tel, char *c) {
    if (*(tel) == '2') {
        for (int i = 0; i < 9; i++) {
             if (i != 0 && *(tel+i) >= 0 && *(tel+i) <= 9)
                *c = 'V';
        }
    } else
        *c = 'I';
}

int main(int argc, const char * argv[]) {
    char telefone, verificacao;
    
    printf("Número telefone: \n");
    scanf("%c", &telefone);
    
    verifica(&telefone, &verificacao);
    
    printf("\n%c\n\n", verificacao);
    
    return 0;
}
