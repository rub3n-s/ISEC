//
//  main.c
//  ex10
//
//  Created by rsantos on 10/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#define LIN 3
#define COL 3

#include <stdio.h>

void cubo(int tab[][3]) {
    int flag = 0;
    
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            flag = (tab[i][j] < 1 || tab[i][j] > 9);
            
            if (flag)
                printf("Valor inválido!");
        }
    }
}
int main(int argc, const char * argv[]) {
    int tab[3][3] = {
        {6, 1, 8},
        {7, 5, 3},
        {2, 9, 4}
    };
    
    return 0;
}
