#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERVER_FIFO "Servidor_N"
#define CLIENT_FIFO "Cliente[%d]"

char CLIENT_FIFO_FINAL[100];

typedef struct { 
    char resposta[200];
} Servidor;

typedef struct {
    int pid;
    char resposta[200];
} Cliente;

void trataSig(int signum) {
    printf("A sair via SIGINT\n");
    unlink(CLIENT_FIFO);
    exit(1);
}

int main() {
    Servidor servidor;
    Cliente cliente;

    struct timeval tv;
    fd_set read_fds;


    if (signal(SIGINT,trataSig)==SIG_ERR) {
        perror("SIGINT");
        exit(-1);
    }

    cliente.pid = getpid();

    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,getpid());
    if (mkfifo(CLIENT_FIFO,0666)==-1) {
        perror("Erro FIFO Cliente");
        exit(-1);
    }

    int fdRecebeServer = open(CLIENT_FIFO,O_RDWR);
    if (fdRecebeServer == -1) {
        perror("Erro a abrir CLIENTE para leitura/escrita");
        exit(-1);
    }

    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fdRecebeServer,&read_fds);

        int nfd = select(fdRecebeServer+1,&read_fds,NULL,NULL,&tv);

        if (FD_ISSET(0,&read_fds)) {
            fflush(stdin);
            scanf("%s",cliente.resposta);

            int fdEnvio = open(SERVER_FIFO,O_WRONLY);
            if (fdEnvio == -1) {
                perror("Erro FD SERVER");
            }
            write(fdEnvio,&cliente,sizeof(cliente));
            close(fdEnvio);
        }

        if (FD_ISSET(fdRecebeServer,&read_fds)) {
            fflush(stdout);
            int size = read(fdRecebeServer,&servidor,sizeof(servidor));
            if (size < 0) {
                perror("Erro a receber dados do SERVER");
            }
            printf("Recebido do Servidor -> [%s]\n",servidor.resposta);

            if (strcmp(servidor.resposta,"sair")==0) {
                printf("A sair também...\n");
                unlink(CLIENT_FIFO);
                close(fdRecebeServer);
                exit(1);
            }
        }
    } while(strcmp(cliente.resposta,"sair")!=0);

    unlink(CLIENT_FIFO);
    close(fdRecebeServer);

    return 0;
}