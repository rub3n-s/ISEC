#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
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

void hanlder_sigalrm(int s, siginfo_t *i, void *v) {
    unlink(SERVER_FIFO);
}

void trataSig(int i) {
    fprintf(stderr, "\nServidor balcao a terminar (interrompido via teclado)\n\n");
    unlink(SERVER_FIFO);
    exit(EXIT_SUCCESS);
}

void leTeclado() {
    char buffer[100];
    scanf("%s", buffer);
    printf("\nLido do teclado [%s]\n", buffer);
    if (strcmp(buffer,"encerra")==0) {
        unlink(SERVER_FIFO);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    resposta msgResposta;
    pedido msgRecebida;
    fd_set read_fds;
    struct timeval tv;

    int listaClientes[5];
    for (int i = 0; i < 5; i++)
        listaClientes[i] = '\0';
    
    // testar em linux -> mac nao tem sigalrm
    /*struct sigaction sa;
    sa.sa_sigaction = hanlder_sigalrm;
    sa.sa_flags =SA_RESTART|SA_SIGINFO;
    sigaction(SIGINT,&sa,NULL); */

    if (signal(SIGINT,trataSig) == SIG_ERR) {
        perror("\nNão foi possivel configurar o sinal SIGINT\n");
        exit(EXIT_FAILURE);
    }

    if (mkfifo(SERVER_FIFO, 0666) == -1) {  /* 1) criar o fifo e fazer as verificações */
        if (errno == EEXIST) {
            printf("Erro -> Já existe ou o programa ja esta a correr\n");
        }
        printf("Erro a abrir fifo\n");
        return 1;
    }
    
    int fdRecebe = open(SERVER_FIFO,O_RDWR);  /* 2) abrir para leitura e fazer as verificações */
    if (fdRecebe == -1) {
        printf("Erro a abrir o pipe para leitura\n");
        return 1;
    }

    do {    /* 3) ler e verificar se o numero de bytes lidos é > 0  (de vários clientes / le vários pipes)*/
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fdRecebe,&read_fds);

        int nfd = select(fdRecebe+1, &read_fds, NULL, NULL, &tv);

        if (FD_ISSET(0,&read_fds))
            leTeclado();

        if(FD_ISSET(fdRecebe, &read_fds)) {
            int size = read(fdRecebe, &msgRecebida, sizeof(msgRecebida));   
            if (size > 0) {
                if (msgRecebida.operador == '+')
                    msgResposta.resultado = msgRecebida.num1 + msgRecebida.num2;
                else if (msgRecebida.operador == '.') {
                    kill(getpid(),SIGINT);
                    unlink(SERVER_FIFO);
                    exit(1);
                }
                
                printf("\nRecebido do cliente [%d %c %d]\n", msgRecebida.num1, msgRecebida.operador, msgRecebida.num2);
                printf("Resposta[%.1f]\n", msgResposta.resultado);

                //guardar o pid do cliente
                for (int i = 0; i < 5; i++) {
                    if (listaClientes[i] == '\0') {
                        listaClientes[i] = msgRecebida.pid;
                        //msgResposta.pid = listaClientes[i];
                        printf("listaClientes[%d] = %d\n", i, msgRecebida.pid);
                        break;
                    } else if (listaClientes[i] == msgRecebida.pid)
                        break;
                }
                printf("\n");
                
                /* responder ao meu cliente */
                int i = 0;
                while(listaClientes[i] != '\0') {
                    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,listaClientes[i]);
                    msgResposta.pid = msgRecebida.pid;
                    printf("A enviar ao %s = %.1f\n", CLIENT_FIFO_FINAL, msgResposta.resultado);
                    int fdEnvio = open(CLIENT_FIFO_FINAL,O_WRONLY);
                    int size = write(fdEnvio, &msgResposta, sizeof(msgResposta));
                    close (fdEnvio);
                    i++;
                }
                
            }
        }
    } while(1);

    unlink(SERVER_FIFO);
    return 0;
}