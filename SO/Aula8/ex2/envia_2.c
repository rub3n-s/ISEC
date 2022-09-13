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

void fim(int s, siginfo_t *info, void *c) {
    unlink(P_ESQ);
    unlink(P_DIR);
    printf("\nAdeus");
    exit(EXIT_SUCCESS);
}

int main(int argc, char ** argv) {
    struct sigaction sa;
    sa.sa_sigaction = fim;    // 3 parametros
    sa.sa_flags = SA_SIGINFO; // para enviar info
    sigaction(SIGINT,&sa,NULL);

    Mensagem msg;
    msg.pidCliente = getpid();
    printf("\nIntroduza um nome: ");
    scanf("%s", msg.nome);
    do {
        printf("Introduza um valor: ");
        scanf("%d",&msg.val);
        int fd = open(argv[1],O_WRONLY);
        int size = write(fd, &msg, sizeof(msg));
        close(fd);
    } while(1);
    return 0;
}