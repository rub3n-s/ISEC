#include "medico.h"

void trataSig(int i) {
    fprintf(stderr, "\nEspecialista a sair (interrompido via SIGINT)\n\n");
    unlink(MEDICO_FIFO_FINAL);
    exit(EXIT_SUCCESS);
}

bool verificaArgs(int argc) {
    if (argc < 3) {
        printf("Erro a ler argumentos\n");
        return false;
    }
    return true;
}

Medico setInfoMedico(char nome[], char especialidade[], int pid) {
    Medico m;
    m.medico_pid = pid;
    strcpy(m.nome,nome);
    strcpy(m.especialidade,especialidade);
    m.comunicaPid = 0;
    m.thread = false;
    m.sinalVida = false;
    return m;
}

void getInfoMedico(Medico m) {
    printf("nome: %s\nespecialidade: %s\n", m.nome, m.especialidade);
}

Medico trataTeclado(Medico medico) {
    char buffer[200];
    fflush(stdin);
    scanf("%s", buffer);
    if (strcmp(buffer,"sair") == 0) { // envia msg ao balcao a informar que vai sair
        strcpy(medico.medicoEncerrou,"sair");
        printf("\nA sair...\n\n");
    }

    int fd_envioBalcao = open(BALCAO_FIFO_MED, O_WRONLY);
    int size = write(fd_envioBalcao, &medico, sizeof(medico));
    if (size < sizeof(medico)) {
        printf("Erro a enviar os dados para o balcão\n");
    }
    close(fd_envioBalcao);

    return medico;
}

void comunicacaoMedicoCliente(Medico medico, Cliente cliente) {
    int fd_recebeCliente; /* resposta do cliente */
    int fd_envioCliente; /* resposta do cliente */
    int fd_envioBalcao; /* avisa o balcao do fim da consulta */
    fd_set read_fds;
    struct timeval tv;
    int nfd;

    /* abre o FIFO do medico para escrita */
    sprintf(MEDICO_FIFO_FINAL,MEDICO_FIFO, medico.medico_pid);
    fd_recebeCliente = open(MEDICO_FIFO_FINAL, O_RDWR | O_NONBLOCK);
    if (fd_recebeCliente == -1) {
        fprintf(stderr,"\nO especialista não está a correr\n\n");
        close(fd_recebeCliente);
        unlink(MEDICO_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    printf("\nVou comunicar com o Utente[%d]\n\n", medico.comunicaPid);

    do {
        medico.sinalVida = false;
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fd_recebeCliente, &read_fds); /* falta abrir para leitura */

        nfd = select(fd_recebeCliente + 1, &read_fds, NULL, NULL, &tv);

        if (nfd == -1) {
            perror("\n[Especialista] Erro no select\n");
            unlink(MEDICO_FIFO_FINAL);
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(0,&read_fds)) {
            fflush(stdin);
            fgets(medico.respondeCli,RES,stdin);
            if (strlen(medico.respondeCli) > 0) {
                medico.respondeCli[strlen(medico.respondeCli)-1] = '\0';
                printf("\nEspecialista[%d] a responder [%s]\n\n", medico.medico_pid, medico.respondeCli);

                /* enviar informação para o cliente */
                sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,medico.comunicaPid);
                fd_envioCliente = open(CLIENT_FIFO_FINAL, O_WRONLY);
                int size = write(fd_envioCliente, &medico, sizeof(medico));
                if (size < sizeof(medico))
                    printf("Erro a enviar os dados para o cliente\n");
                close(fd_envioCliente);

                /* enviar informação para o balcao - informar fim da consulta */
                if (strcmp(medico.respondeCli, "adeus") == 0 || strcmp(medico.respondeCli, "sair") == 0) {
                    fd_envioBalcao = open(BALCAO_FIFO_MED, O_WRONLY);
                    int size_2 = write(fd_envioBalcao, &medico, sizeof(medico));
                    if (size_2 < sizeof(medico)) {
                        printf("Erro a enviar os dados para o balcão\n");
                    }
                    close(fd_envioBalcao);
                    printf("\nConversa a terminar...\n\n");
                    if (strcmp(medico.respondeCli, "sair") == 0)
                        exit(EXIT_SUCCESS);
                    break;
                } else {
                    /* envia o sinal de vida ao balcão */
                    medico.sinalVida = true;
                    fd_envioBalcao = open(BALCAO_FIFO_MED, O_WRONLY);
                    int size_2 = write(fd_envioBalcao, &medico, sizeof(medico));
                    if (size_2 < sizeof(medico)) {
                        printf("Erro a enviar os dados para o balcão\n");
                    }
                    close(fd_envioBalcao);
                }
            }
        }

        if (FD_ISSET(fd_recebeCliente, &read_fds)) {
            /* receber a resposta do servidor */
            int size_3 = read(fd_recebeCliente, &cliente, sizeof(cliente));
            if (size_3 == sizeof(cliente))
                printf("\nUtente[%d] -> [%s]\n\n", cliente.cliente_pid, cliente.respondeMed);

            /* utente solicitou o fim da consulta */
            if (strcmp(cliente.respondeMed,"adeus") == 0 || strcmp(cliente.respondeMed,"sair") == 0) {
                printf("\nUtente[%d] solicitou o fim da conversa.\n\nConversa a terminar...\n\n",cliente.cliente_pid);
                medico.comunicaPid = 0; /* repõe o pid de comunicação a zero, para se desassociar ao cliente com que estava a comunicar */
                break;
            }
        }
    } while(strcmp(cliente.respondeMed,"adeus") != 0 || strcmp(cliente.respondeMed,"sair") != 0);

    close(fd_recebeCliente);
    close(fd_envioCliente);
}