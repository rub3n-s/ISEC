//
//  main.c
//  guiao_0_ex10
//
//  Created by rsantos on 27/02/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void espacos(char f[]) {
    int i = 0;
    
    while (f[i] == ' ')
        i++;
    
    while(f[i]) {
        if (f[i] == ' ') {
            putchar('\n');
            while(f[i] == ' ')
                i++;
        }
        if (f[i])
            putchar(f[i]);
        i++;
    }
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char frase[] = "   Hoje    e   domingo!";
    
    espacos(frase);
    

    return 0;
}
