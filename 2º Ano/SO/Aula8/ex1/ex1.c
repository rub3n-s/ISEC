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
#include <time.h>

typedef struct {
    char ident;
    pthread_mutex_t *m;
} TDADOS;

void *imprime(void *dados) {
    TDADOS *pdados = (TDADOS *)dados;
    
    pthread_mutex_lock(pdados->m);

    srand(time(NULL));
    int random = rand()%(5+1);

    for (int i = 0; i < random; i++) {
        printf("\nthread[.]");
        fflush(stdout);
        sleep(1);
    }

    pthread_mutex_unlock(pdados->m);

    for (int i = 0; i < 3; i++) {
        printf("\nthread[%c]", pdados->ident);
        fflush(stdout);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    TDADOS val[2];
    pthread_t t[2];
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);

    val[0].ident = 'A';
    val[0].m = &mutex;
    val[1].ident = 'B';
    val[1].m = &mutex;

    if (pthread_create(&t[0],NULL,&imprime,&val[0])!=0) {
        printf("erro - thread A");
        exit(-1);
    }

    if (pthread_create(&t[1],NULL,&imprime,&val[1])!=0) {
        printf("erro - thread B");
        exit(-1);
    }
 
    // usado para aguardar que as threads termine antes do programa terminar
    pthread_join(t[0],NULL);    // espera pelo fim da thread A
    pthread_join(t[1],NULL);    // espera pelo fim da thread B
}