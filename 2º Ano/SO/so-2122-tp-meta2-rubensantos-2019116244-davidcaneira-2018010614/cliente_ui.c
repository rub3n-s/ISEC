#include "cliente.h"

int main(int argc, char ** argv) {
    Cliente cliente;
    Medico medico;
    Balcao balcao;

    int fd_resposta; /* balcao */

    fd_set read_fds;
    struct timeval tv;
    int nfd;

    if(!verificaArgs(argc)) return 0;

    if (signal(SIGINT,trataSig) == SIG_ERR) {
        fprintf(stderr,"\nNão foi possivel configurar o sinal SIGINT\n\n");
        exit(EXIT_FAILURE);
    }

    /* definir os dados do cliente*/
    cliente = setInfoCliente(argv[1],getpid());

    /* cria o FIFO do cliente */
    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO, cliente.cliente_pid);
    if (mkfifo(CLIENT_FIFO_FINAL,0666) == -1) {
        if (errno == EEXIST) {
            fprintf(stderr,"\nErro - Ja existe ou o programa ja esta a correr\n\n");
        }
        return 1;
    }

    /* verifica se o fifo do cliente está aberto no balcao */
    if(open(BALCAO_FIFO, O_RDWR) == -1) {
        fprintf(stderr,"\nO balcão não está a correr\n\n");
        unlink(CLIENT_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    /* abre o FIFO do cliente */
    fd_resposta = open(CLIENT_FIFO_FINAL, O_RDWR);
    if (fd_resposta == -1) {
        fprintf(stderr,"\nErro a abrir FIFO do cliente\n\n");
        close(fd_resposta);
        unlink(CLIENT_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    printf("\nUtente[%d]\n\nInsira os sintomas: \n\n", cliente.cliente_pid);

    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fd_resposta,&read_fds);

        nfd = select(fd_resposta+1, &read_fds, NULL, NULL, &tv);

        if (nfd == -1) {
            perror("\nErro no select\n");
            close(fd_resposta);
            unlink(CLIENT_FIFO_FINAL);
            return EXIT_FAILURE;
        }

        if (FD_ISSET(0,&read_fds))
            cliente = trataTeclado(cliente);

        if (FD_ISSET(fd_resposta, &read_fds)) {
            /* receber a especialidade e prioridade */
            int size = read(fd_resposta, &balcao, sizeof(balcao));
            if (size == sizeof(balcao)) {
                if (balcao.avisa) {
                    printf("\n[%s]\n",balcao.resposta);
                    unlink(CLIENT_FIFO_FINAL);
                    exit(1);
                } else if (balcao.cheioClientes) {
                    printf("\n[CAPACIDADE MÁXIMA ATINGIDA]\n\nOk, a sair...\n\n");
                    close(fd_resposta);
                    unlink(CLIENT_FIFO_FINAL);
                    exit(1);
                } else if (balcao.comunicaMedPID == 0) {   // o balcao envia informação que contem o PID do medico, caso receba
                    printf("\nResposta do balcao [%s]\n\n", balcao.resposta);   // o pid ja esta pronto para comunicar
                    setDadosCliente(&cliente, balcao);                  // e nao altera os dados do cliente
                    printf("Especialidade [%s]\tPrioridade [%d]\n\n", cliente.especialidade, cliente.prioridade);
                } else {
                    cliente.comunicaPid = balcao.comunicaCliPID;
                    comunicaoClienteMedico(medico,cliente);
                    exit(1);    // acabou a conversa, termina o processo
                }
            }
            else
                printf("Sem resposta ou resposta incompreensivel [bytes lides: %d]\n", size);
        }
    } while(strcmp(cliente.sintomas,"sair")!=0);

    close(fd_resposta);
    unlink(CLIENT_FIFO_FINAL);

    return 0;
}