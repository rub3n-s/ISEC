//
//  main.c
//  ficha2ex10
//
//  Created by Rúben Mendes Santos on 17/10/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int segundosEnt;
    int horas,minutos,segundos;
    int restoSeconds;

    printf("Segundos: ");
    scanf("%d",&segundosEnt);
 
    horas = (segundosEnt/3600);

    restoSeconds = segundosEnt - (horas * 3600);
    minutos = restoSeconds/60;

    restoSeconds = restoSeconds - (minutos * 60);
    segundos = restoSeconds;
    
    printf("%d hora, %d minutos e %d segundos\n", horas, minutos, segundos);
    
    return 0;
}
