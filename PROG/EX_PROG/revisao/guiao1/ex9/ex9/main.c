//
//  main.c
//  ex9
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#define N 9

void verifica(char *tel, char *c) {
    for (int i = 0; i < N; i++) {
        if (*tel != '2') {
            *c = 'I';
        } else if (*tel == '2' && *(tel + i) >= '0' && *(tel + i) <= '9'){
            *c = 'V';
        }
    }
}

int main(int argc, const char * argv[]) {
    char tel[N], c;
    
    printf("Telefone: ");
    scanf("%c", tel);
    
    verifica(tel, &c);
    
    printf("%c\n", c);
    
    return 0;
}
