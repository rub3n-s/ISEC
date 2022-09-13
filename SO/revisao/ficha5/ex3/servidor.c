#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SERVIDOR "server"

void sig_handler(int signum) {
    unlink(SERVIDOR);
    exit(1);
}
int main() {
    char buffer[50];
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    
    if (sigaction(SIGINT,&sa,NULL)==-1) {
        perror("erro a configurar o sinal");
        exit(-1);
    }

    if (mkfifo(SERVIDOR,0666)==-1) {
        perror("pipe");
        exit(1);
    }

    int fd_leitura = open(SERVIDOR, O_RDONLY);
    if (fd_leitura == -1) {
        perror("erro a abrir para leitura");
        unlink(SERVIDOR);
        exit(-1);
    }

    do {
        int size = read(fd_leitura,&buffer,sizeof(buffer));
        if (size < 0) {
            perror("dados incompletos");
            unlink(SERVIDOR);
            exit(-1);
        }
        printf("recebido [%s]\n",buffer);
    } while(strcmp(buffer,"sair")!=0);

    unlink(SERVIDOR);
    close(fd_leitura);
    
    return 0;
}