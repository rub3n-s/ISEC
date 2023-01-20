#include "cliente.h"

void trataSig(int i) {
    fprintf(stderr, "\nUtente a sair (interrompido via teclado)\n\n");
    unlink(CLIENT_FIFO_FINAL);
    exit(EXIT_SUCCESS);
}

bool verificaArgs(int argc) {
    if (argc < 2) { // falta introduzir o nome do cliente
        printf("erro a ler argumentos\n");
        return false;
    }
    return true;
}

Cliente setInfoCliente(char nome[], int pid) {
    Cliente c;
    strcpy(c.nome,nome);
    c.cliente_pid = pid;
    c.comunicaPid = 0;
    c.emEspera = false;
    return c;
}

void getInfoCliente(Cliente c) {
    printf("\npid[%d]\nnome[%s]\nsintomas[%s]\n", c.cliente_pid, c.nome, c.sintomas);
}

void setDadosCliente(Cliente *c, Balcao b) {
    char divideStr[2][20];
    int counter = 0, j = 0;
    for (int i = 0; i < strlen(b.resposta); i++) {
        if (b.resposta[i] == '\0' || b.resposta[i] == ' ') {
            divideStr[counter][j] = '\0';   // detetou espaco ou \0,
            counter++;                      // termina a leitura da palavra
            j = 0;                          // e incrementa o num de linhas ( counter )
        } else {    // se nao for espaco ou \0, copia os carateres 1 a 1
            divideStr[counter][j] = b.resposta[i];
            j++;
        }
    }
    divideStr[0][sizeof(divideStr[0])-1] = '\0';
    strcpy(c->especialidade,divideStr[0]);
    c->prioridade = atoi(divideStr[1]);
    c->comunicaPid = b.comunicaMedPID;
}

Cliente trataTeclado(Cliente cliente) {
    fflush(stdin);
    fgets(cliente.sintomas,S,stdin);
    cliente.sintomas[strlen(cliente.sintomas) - 1] = '\0';

    int fd_envioBalcao = open(BALCAO_FIFO, O_WRONLY);
    int size = write(fd_envioBalcao, &cliente, sizeof(cliente));
    if (size < sizeof(cliente)) {
        printf("Erro a enviar os dados para o balcao\n");
    }
    close(fd_envioBalcao);

    return cliente;
}

void comunicaoClienteMedico(Medico medico, Cliente cliente) {
    int fd_recebeMedico; /* resposta do medico */
    int fd_envioMedico; /* resposta do cliente */
    int fd_envioBalcao; /* avisa o balcao do fim da consulta */
    fd_set read_fds;
    struct timeval tv;
    int nfd;

    printf("\nVou comunicar com o Especialista[%d]\n\n", cliente.comunicaPid);

    /* abre o FIFO do medico para escrita */
    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO, cliente.cliente_pid);
    fd_recebeMedico = open(CLIENT_FIFO_FINAL, O_RDWR | O_NONBLOCK);
    if (fd_recebeMedico == -1) {
        fprintf(stderr,"\nO especialista não está a correr\n\n");
        close(fd_recebeMedico);
        unlink(CLIENT_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fd_recebeMedico,&read_fds);

        nfd = select(fd_recebeMedico + 1, &read_fds, NULL, NULL, &tv);

        if (nfd == -1) {
            perror("\n[Utente] Erro no select\n");
            unlink(CLIENT_FIFO_FINAL);
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(0,&read_fds)) {
            fflush(stdin);
            fgets(cliente.respondeMed,RES,stdin);
            if (strlen(cliente.respondeMed)) {
                cliente.respondeMed[strlen(cliente.respondeMed)-1] = '\0';
                printf("\nUtente[%d] a responder [%s]\n\n", cliente.cliente_pid, cliente.respondeMed);

                /* enviar informação para o medico */
                sprintf(MEDICO_FIFO_FINAL,MEDICO_FIFO,cliente.comunicaPid);
                fd_envioMedico = open(MEDICO_FIFO_FINAL, O_WRONLY);
                int size = write(fd_envioMedico, &cliente, sizeof(cliente));
                if (size < sizeof(cliente)) {
                    printf("Erro a enviar os dados para o cliente\n");
                }
                close(fd_envioMedico);

                /* enviar informação para o balcao - informar fim da consulta */
                if (strcmp(cliente.respondeMed, "adeus") == 0 || strcmp(cliente.respondeMed, "sair") == 0) {
                    fd_envioBalcao = open(BALCAO_FIFO, O_WRONLY);
                    int size_2 = write(fd_envioBalcao, &cliente, sizeof(cliente));
                    if (size_2 < sizeof(cliente)) {
                        printf("Erro a enviar os dados para o balcão\n");
                    }
                    close(fd_envioBalcao);
                    printf("\nConversa a terminar...\n\n");
                    unlink(CLIENT_FIFO_FINAL);
                    exit(EXIT_SUCCESS);
                }
            }
        }

        if (FD_ISSET(fd_recebeMedico, &read_fds)) {
            /* receber a resposta do servidor */
            int size_3 = read(fd_recebeMedico, &medico, sizeof(medico));
            if (size_3 == sizeof(medico)) {
                printf("\nEspecialista[%d] -> [%s]\n\n", medico.medico_pid, medico.respondeCli);
            }

            if (strcmp(medico.respondeCli,"adeus") == 0 || strcmp(medico.respondeCli,"sair") == 0) {
                printf("\nEspecialista[%d] solicitou o fim da conversa.\n\nConversa a terminar...\n\n",medico.medico_pid);
                unlink(CLIENT_FIFO_FINAL);
                exit(EXIT_SUCCESS);
            }
        }
    } while(strcmp(cliente.respondeMed,"adeus")!=0 || strcmp(cliente.respondeMed,"sair")!=0 || strcmp(medico.respondeCli,"adeus")!=0 || strcmp(medico.respondeCli,"sair")!=0);

    close(fd_recebeMedico);
    close(fd_envioMedico);
}