#include "medico.h"

int main(int argc, char ** argv) {
    Medico medico;
    Cliente cliente;
    Balcao balcao;

    int fd_resposta; /* balcao */

    fd_set read_fds;
    struct timeval tv;
    int nfd;

    if (!verificaArgs(argc)) return 0;

    if (signal(SIGINT, trataSig) == SIG_ERR) {
        fprintf(stderr,"\nNão foi possivel configurar o sinal SIGINT\n\n");
        exit(EXIT_FAILURE);
    }

    /* definir os dados do medico */
    medico = setInfoMedico(argv[1],argv[2],getpid());

    /* cria o FIFO do medico */
    sprintf(MEDICO_FIFO_FINAL, MEDICO_FIFO, medico.medico_pid);
    if (mkfifo(MEDICO_FIFO_FINAL, 0666) == -1) {
        if (errno == EEXIST) {
            fprintf(stderr,"\nErro - Ja existe ou o programa ja esta a correr\n\n");
        }
        return 1;
    }

    /* verifica se o fifo do medico está aberto no balcao */
    if(open(BALCAO_FIFO_MED, O_RDWR) == -1) {
        fprintf(stderr,"\nO balcão não está a correr\n\n");
        unlink(MEDICO_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    /* abre o FIFO do medico */
    fd_resposta = open(MEDICO_FIFO_FINAL, O_RDWR);
    if (fd_resposta == -1) {
        fprintf(stderr,"\nErro a abrir FIFO do medico\n\n");
        unlink(MEDICO_FIFO_FINAL);
        exit(EXIT_FAILURE);
    }

    printf("\nEspecialista[%d] Nome[%s] Especialidade[%s]\n\n",
           medico.medico_pid, medico.nome, medico.especialidade);
    printf("Informe o balcão que vai entrar no sistema: \n\n");

    do {
        tv.tv_sec = 5; tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        FD_SET(fd_resposta,&read_fds);

        nfd = select(fd_resposta+1, &read_fds, NULL, NULL, &tv);

        if (nfd == -1) {
            perror("\nErro no select\n");
            close(fd_resposta);
            unlink(MEDICO_FIFO_FINAL);
            return EXIT_FAILURE;
        }

        if (FD_ISSET(0,&read_fds))
            medico = trataTeclado(medico);

        if (FD_ISSET(fd_resposta, &read_fds)) {
            /* receber a resposta do servidor */
            int size = read(fd_resposta, &balcao, sizeof(balcao));
            if (size == sizeof(balcao)) {
                if (balcao.avisa) {
                    printf("\n[%s]\n",balcao.resposta);
                    unlink(MEDICO_FIFO_FINAL);
                    exit(1);
                } else if (balcao.cheioMedicos) {
                    printf("\n[CAPACIDADE MÁXIMA ATINGIDA]\n\nOk, a sair...\n\n");
                    close(fd_resposta);
                    unlink(MEDICO_FIFO_FINAL);
                    exit(1);
                } else if (balcao.comunicaMedPID > 0) {
                    medico.comunicaPid = balcao.comunicaMedPID;
                    comunicacaoMedicoCliente(medico,cliente);
                }
            }
            else
                printf("Sem resposta ou resposta incompreensivel [bytes lides: %d]\n", size);
        }
    } while(strcmp(medico.medicoEncerrou,"sair")!=0);

    close(fd_resposta);
    unlink(MEDICO_FIFO_FINAL);

    return 0;
}