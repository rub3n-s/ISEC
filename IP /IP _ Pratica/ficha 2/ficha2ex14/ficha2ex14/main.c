//
//  main.c
//  ficha2ex14
//
//  Created by Rúben Mendes Santos on 28/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int dia, mes, ano;
    
    printf("dd/mm/aa: \n");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    printf("%02d%02d%02d", ano, mes, dia);
    
    return 0;
}
