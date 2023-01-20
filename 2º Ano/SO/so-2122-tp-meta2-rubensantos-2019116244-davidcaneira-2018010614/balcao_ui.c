#include "balcao.h"

int main(int argc, char ** argv) {
    Balcao balcao;
    Cliente cliente;
    Medico medico;

    int nfd;
    fd_set read_fds;
    struct timeval tv;

    inicializa(&balcao);
    getEnvVars(&balcao);
    infoBalcao(balcao);

    Temporizador *temporizador;
    pthread_t *time;

    int count_fila = balcao.freqFila;
    int nTemporizadores = 0, nThreads = 0;

    if (signal(SIGINT,trataSig) == SIG_ERR) {
        perror("\nNão foi possivel configurar o sinal SIGINT\n");
        exit(EXIT_FAILURE);
    }

    if (signal (SIGALRM, trataSigAlrm) == SIG_ERR) {
        perror("\nNão foi possivel configurar o sinal SIGALRM\n");
        exit(EXIT_FAILURE);
    }

    if (mkfifo(BALCAO_FIFO, 0666) == -1) {  /* criar o fifo CLIENTE e fazer as verificações */
        if (errno == EEXIST) {
            printf("Erro - Já existe ou o programa já está a correr\n");
        }
        printf("Erro a abrir fifo\n");
        return 1;
    }

    if (mkfifo(BALCAO_FIFO_MED, 0666) == -1) {  /* criar o fifo MEDICO e fazer as verificações */
        if (errno == EEXIST) {
            printf("Erro - Já existe ou o programa já está a correr\n");
        }
        printf("Erro a abrir fifo\n");
        return 1;
    }

    int fdRecebeCliente = open(BALCAO_FIFO,O_RDWR | O_NONBLOCK);  /* abrir fifo CLIENTE para leitura/escrita e fazer as verificações */
    if (fdRecebeCliente == -1) {
        printf("Erro a abrir o pipe cliente\n");
        return 1;
    }

    int fdRecebeMedico = open(BALCAO_FIFO_MED,O_RDWR | O_NONBLOCK);  /* abrir fifo MEDICO para leitura/escrita e fazer as verificações */
    if (fdRecebeMedico == -1) {
        printf("Erro a abrir o pipe medico\n");
        return 1;
    }

    do {    /* select que fica à escuta de informação vinda de clientes/medicos */
        tv.tv_sec = 1; // segundos (usado como contador para a frequencia da listagem de filas de espera)
        tv.tv_usec = 0; // micro segundos

        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(fdRecebeCliente, &read_fds);
        FD_SET(fdRecebeMedico, &read_fds);

        nfd = select(max(fdRecebeCliente, fdRecebeMedico) + 1, &read_fds, NULL, NULL, &tv);

        if (nfd == -1) {
            perror("\nErro no select\n");
            close(fdRecebeCliente);
            close(fdRecebeMedico);
            unlink(BALCAO_FIFO);
            unlink(BALCAO_FIFO_MED);
            return EXIT_FAILURE;
        }

        /* trata o teclado do programa balcão*/
        if (FD_ISSET(0, &read_fds))
            trataTeclado(&balcao);

        /* controla a entrada e saída de informação com o programa cliente */
        if (FD_ISSET(fdRecebeCliente, &read_fds))
            balcao = pipeCliente(fdRecebeCliente, cliente, balcao);

        /* controla a entrada e saída de informação com o programa médico */
        if (FD_ISSET(fdRecebeMedico, &read_fds)) {
            int medico_pid = 0;
            balcao = pipeMedico(fdRecebeMedico, medico, balcao, &medico_pid);

            /* verifica se o medico tem alguma thread a correr */
            bool temThread = false;
            for (int i = 0; i < balcao.nMedicos; i++)
                if (balcao.medicos[i].thread && balcao.medicos[i].medico_pid == medico_pid)
                    temThread = true;

            if (temThread) {
                //printf("\nA RECOMEÇAR CONTAGEM -> ESPECIALISTA[%d]\n\n",medico_pid);
                /* redefine o valor do temporizador para 20 segundos (recomeça a contagem)
                 * cada medico tem o seu proprio temporizador associado ao PID */
                for (int i = 0; i < nTemporizadores; i++) {
                    if (temporizador[i].pid == medico_pid)
                        temporizador[i].tempo = 20;
                }
                printf("\nRecebido sinal de vida do especialista[%d]\n\n", medico_pid);
            /* se o medico que esta a chegar não tem thread (não está no sistema), então verifica capacidade*/
            } else if (!balcao.cheioMedicos) {
                if (nThreads == 0) {
                    /* alocar memoria para nova estrutura de dados tempo */
                    temporizador = malloc(sizeof(Temporizador));

                    /* definir os dados do novo objeto temporizador */
                    temporizador[nTemporizadores].pid = medico_pid;
                    temporizador[nTemporizadores].tempo = 20;
                    temporizador[nTemporizadores].expirou = false;

                    /* alocar memoria para uma nova thread */
                    time = malloc(sizeof(pthread_t));

                    if (pthread_create(&time[nThreads], NULL, &sinalVida, &temporizador[nTemporizadores]) != 0) {
                        printf("\nErro a criar thread especialista[%d]\n", medico_pid);
                        exit(-1);
                    }

                    /* guardar o indice da thread para ser acedido mais tarde */
                    setThreadMedico(&balcao, medico_pid, &time[nThreads]);

                    /* incrementar os contadores */
                    nThreads++; nTemporizadores++;
                } else if (nThreads > 0) {
                    /* realocar memoria para nova estrutura de dados tempo */
                    temporizador = realloc(temporizador, sizeof(Temporizador) * nTemporizadores + 1);

                    /* definir os dados do novo objeto temporizador */
                    temporizador[nTemporizadores].pid = medico_pid;
                    temporizador[nTemporizadores].tempo = 20;
                    temporizador[nTemporizadores].expirou = false;

                    /* alocar memoria para uma nova thread e chama o temporizador com o pid do medico*/
                    time = realloc(time, sizeof(pthread_t) * nThreads + 1);
                    if (pthread_create(&time[nThreads], NULL, &sinalVida, &temporizador[nTemporizadores]) != 0) {
                        printf("\nErro a criar thread especialista[%d]\n", medico_pid);
                        exit(-1);
                    }

                    /* guardar a thread na estrutura medico para ser acedida mais tarde */
                    setThreadMedico(&balcao, medico_pid, &time[nThreads]);

                    /* incrementar os contadores */
                    nThreads++; nTemporizadores++;
                }
            }
        }

        if (count_fila == 0) {   /* select configurado para operar de 1 em 1 segundo */
            listaFilaEspera(balcao);
            count_fila = balcao.freqFila;    /* repõe o valor para recomeçar a contagem decrescente */
        } else
            count_fila--;

        for (int j = 0; j < nTemporizadores; j++) {
            if (temporizador[j].expirou) {
                printf("\nEspecialista[%d] vai ser retirado por não dar sinal de vida!\n", temporizador[j].pid);
                /* verifica se o medico já esta a comunicar com algum processo cliente */
                for (int i = 0; i < balcao.nMedicos; i++) {
                    if (balcao.medicos[i].medico_pid == temporizador[j].pid){
                        if (balcao.medicos[i].comunicaPid > 0) { /* já está a comunicar */
                            /* remove também o utente que se encontra na consulta */
                            printf("\nA remover o utente [%d]\n",balcao.medicos[i].comunicaPid);
                            kill(balcao.medicos[i].comunicaPid,SIGINT);
                            eliminaUtente(&balcao,balcao.medicos[i].comunicaPid);
                        }
                    }
                }

                /* cancela a thread que estava a correr associada a este especialista*/
                pthread_cancel(delThreadMedico(balcao,temporizador[j].pid));
                /* mata o processo do especialista associado ao temporizador que expirou */
                kill(temporizador[j].pid,SIGINT);
                /* remove o especialista da lista */
                eliminaEspecialista(&balcao,temporizador[j].pid);
                printf("\nA enviar informação ao especialista[%d] que vai ser retirado\n\n", temporizador[j].pid);

                balcao.comunicaCliPID = 0;
                temporizador[j].expirou = false;
                temporizador[j].pid = 0;
                temporizador[j].tempo = 0;

                break;
            }
        }

        /* verifica se os processos dos utentes da lista estão a correr */
        if (balcao.nClientes > 0) {
            for (int i = 0; i < balcao.nClientes; i++)
                if (0 != kill(balcao.clientes[i].cliente_pid, 0))
                    eliminaUtente(&balcao,balcao.clientes[i].cliente_pid);
        }
        /* verifica se os processos dos especialistas da lista estão a correr */
        if (balcao.nMedicos > 0) {
            for (int j = 0; j < balcao.nMedicos; j++) {
                if (0 != kill(balcao.medicos[j].medico_pid, 0)) {
                    for (int k = 0; k < nTemporizadores; k++) {
                        /* procura o temporizador que esta associado ao especialista */
                        if (temporizador[k].pid == balcao.medicos[j].medico_pid) {
                            /* cancela a thread que estava a correr associada a este especialista*/
                            pthread_cancel(delThreadMedico(balcao,temporizador[k].pid));
                        }
                    }
                    /* se estiver em consulta, mata o processo do utente */
                    if (balcao.medicos[j].comunicaPid > 0) {
                        kill(balcao.medicos[j].comunicaPid,SIGINT);
                        eliminaUtente(&balcao,balcao.medicos[j].comunicaPid);
                    }
                    /* remove o especialista */
                    eliminaEspecialista(&balcao,balcao.medicos[j].medico_pid);                
                }
            }
        }
    } while(!balcao.avisa);

    free(time);
    free(temporizador);
    close(fdRecebeCliente);
    close(fdRecebeMedico);
    unlink(BALCAO_FIFO);
    unlink(BALCAO_FIFO_MED);

    return 0;
}