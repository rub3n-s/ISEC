//
//  main.c
//  exame_1819
//
//  Created by rsantos on 12/01/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

//----------------------------
//  Exercicio 2 - Incompleto
//----------------------------
//const int N = 5;
//const int P = 10;
//
//#include <stdio.h>
//#include <string.h>
//
//int determina_aprovados(float notas[],int pres[],int n_alunos,int min_pres,float aprovados[]) {
//    int total_aprovados = 0;
//    float soma = 0.0, media = 0.0, melhor_nota = 0.0;
//
//
//
//    for (int i = 0; i <= 40; i++) {
//        printf("-");
//    }
//
//    printf("\nLista das notas dos alunos aprovados: \n");
//    for (int i = 1; i <= n_alunos; i++) {
//        if(notas[i] >= 9.5 && pres[i] >= min_pres ) {
//            aprovados[i] = notas[i];
//            total_aprovados++;
//
//            melhor_nota = notas[i];
//
//            printf("Aluno %d -> %f\n", i, aprovados[i]);
//        }
//
//        if (notas[i] > melhor_nota)
//            melhor_nota = notas[i];
//
//        soma += aprovados[i];
//    }
//
//    for (int i = 0; i <= 40; i++) {
//        printf("-");
//    }
//
//    media = soma / total_aprovados;
//
//    printf("\nMédia -> %.2f\n", media);
//    printf("Melhor nota -> %.2f\n", melhor_nota);
//
//    return total_aprovados;
//}
//
//int main(int argc, const char * argv[]) {
//
//    int presencas[N];
//    float nota[N];
//    float aprov[N];
//
//    for (int i = 1; i <= N; i++) {
//        printf("Aluno %d: ", i);
//        do {
//            scanf("%f %d", &nota[i], &presencas[i]);
//        } while(nota[i] < 0 || nota[i] > 20 || presencas[i] < 0);
//    }
//    printf("Total aprovados -> %d\n", determina_aprovados(nota, presencas, N, P, aprov));
//
//
//    return 0;
//}


//----------------------------
//        Exercicio 3
//----------------------------
#include <stdio.h>
#include <string.h>

int trocarCarater(char f[], char p[], char c) {
    int num_s = 0;

    for (int i = 0; i <= strlen(f); i++) {
        if (f[i] == 'c' && f[i+1] == 'h'){
            f[i] = ' ';
            f[i+1] = 'x';
            num_s++;
        }
    }

    return num_s;
}

int main(int argc, const char * argv[]) {

    char frase[] = "Hoje chegou o cheque do chefe para pagar os chazinhos daquele chato";
    char par[] = "ch";
    char carater = 'x';

    puts(frase);

    printf("\nForam efetuadas as seguintes %d substituicoes: \n", trocarCarater(frase, par, carater));

    puts(frase);

    return 0;
}

//const int N = 5;
//const int P = 10;
//
//#include <stdio.h>
//
//int determina_aprovados(float notas[],int pres[],int n_alunos,int min_pres,float aprovados[]) {
//    int contador = 0, total_aprovados = 0;
//    float max = 0, soma = 0;
//
//    for (int i=0; i<n_alunos; i++) {
//        if(notas[i] > 9.5 && pres[i] >= min_pres) {
//            aprovados[i] = notas[i];
//            contador++;
//        }
//    }
//    printf("--------------------------------------\n");
//    printf("Lista das notas dos alunos aprovados:\n");
//    printf("--------------------------------------\n");
//
//    notas[0] = max;
//
//    for (int i=0; i<n_alunos; i++) {
//        if(notas[i] > 9.5 && pres[i] >= min_pres) {
//            printf("Aluno %d: %f\n", i, notas[i]);
//            soma+=notas[i];
//            total_aprovados++;
//        }
//
//        if(notas[i] > max)
//            max = notas[i];
//    }
//
//    printf("Total aprovados: %d\n", total_aprovados);
//    printf("--------------------------------------\n");
//    printf("Melhor nota: %.2f\n", max);
//    printf("Média das notas dos alunos aprovados: %.2f\n", soma/contador);
//
//    return contador;
//}
//
//int main(int argc, const char * argv[]) {
//    float notas[N];
//    int pres[N];
//    float aprovados[N];
//
//    for (int i = 0; i < N; i++) {
//        printf("Aluno %d -> ", i+1);
//        do  {
//            scanf("%f %d", &notas[i], &pres[i]);
//        } while(notas[i] < 0 || notas[i] > 20);
//    }
//
//    determina_aprovados(notas, pres, N, P, aprovados);
//
//    return 0;
//}
