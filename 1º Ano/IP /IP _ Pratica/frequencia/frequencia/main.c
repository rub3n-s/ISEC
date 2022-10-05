//
//  main.c
//  frequencia
//
//  Created by rsantos on 27/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

int NumSalas(int num_a) {
    int num_s;
    
    num_s = num_a / 50;
    
    return num_s;
}

int main(int argc, const char * argv[]) {
    
    int num_alunos, num_salas, maior_num = -1, a = 0, b = 0;
    
    do {
        printf("Nº de alunos inscritos na UC %d: ", a + 1);
        scanf("%d", &num_alunos);
        
        if (num_alunos > 0) {
            a += 1;
            
            num_salas = NumSalas(num_alunos);
            
            if ((num_salas % 10 != 0) || (num_salas < 1))
                num_salas += 1;
            
            if (num_salas > maior_num) {
                maior_num = num_salas;
                b = a;
            }
                
            
            printf("Número de salas necessário para a UC: %d\n\n", num_salas);
        }
        
        if (num_alunos == 0) {
            printf("\nMaior número de salas por exame: %d\n", maior_num);
            printf("Ocorre na UC %d\n", b);
        }
        
    } while(num_alunos != 0);
    
    return 0;
}
