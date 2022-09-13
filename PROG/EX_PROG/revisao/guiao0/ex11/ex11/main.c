//
//  main.c
//  ex11
//
//  Created by rsantos on 25/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void inverter(char frase[]) {
    int i;
    
    for (i = strlen(frase); i >= 0; i--) {
        printf("%c", frase[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char frase[] = "Hoje e Domingo";
    
    inverter(frase);
    
    return 0;
}
