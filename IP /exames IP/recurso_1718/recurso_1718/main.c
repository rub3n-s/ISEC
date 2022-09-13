//
//  main.c
//  recurso_1718
//
//  Created by rsantos on 12/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

//-----------------------------
// Exercício 2-a) (incompleto)
//-----------------------------

//int EliminaValor(int v[ ], int tam, int num) {
//    for (int i=1; i<=tam; i++) {
//        if (num==v[i]) {
//            v[i] = 0;
//            tam--;
//        }
//    }
//
//    return tam;
//}
//
//int main(int argc, const char * argv[]) {
//    int v[] = {102,23,51,48,76,120,51,114};
//
//    printf("%d\n", EliminaValor(v, 8, 51));
//
//    for (int i=0; i<8; i++) {
//        printf("%d ", v[i]);
//    }
//    printf("\n");
//
//    return 0;
//}


//-----------------------------
// Exercício 2-b) (incompleto)
//-----------------------------
//int main(int argc, const char * argv[]) {
//    int n, vencedor = 0, contador = 0, rifa;
//
//    printf("Número de rifas: ");
//    scanf("%d", &n);
//
//    int v[n];
//
//    for (int i = 0; i < n; i++) {
//        printf("Rifa nº %d: ", i+1);
//        scanf("%d", &v[i]);
//    }
//
//    printf("Indique a rifa sorteada: ");
//    scanf("%d", &rifa);
//
//    for (int j = 0; j < n; j++) {
//        if (j == rifa-1) {
//            vencedor = v[j];
//        }
//    }
//    printf("O vencedor tem o cartão de cidadão nº %d e comprou um total de %d rifas\n", vencedor, contador);
//
//    return 0;
//}

//-----------------------------
//        Exercício 3
//-----------------------------

#include <string.h>

int quantasPalavras(char frase[], char maior[]) {
    int contador = 1;
    int posicao;
    
    for (int i = 0; i <= strlen(frase); i++) {
        if(frase[i] == ' ') {
            contador++;
        }
    }
    
    return contador;
}

int main(int argc, const char * argv[]) {

    char frase[] = "Como eu gosto de IP";
    char maior[20];
    int n_palavras;
    
    n_palavras = quantasPalavras(frase, maior);
    
    printf("%d palavras\n", n_palavras);
    printf("maior palavra = %s\n", maior);
    
    return 0;
}
