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
    pthread_mutex_t *m;
} TDADOS;


// OBJETIVO: IMPRIMIR NO ECRA 2 VEZES OLA EM THREADS DIFERENTES
void *imprime(void *dados) {
    TDADOS *pdados = (TDADOS *)dados;
    pthread_mutex_lock(pdados->m);
    for (int i = 1; i < 11; i++) {
        printf("\nthread[%c] - contador[%d]", pdados->ident, i);
        fflush(stdout);
        sleep(3);
    }
    pthread_mutex_unlock(pdados->m);
}

int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    TDADOS val[2];
    val[0].ident = 'A';
    val[0].m = &mutex;
    val[0].stop = 1;
    val[1].ident = 'B';
    val[1].stop = 1;
    val[0].m = &mutex;
    pthread_t t[2]; // ou pthread_t tA, tB;

    if (pthread_create(&t[0],NULL,&imprime,&val[0])!=0) { // 4º parametro permite enviar uma estrutura para a função imprime
        printf("\nErro ao criar a thread A");
        exit(-1);
    }

    if (pthread_create(&t[1],NULL,&imprime,&val[1])!=0) { // 4º parametro permite enviar uma estrutura para a função imprime
        printf("\nErro ao criar a thread B");
        exit(-1);
    }

    //inicio da zona critica
    pthread_mutex_lock(&mutex);
    printf("\n [MAIN] - Ola \n");
    for (int i = 1; i < 11; i++) {
        printf("\n[MAIN] - contador[%d]", i);
        fflush(stdout);
        sleep(3);
    }
    pthread_mutex_unlock(&mutex);
    //fim da zona critica

    // usado para aguardar que as threads termine antes do programa terminar
    pthread_join(t[0],NULL);    // espera pelo fim da thread A
    pthread_join(t[1],NULL);    // espera pelo fim da thread B
    
    return 0;
}