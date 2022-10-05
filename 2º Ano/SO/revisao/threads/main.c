#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>

typedef struct {
    char ficheiro[50];
    int nLinhas;
    int erro;
    pthread_mutex_t *m;
} ContaLinhas;

int leProximaLinha(char ficheiro[]);

void *contaLinhas(void *dados) {
    ContaLinhas *pdados = (ContaLinhas *) dados;
    FILE *fp;
    fp = fopen(pdados->ficheiro,"r");
    if (fp == NULL) {
        pdados->erro = 1;
        perror("Erro a abrir ficheiro.");
        pthread_exit(NULL);
    }
    pthread_mutex_lock(pdados->m);
    do {
        if(leProximaLinha(pdados->ficheiro)==-1) {
            pdados->erro = 1;
            perror("Proxima linha");
            pthread_exit(NULL);
        }
        else if (leProximaLinha(pdados->ficheiro)==0) {
            printf("Ficheiro[%s] -> %d linhas\n",pdados->ficheiro,pdados->nLinhas);
            pthread_exit(NULL);
        }
        else
            pdados->nLinhas++;
    } while(leProximaLinha(pdados->ficheiro)==1);
    pthread_mutex_unlock(pdados->m);
    pthread_exit(NULL);
}

int main(int argc, char ** argv) {
    ContaLinhas cl[argc-1];
    pthread_t t[argc-1];
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);

    for (int i = 1; i < argc; i++) {
        strcpy(cl[i].ficheiro,argv[i]);
        cl[i].nLinhas = 0;
        cl[i].erro = 0;
        cl[i].m = &mutex;

        if (pthread_create(&t[i],NULL,&contaLinhas,&cl[i])!=0) {
            perror("thread");
            exit(-1);
        }

        pthread_join(t[i],NULL);
    }

    while(1) {
        int ativas = 0;
        for (int i = 1; i < argc; i++) {
            // se houver erro numa, cancela as outras
            if (cl[i].erro == 1) {
                for (int i = 1; i < argc; i++)
                    pthread_cancel(t[i]);
                exit(-1);
            }
            // verifica se ainda há threads a correr
            if (pthread_kill(t[i],0))
                ativas++;
        }
        // se não há threads a correr termina o prog.
        if (ativas == 0)
            exit(-1);
    }

    return 0;
}