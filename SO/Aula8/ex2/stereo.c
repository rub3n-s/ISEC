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

void trataSig(int i) {
    unlink(P_ESQ);
    unlink(P_DIR);
    exit(EXIT_SUCCESS);
}

int main() {
    Mensagem m;
    int fdRecebeEsq;
    int fdRecebeDir;
    char buffer[200];

    if (signal(SIGINT,trataSig) == SIG_ERR) {
        perror("Erro a configurar o sinal");
        return -1;
    }

    if (mkfifo(P_ESQ,0777) == -1) {
        perror("Erro a criar o pipe p_esq");
        return -1;
    }

    if (mkfifo(P_DIR,0777) == -1) {
        perror("Erro a criar o pipe p_esq");
        return -1;
    }

    fdRecebeEsq = open(P_ESQ,O_RDONLY);
    if (fdRecebeEsq == -1) {
        perror("erro");
        return -1;
    }

    fdRecebeDir = open(P_DIR,O_RDONLY);
    if (fdRecebeDir == -1) {
        perror("erro");
        return -1;
    }

    int size = read(fdRecebeEsq,&m,sizeof(m));
    if (size > 0) {
        if (m.esq == 1)
            printf("Recebido do pipe [P_ESQ] a mensagem [%s]\n",m.buffer);
    } else {
        printf("\nRecebida informação incompleta do pipe [P_ESQ]\n");
    }

    int size_dir = read(fdRecebeDir,&m,sizeof(m));
    if (size_dir > 0) {
        if (m.dir == 1)
            printf("Recebido do pipe [P_DIR] a mensagem [%s]\n",m.buffer);
    } else {
        printf("\nRecebida informação incompleta do pipe [P_DIR]\n");
    }

    unlink(P_ESQ);
    unlink(P_DIR);
    return 0;
}