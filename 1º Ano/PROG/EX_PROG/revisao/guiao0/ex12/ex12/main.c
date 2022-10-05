//
//  main.c
//  ex12
//
//  Created by rsantos on 25/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void espacos(char f[]) {
        int i = 0;
        
        while (f[i] == ' ')
            i++;
        
    for (int i = 0; i < strlen(f); i++) {
        printf("%c", f[i]);
    }
        
//    while(f[i]) {
//        if (f[i] == ' ') {
//            putchar('\n');
//            while(f[i] == ' ')
//                i++;
//        }
//        if (f[i])
//            putchar(f[i]);
//        i++;
//    }

    printf("\n");
}


int main(int argc, const char * argv[]) {
    char frase[] = "   Hoje e   Domingo!";
    
    espacos(frase);
    
    return 0;
}
