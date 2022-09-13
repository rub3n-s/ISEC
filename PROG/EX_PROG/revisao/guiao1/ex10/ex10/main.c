//
//  main.c
//  ex10
//
//  Created by rsantos on 27/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define N 50

int tres_consecutivos(char *frase) {
    for (int i = 0; i < strlen(frase) - 1; i++) {
        if (*(frase+i) == *(frase+i+1) && *(frase+i+1) == *(frase+i+2)) {
            printf("%c\t%c\t%c\n", *(frase+i), *(frase+i+1), *(frase+i+2));
            return 1;
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    char frase[N];
    
    printf("frase: ");
    gets(frase);
    
    printf("%d\n", tres_consecutivos(frase));
    
    return 0;
}
