#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define SERVER_FIFO "SERVIDOR2"
#define CLIENT_FIFO "CLIENTE[%d]" // cliente[123]
char CLIENT_FIFO_FINAL[100];    // cliente[123] -> nome do cliente fifo fica nesta variavel global

typedef struct { /* mensagem que recebe */
    pid_t pid;
    int num1;
    int num2;
    char operador;
} pedido;

typedef struct {    /* mensagem com a resposta */
    int pid;
    double resultado;
} resposta;

void trataSig(int i) {
    fprintf(stderr, "\nServidor balcao a terminar (interrompido via teclado)\n\n");
    unlink(CLIENT_FIFO_FINAL);
    exit(EXIT_SUCCESS);
}

int main() {
    /* alinea d) fazer programa correr em background */
    /*
    int id = fork();
    if (id > 0) // processo pai
        exit(1);
    //significa que o filho vai ficar a correr e duplica o processo
    */
    pedido mensagem;
    resposta msgResposta;
    fd_set read_fds;
    struct timeval tv;

    if (signal(SIGINT,trataSig) == SIG_ERR) {
        perror("\nNão foi possivel configurar o sinal SIGINT\n");
        exit(EXIT_FAILURE);
    }

    mensagem.pid = getpid();
    int fd_envio, fd_resposta;

    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO, getpid());
    if (mkfifo(CLIENT_FIFO_FINAL,0666) == -1) {
        if (errno == EEXIST) {
            printf("erro - ja existe ou o programa ja esta a correr\n");
        }
        printf("Erro a abrir fifo");
        return 1;
    }

    fd_resposta = open(CLIENT_FIFO_FINAL, O_RDWR);

    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fd_resposta,&read_fds);

        int nfd = select(fd_resposta+1, &read_fds, NULL, NULL, &tv);

        if (FD_ISSET(0,&read_fds)) {
            printf("num1 '+' num2: ");
            scanf("%d %c %d", &mensagem.num1, &mensagem.operador, &mensagem.num2);

            if (mensagem.operador == '.') { // termina o programa
                fd_envio = open(SERVER_FIFO, O_WRONLY);
                int size = write(fd_envio, &mensagem, sizeof(mensagem));
                close(fd_envio);
                unlink(CLIENT_FIFO_FINAL);
                exit(1);
            }

            fd_envio = open(SERVER_FIFO, O_WRONLY);
            int size = write(fd_envio, &mensagem, sizeof(mensagem));
            if (size < sizeof(mensagem)) {
                printf("Erro a enviar os dados para o servidor\n");
            }
            close(fd_envio);
        }

        if (FD_ISSET(fd_resposta, &read_fds)) { /* receber o calculo e o PID */
            int size = read(fd_resposta, &msgResposta, sizeof(msgResposta));
            if (size > 0) {
                printf("\nResultado do calculo - [%f] do cliente [%d]\n",msgResposta.resultado,msgResposta.pid);
            }
        }
    } while(1);
    close(fd_resposta);
    unlink(CLIENT_FIFO_FINAL);
    return 0;
}