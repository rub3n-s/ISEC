//
//  main.c
//  ex20
//
//  Created by rsantos on 19/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <locale.h>
//#include <windows.h>

void traduz_mes(char *ptr[][2], char mes[10], int n_lin) {
    int i;
    
    for (int i = 0; i < n_lin; i++) {
        if (stricmp(ptr[i][0], mes) == 0)
            puts(ptr[i][1]);
        break;
    }
}

int main(int argc, const char * argv[]) {
    char *ptr[12][2] = {{"janeiro","january"}, {"fevereiro","february"} ,{"março", "march"}, {"abril", "april"}, {"maio", "may"}, {"junho", "june"}, {"julho", "july"}, {"agosto", "august"}, {"setembro", "septembre"}, {"outubro", "october"}, {"novembro", "november"}, {"dezembro", "december"}};
    char mes[10];
    
    unsigned int cp = 1252;
    
    printf("mês: ");
    SetConsoleCP(cp);
    gets(mes);
    traduz_mes(ptr, mes, 12);
    
    return 0;
}
