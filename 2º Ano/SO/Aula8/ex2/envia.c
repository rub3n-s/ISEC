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

#define P_ESQ "p_esq"
#define P_DIR "p_dir"

typedef struct {
    char buffer[200];
    int esq;
    int dir;
    int fd;
} Mensagem;

void *enviaMensagem(void * dados) {
    Mensagem *pdados = (Mensagem *) dados;

    if (pdados->esq == 1)
        pdados->fd = open(P_ESQ,O_WRONLY);
    else if (pdados->dir == 1)
        pdados->fd = open(P_DIR,O_WRONLY);
    int size = write(pdados->fd,&pdados->buffer, sizeof(pdados->buffer));
    if (size < 0) {
        perror("\nerro a enviar p_esq");
    }
    close(pdados->fd);
    
    pthread_exit(NULL);
}

int main() {
    char buffer[10];
    pthread_t t[2];
    Mensagem m[2];
    int fdEnviaEsq, fdEnviaDir;

    printf("Introduza texto: ");
    scanf("%s",buffer);

    fdEnviaEsq = open(P_ESQ, O_WRONLY);
    if (fdEnviaEsq == -1) {
        printf("Erro a abrir o fifo\n");
        return -1;
    }

    fdEnviaDir = open(P_DIR, O_WRONLY);
    if (fdEnviaDir == -1) {
        printf("Erro a abrir o fifo\n");
        return -1;
    }
    
    strcpy(m[0].buffer,buffer);
    m[0].esq = 1;
    m[0].dir = 0;
    m[0].fd = fdEnviaEsq;

    strcpy(m[1].buffer,buffer);
    m[1].esq = 0;
    m[1].dir = 1;
    m[1].fd = fdEnviaDir;

    if (pthread_create(&t[0],NULL,&enviaMensagem,&m[0]) == -1) {
        perror("\nErro a criar thread");
    }

    if (pthread_create(&t[1],NULL,&enviaMensagem,&m[1]) == -1) {
        perror("\nErro a criar thread");
    }

    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);

    return 0;
}