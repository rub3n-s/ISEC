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
    char nome[10];
    int val;
    pid_t pidCliente;
} Mensagem;

typedef struct {
    char fifo[10];
    int stop;    
} TDADOS;

void *enviaMensagem(void * dados) {
    TDADOS *pdados = (TDADOS *) dados;
    Mensagem msg;
    int fd = open(pdados->fifo, O_RDWR | O_NONBLOCK);
    do {
        int size = read(fd,&msg,sizeof(msg));
        if (size == sizeof(msg)) {
            if (strcmp(pdados->fifo,"p_esq") == 0) {
                printf("\n * Esquerdo * ");
                printf(" NOME - [%s], Valor - [%d]", msg.nome, msg.val);
                fflush(stdout);
            } else {
                printf("\n * Direito * ");
                printf(" NOME - [%s], Valor - [%d]", msg.nome, msg.val);
                fflush(stdout);
            }
        }
    } while(1);    
}

void fim(int s, siginfo_t *info, void *c) {
    unlink(P_ESQ);
    unlink(P_DIR);
    printf("\nAdeus");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = fim;    // 3 parametros
    sa.sa_flags = SA_SIGINFO; // para enviar info
    sigaction(SIGINT,&sa,NULL);

    TDADOS thDados[2];
    thDados[0].stop = 1;
    strcpy(thDados[0].fifo,P_ESQ);

    thDados[1].stop = 1;
    strcpy(thDados[1].fifo,P_DIR);

    if (mkfifo(thDados[0].fifo,0600) == -1) {
        if (errno == EEXIST)
            perror("Fifo já existe");
        perror("Erro a criar o pipe p_esq");
        return -1;
    }

    if (mkfifo(thDados[1].fifo,0600) == -1) {
        if (errno == EEXIST)
            perror("Fifo já existe");
        perror("Erro a criar o pipe p_dir");
        return -1;
    }

    pthread_t th[2];
    if (pthread_create(&th[0],NULL,enviaMensagem,&thDados[0]) == -1) {
        perror("Erro a criar thread");
        return -1;
    }

    if (pthread_create(&th[1],NULL,enviaMensagem,&thDados[1]) == -1) {
        perror("Erro a criar thread");
        return -1;
    }

    if (pthread_join(th[0],NULL) == -1) {
        perror("Erro a fazer join da thread thread");
        return -1;
    }

    if (pthread_join(th[1],NULL) == -1) {
        perror("Erro a fazer join da thread thread");
        return -1;
    }

    return 0;
}