//
//  main.c
//  ficha5ex13
//
//  Created by rsantos on 12/11/2019.
//  Copyright © 2019 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int NovaAposta (int num_jogador) {
    printf("É a vez do jogador %d: ", num_jogador);
    int num_escolhido;
    
    do {
        printf("Qual é a sua aposta?");
        scanf("%d", &num_escolhido);
    } while (num_escolhido < 0 && num_escolhido > 500);
    
    return num_escolhido;
}

int Compara (int prim_num, int seg_num) {
    int comparacao;
    
    if(prim_num < seg_num) {
        comparacao = -1;
    } else {
        if (prim_num > seg_num) {
            comparacao = 1;
        } else {
            comparacao = 0;
        }
    }
    
    return comparacao;
}

int main(int argc, const char * argv[]) {
    int num_escolhido = -1;
    int jogador = 1;
    
    //No inicio o programa deve receber um num aleatorio entre 0 e 500
    srand(time(NULL));
    rand();
    int num_aleatorio = rand()%501;
    
    printf("Valor aleatório: %d\n", num_aleatorio);
           
    //Vai perguntando a cada jogador qual a sua aposta
    while (num_escolhido != num_aleatorio) {
        num_escolhido = NovaAposta(jogador);
        int comparacao = Compara(num_escolhido, num_aleatorio);
        
        switch(comparacao) {
            case 1:
                printf("O valor %d esta acima do numero certo.\n\n", num_escolhido);
                break;
            case 0:
                printf("O jogador %d acertou.\n\n", jogador);
                break;
            case -1:
                printf("O valor %d esta abaixo do numero certo.\n\n", num_escolhido);
                break;
            default:
                printf("Erro!\n");
                break;
        }
        
        jogador++; // jogador 1 -> 2;
        
        if (jogador == 3) { // jogador 2 -> 1;
            jogador = 1;
        }
    }
    
     //Termina quando um dos jogadores acertar no número
    
    return 0;
}
