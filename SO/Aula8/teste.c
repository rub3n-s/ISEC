#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    char ident;
    int stop;
} TDADOS;


// OBJETIVO: IMPRIMIR NO ECRA 2 VEZES OLA EM THREADS DIFERENTES
void *imprime(void *dados) {
    TDADOS *pdados = (TDADOS *)dados;
    do {
        printf("\nThread [%c] - Olá esta e a minha primeira thread", pdados->ident);
        fflush(stdout); // importante para que o output seja seguido
    } while(pdados->stop == 1);
    sleep(10);
    pthread_exit(NULL);
}

int main() {
    TDADOS val[2];
    val[0].ident = 'A';
    val[1].ident = 'B';
    val[0].stop = 1;
    val[1].stop = 1;
    pthread_t t[2]; // ou pthread_t tA, tB;
    
    if (pthread_create(&t[0],NULL,&imprime,&val[0])!=0) { // 4º parametro permite enviar uma estrutura para a função imprime
        printf("Erro ao criar a thread A");
        exit(-1);
    }

    if (pthread_create(&t[1],NULL,&imprime,&val[0])!=0) { // 4º parametro permite enviar uma estrutura para a função imprime
        printf("Erro ao criar a thread B");
        exit(-1);
    }

    char buffer[10];
    do {
        printf("Para sair introduza a palavra 'fim'");
        fflush(stdout);
        scanf("%s",buffer);
        if (strcmp(buffer,"fim")==0) {
            // vou terminar as threads
            val[0].stop = 0;
            val[1].stop = 0;
        } else {
            printf("\ncomando invalido");
        }
    } while(strcmp(buffer,"fim")!=0);

    // usado para aguardar que as threads termine antes do programa terminar
    pthread_join(t[0],NULL);    // espera pelo fim da thread A
    pthread_join(t[1],NULL);    // espera pelo fim da thread B
    
    return 0;
}