#include "balcao.h"

/*============== Comunicação Balcão-Cliente ==============*/

int max(int a, int b) {
    return (a > b) ? a : b;
}

void trataSig(int i) {
    fprintf(stderr, "\nServidor balcao a terminar (interrompido via teclado)\n\n");
    unlink(BALCAO_FIFO);
    unlink(BALCAO_FIFO_MED);
    exit(EXIT_SUCCESS);
}

void trataSigAlrm(int i) {
    printf("\nPassaram [%d] segundos.\n\n", i);
}

bool verificaCmd(char *str) {
    int cmd_size =  sizeof(cmd) / sizeof(cmd[0]);   // tamanho do array cmd
    for (int i = 0; i < cmd_size; i++) {
        if(strcmp(str, cmd[i])==0)
            return true;
    }
    return false;
}

void listaCmd() {
    int cmd_size =  sizeof(cmd) / sizeof(cmd[0]);   // tamanho do array cmd
    printf("\nLista de comandos:\n");
    for (int i = 0; i < cmd_size; i++)
        printf("%s\n", cmd[i]);
    printf("\n");
}

void trataTeclado(Balcao *b) {
    char cmd[cmd_len];
    char cmd_ret[cmd_len];
    int pid_ret;

    fflush(stdin);
    memset(&cmd[0], 0, sizeof(cmd));
    memset(&cmd_ret[0], 0, sizeof(cmd_ret));
    fgets(cmd,cmd_len,stdin);
    if ((strlen(cmd) > 0) && (cmd[strlen(cmd)-1] == '\n'))
        cmd[strlen(cmd)-1] = '\0';

    if ((strcmp(cmd,"utentes")==0 || strcmp(cmd,"especialistas")==0 || strcmp(cmd,"encerra")==0) && verificaCmd(cmd)) {
        executaCmd(b,cmd,pid_ret);
    } else {
        divideComando(cmd, cmd_ret, &pid_ret);
        if (verificaCmd(cmd_ret))
            executaCmd(b,cmd_ret,pid_ret);
        else
            printf("\ncomando invalido\n\n");
    }
}

void informaTodos(Balcao b) {
    b.avisa = true;
    strcpy(b.resposta,"Balcao a fechar...");
    for (int i = 0; i < b.nClientes; i++) {
        sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,b.clientes[i].cliente_pid);
        int fd_aviso_ut = open(CLIENT_FIFO_FINAL, O_WRONLY);
        if (fd_aviso_ut==-1)
            fprintf(stderr,"\nErro a informar os clientes\n\n");
        write(fd_aviso_ut,&b,sizeof(b));
        close(fd_aviso_ut);
    }
    for (int i = 0; i < b.nMedicos; i++) {
        sprintf(MEDICO_FIFO_FINAL,MEDICO_FIFO,b.medicos[i].medico_pid);
        int fd_aviso_esp = open(MEDICO_FIFO_FINAL, O_WRONLY);
        if (fd_aviso_esp==-1)
            fprintf(stderr,"\nErro a informar os especialistas\n\n");
        write(fd_aviso_esp,&b,sizeof(b));
        close(fd_aviso_esp);
    }
    unlink(BALCAO_FIFO);
    unlink(BALCAO_FIFO_MED);
    unlink(CLIENT_FIFO);
    unlink(MEDICO_FIFO);
    exit(EXIT_SUCCESS);
}

void divideComando(char cmd[], char *cmd_ret, int *pid_ret) {
    char divideStr[2][20];
    int counter = 0, j = 0;
    for (int i = 0; i < strlen(cmd); i++) {
        if (cmd[i] == '\0' || cmd[i] == ' ') {
            divideStr[counter][j] = '\0';   // detetou espaco ou \0,
            counter++;                      // termina a leitura da palavra
            j = 0;                          // e incrementa o num de linhas ( counter )
        } else {    // se nao for espaco ou \0, copia os carateres 1 a 1
            divideStr[counter][j] = cmd[i];
            j++;
        }
    }
    char *aux = malloc(sizeof(*aux) * strlen(divideStr[0]));
    strcpy(aux,divideStr[0]);
    strcpy(cmd_ret,aux);
    *pid_ret = atoi(divideStr[1]);
    free(aux);
}

void executaCmd(Balcao *b,char cmd[],int pid) {
    // passa pela func verificar, se for true executa
    if (strcmp(cmd,"utentes")==0)
        listaUtentes(b);
    else if (strcmp(cmd,"especialistas")==0)
        listaEspecialistas(b);
    else if (strcmp(cmd,"delut")==0)
        eliminaUtente(b,pid);
    else if (strcmp(cmd,"delesp")==0)
        eliminaEspecialista(b,pid);
    else if (strcmp(cmd,"freq")==0)
        setFreqFila(b,pid);
    else if (strcmp(cmd,"encerra") == 0)
        informaTodos(*b);
}

void inicializa(Balcao *b) {
    b->nClientes = 0;
    b->nMedicos = 0;
    b->MAXCLIENTES = 0;
    b->MAXMEDICOS = 0;
    b->comunicaMedPID = 0;
    b->comunicaCliPID = 0;
    b->freqFila = 30; // 30 segundos
    b->filaGeral = 0;
    b->filaEstomatologia = 0;
    b->filaOftalmologia = 0;
    b->filaOrtopedia = 0;
    b->filaNeurologia = 0;
    b->cheioClientes = false;
    b->cheioMedicos = false;
    b->avisa = false;
}

int getEnvVars(Balcao *balcao) {
    int maxClientes, maxMedicos;

    if (!getenv(EV_MAXMEDICOS)) {
        printf("\nVariável de ambiente MAXMEDICOS não inicializada.\n");
        return -1;
    } else if (!getenv(EV_MAXCLIENTES)) {
        printf("\nVariável de ambiente MAXCLIENTES não inicializada.\n");
        return -1;
    }
    maxClientes = atoi(getenv(EV_MAXCLIENTES));
    maxMedicos = atoi(getenv(EV_MAXMEDICOS));
    if (maxClientes < 0 || maxMedicos < 0) {
        printf("Variáveis ambiente não podem ter valores menores que zero\n");
        return -1;
    }
    balcao->MAXCLIENTES = maxClientes;
    balcao->MAXMEDICOS = maxMedicos;
    return 0;
}

void infoBalcao(Balcao b) {
    printf("\nMAXCLIENTES [%d]\tMAXMEDICOS [%d]\n\n", b.MAXCLIENTES, b.MAXMEDICOS);
}

char* enviaClassificador(char string[]) {
    char readbuffer[50];
    int b2c[2], c2b[2];
    int nbytes;

    pipe(b2c); pipe(c2b);

    if(pipe(b2c)==-1){
        perror("Erro a abrir o pipe b2c");
        return "Erro a abrir o pipe balcao > classificador\n";
    }

    if(pipe(c2b)==-1){
        perror("Erro a abrir o pipe c2b");
        return "Erro a abrir o pipe classificador > balcao\n";
    }

    int id = fork();
    switch(id) {
        case -1:
            perror("Fork");
            return "Erro a abrir o fork";

        case 0: // filho
            close(b2c[1]);  // fecha escrita - abre leitura
            dup2(b2c[0], STDIN_FILENO);
            close(b2c[0]);

            close(c2b[0]);  // fecha leitura - abre escrita
            dup2(c2b[1], STDOUT_FILENO);
            close(c2b[1]);

            execl("./classificador_mac","classificador_mac",NULL);
            //execl("./classificador","classificador",NULL); /* linux 64 */
            perror("execl classificador");
            exit(1);

        default: //pai
            close(b2c[0]);
            write(b2c[1], string, strlen(string));

            close(c2b[1]);
            nbytes = read(c2b[0], readbuffer, sizeof(readbuffer));

            if (nbytes == -1) {
                perror("Read error");
            } else {
                readbuffer[nbytes-1] = '\0';
                printf("\nClassificador a enviar [%s], com [%d bytes]\n", readbuffer, nbytes);
                char *aux = malloc(sizeof (char) * nbytes);
                if (!aux)
                    printf("Erro a alocar a memoria\n");
                strcpy(aux, readbuffer);
                return aux;
            }
    }
    close(b2c[1]);
    close(c2b[0]);
    return "Erro\n";
}

void setCliente(Balcao *b, Cliente c) {
    if (b->nClientes == 0) {
        b->clientes = malloc(sizeof(Cliente));
        if (b->clientes == NULL)
            printf("Erro a alocar memoria\n");
        b->clientes[b->nClientes] = c;
        (b->nClientes)++;
        printf("\nNovo utente adicionado com sucesso\n\n");
    } else {
        for (int i = 0; i < b->nClientes; i++) {
            if (b->clientes[i].cliente_pid == c.cliente_pid) {
                strcpy(b->clientes[i].sintomas,c.sintomas);
                strcpy(b->clientes[i].especialidade,c.especialidade);
                b->clientes[i].prioridade = c.prioridade;
                return;
            }
        }
        b->clientes = realloc(b->clientes,sizeof(Cliente) * b->nClientes);
        b->clientes[b->nClientes] = c;
        (b->nClientes)++;
        printf("\nNovo utente adicionado com sucesso\n\n");
    }
}

void setMedico(Balcao *b, Medico m) {
    if (b->nMedicos == 0) {
        b->medicos = malloc(sizeof(Medico));
        if (b->medicos == NULL)
            printf("Erro a alocar memoria\n");
        b->medicos[b->nMedicos] = m;
        (b->nMedicos)++;
        printf("\nNovo especialista para a especialidade [%s]\n\n", m.especialidade);
    } else {
        bool flg = false;
        for (int i = 0; i < b->nMedicos; i++)
            if (m.medico_pid == b->medicos[i].medico_pid)
                flg = true;
        if (!flg) {
            b->medicos = realloc(b->medicos,sizeof(Medico) * b->nMedicos);
            b->medicos[b->nMedicos] = m;
            (b->nMedicos)++;
            printf("\nNovo especialista para a especialidade [%s]\n\n", m.especialidade);
        }
    }
}

void eliminaUtente(Balcao *b, int pid) {
    bool flg = false;
    if (b->nClientes > 0) {
        for (int i = 0; i < b->nClientes; i++)
            if (b->clientes[i].cliente_pid == pid)
                flg = true;
        if (flg) {
            if (b->nClientes == 1) {
                b->nClientes = 0;
                free(b->clientes);
            } else {
                int pos = -1;
                for (int i = 0; i < b->nClientes; i++) {
                    if (b->clientes[i].cliente_pid == pid) {
                        pos = i;
                        break;
                    }
                }
                for (int i = pos; i < b->nClientes - 1; i++)
                    b->clientes[i] = b->clientes[i+1];
                b->clientes = realloc(b->clientes,sizeof(Cliente) * (b->nClientes-1));
                (b->nClientes)--;
            }
            printf("\nUtente[%d] eliminado com sucesso.\n\n", pid);
        } else
            printf("\nNão existe nenhum utente com esse pid.\n\n");
    } else
        printf("\nLista de utentes vazia.\n\n");
}

void eliminaEspecialista(Balcao *b, int pid) {
    bool flg = false;
    if (b->nMedicos > 0) {
        for (int i = 0; i < b->nMedicos; i++)
            if (b->medicos[i].medico_pid == pid)
                flg = true;
        if (flg) {
            if (b->nMedicos == 1) {
                b->nMedicos = 0;
                free(b->medicos);
            } else {
                int pos = -1;
                for (int i = 0; i < b->nMedicos; i++) {
                    if (b->medicos[i].medico_pid == pid) {
                        pos = i;
                        break;
                    }
                }
                for (int i = pos; i < b->nMedicos - 1; i++)
                    b->medicos[i] = b->medicos[i+1];
                b->medicos = realloc(b->medicos,sizeof(Medico) * (b->nMedicos-1));
                (b->nMedicos)--;
            }
            printf("\nEspecialista[%d] eliminado com sucesso.\n\n", pid);
        } else
            printf("\nNão existe nenhum especialista com esse pid.\n\n");
    } else
        printf("\nLista de especialistas vazia.\n\n");
}

void listaUtentes(Balcao *b) {
    printf("\nNumero de utentes [%d]\n", b->nClientes);
    if (b->nClientes > 0)
        for (int i = 0; i < b->nClientes; i++)
            printf("\tPID[%d], NOME[%s], SINTOMAS[%s], ESPECIALIDADE[%s], PRIORIDADE[%d], EM_ESPERA[%d]\n",
                   b->clientes[i].cliente_pid, b->clientes[i].nome, b->clientes[i].sintomas,
                   b->clientes[i].especialidade, b->clientes[i].prioridade, b->clientes[i].emEspera);
    else
        printf("Nao existem utentes na lista\n");
    printf("\n");
}

void listaEspecialistas(Balcao *b) {
    printf("\nNumero de especialistas [%d]\n", b->nMedicos);
    if (b->nMedicos > 0)
        for (int i = 0; i < b->nMedicos; i++)
            printf("\tPID[%d], NOME[%s], ESPECIALIDADE[%s]\n",
                   b->medicos[i].medico_pid, b->medicos[i].nome, b->medicos[i].especialidade);
    else
        printf("Nao existem especialistas na lista\n");
    printf("\n");
}

Balcao pipeCliente(int fdRecebeCliente, Cliente c, Balcao b) {
    int size = read(fdRecebeCliente, &c, sizeof(c));
    if (size < sizeof(c)) {
        fprintf(stderr, "\nRecebidos sintomas incompletos, [bytes lidos %d]\n", size);
    }
    else if (size == sizeof(c)) {
        if (strcmp(c.sintomas,"sair") == 0) {
            printf("\nUtente[%d] a sair...\n\n", c.cliente_pid);
            eliminaUtente(&b,c.cliente_pid);
            unlink(CLIENT_FIFO_FINAL);
        } else if (strcmp(c.respondeMed,"adeus")==0) { // adeus - termina a consulta
            printf("\nUtente[%d] terminou a consulta.\n\n",c.cliente_pid);
            eliminaUtente(&b,c.cliente_pid);
            unlink(CLIENT_FIFO_FINAL);
        } else if (strcmp(c.respondeMed,"sair")==0) { // sair - termina a consulta e sai do sistema
            printf("\nUtente[%d] saiu da consulta e do sistema.\n\n",c.cliente_pid);
            eliminaUtente(&b,c.cliente_pid);
            unlink(CLIENT_FIFO_FINAL);
        } else {
            verificaCapacidaClientes(&b, c);
            if (b.cheioClientes) {
                /* responder ao meu cliente */
                sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,c.cliente_pid);
                int fdEnvio = open(CLIENT_FIFO_FINAL,O_WRONLY);
                if (fdEnvio == -1)
                    perror("\n Erro no open - Ninguem quis a resposta");
                int res = write(fdEnvio, &b, sizeof(b));
                if (res == sizeof(b))
                    fprintf(stderr,"\nenviou aviso de capacidade ao utente[%d]...\n\n",c.cliente_pid);
                else
                    fprintf(stderr,"\nerro a enviar aviso de capacidade utente[%d]...\n\n",c.cliente_pid);
                close (fdEnvio);
                return b;
            }

            printf("\na iniciar leitura...\n");
            printf("\nUtente[%d] chegou com os sintomas [%s]\n", c.cliente_pid, c.sintomas);


            /* se alterar os sintomas remove da fila onde estava para adicionar a outra */
            if (qualEspecialidade(&b,c.especialidade,1) && c.emEspera) {
                printf("\nUtente[%d] removido da fila de espera para a especialidade [%s]\n", c.cliente_pid, c.especialidade);
                c.emEspera = false;
            }

            /* recebe a especialidade e prioridade atribuida pelo classificador */
            c.sintomas[strlen(c.sintomas)] = '\n';
            char *aux;
            aux = enviaClassificador(c.sintomas);
            strcpy(b.resposta,aux);
            printf("\nBalcao a enviar [%s]\n", b.resposta);
            c.sintomas[strlen(c.sintomas)-1] = '\0';

            /* divide a frase recebida do classificador */
            setDadosCliente(&c,&b);

            /* atribui o utente à fila de espera com a especialidade correspondente */
            if (qualEspecialidade(&b,c.especialidade,0) && !c.emEspera) {
                c.emEspera = true;
                printf("\nUtente[%d] adicionado à fila de espera para a especialidade [%s]\n", c.cliente_pid, c.especialidade);
            }

            /* define todos os dados anteriores do cliente na estrutura balcao*/
            setCliente(&b,c);

            /* estes valores tem de ser redefinidos a zero para nao interferirem com outros clientes
             * que ja se encontrem a comunicar com o medico */
            b.comunicaMedPID = 0;
            b.comunicaCliPID = 0;

            /* responder ao meu cliente */
            sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,c.cliente_pid);
            int fdEnvio = open(CLIENT_FIFO_FINAL,O_WRONLY);
            if (fdEnvio == -1)
                perror("\n Erro no open - Ninguem quis a resposta");
            int res = write(fdEnvio, &b, sizeof(b));
            if (res == sizeof(b))
                fprintf(stderr,"\nescreveu a resposta...\n\n");
            else
                fprintf(stderr,"\nerro a escrever a resposta...\n\n");
            close (fdEnvio);
        }
    }
    return b;
}

Balcao pipeMedico(int fdRecebeMedico, Medico m, Balcao b, int *med_pid) {
    int size = read(fdRecebeMedico, &m, sizeof(m));
    if (size > 0) {
        if (strcmp(m.medicoEncerrou,"sair")==0) {
            printf("\nEspecialista[%d] saiu.\n\n",m.medico_pid);
            eliminaEspecialista(&b,m.medico_pid);
            unlink(MEDICO_FIFO_FINAL);
        } else if (strcmp(m.respondeCli,"sair")==0) { // sair - termina a consulta e sai do sistema
            printf("\nEspecialista[%d] saiu da consulta e do sistema.\n\n",m.medico_pid);
            eliminaUtente(&b,m.comunicaPid);
            eliminaEspecialista(&b,m.medico_pid);
            unlink(MEDICO_FIFO_FINAL);
        } else if (strcmp(m.respondeCli,"adeus")==0) { // adeus - termina a consulta
            printf("\nEspecialista[%d] terminou a consulta.\n\n",m.medico_pid);
            eliminaUtente(&b,m.comunicaPid);
            strcpy(m.respondeCli,"vazia");
        } else {
            verificaCapacidaMedicos(&b, m);
            if (b.cheioMedicos) {
                /* avisar o medico da capacidade maxima */
                sprintf(MEDICO_FIFO_FINAL, MEDICO_FIFO, m.medico_pid);
                int fdEnvio = open(MEDICO_FIFO_FINAL, O_WRONLY);
                int res = write(fdEnvio, &b, sizeof(b));
                if (res == sizeof(b))
                    fprintf(stderr, "\nenviou aviso de capacidade ao especialista[%d]...\n\n", m.medico_pid);
                else
                    fprintf(stderr, "\nerro a enviar aviso de capacidade ao especialista[%d]...\n\n", m.medico_pid);
                close(fdEnvio);
                return b;
            }

            /* esta atribuição apenas server para quando o especialista entra diretamente numa consulta
                 * e queremos guardar o seu pid no balcao para iniciar a contagem decrescente */
            *med_pid = m.medico_pid;

            /* se sinalVida == true significa que está a comunicar a partir da consulta, nao entra na condição abaixo */
            if (!m.sinalVida) {
                /* procurar o utente com que vai iniciar a consulta  */
                b.comunicaMedPID = procuraCliente(m, b);
                b.comunicaCliPID = m.medico_pid;  //este medico comunica com o cliente na func procuraCliente
                m.comunicaPid = b.comunicaMedPID;

                setMedico(&b, m);

                if (b.comunicaMedPID > 0) {
                    /* emEspera = false -> evita encontrar algum utente que se encontre em consulta */
                    for (int i = 0; i < b.nClientes; i++) {
                        if (b.comunicaMedPID == b.clientes[i].cliente_pid) {
                            if (b.clientes[i].emEspera) {
                                b.clientes[i].emEspera = false;
                                qualEspecialidade(&b, m.especialidade, 1);
                                iniciaConsulta(b, m);
                                b.comunicaMedPID = 0;
                                b.comunicaCliPID = 0;
                            }
                        }
                    }
                }
            } else {
                printf("\nEspecialista[%d] deu sinal de vida durante a consulta.\n\n",m.medico_pid);
            }
        }
    } else
        fprintf(stderr, "\nRecebidos dados incompletos, [bytes lidos %d]\n", size);

    return b;
}

void setDadosCliente(Cliente *c, Balcao *b) {
    char divideStr[2][20];
    int counter = 0, j = 0;
    for (int i = 0; i < strlen(b->resposta); i++) {
        if (b->resposta[i] == '\0' || b->resposta[i] == ' ') {
            divideStr[counter][j] = '\0';   // detetou espaco ou \0,
            counter++;                      // termina a leitura da palavra
            j = 0;                          // e incrementa o num de linhas ( counter )
        } else {    // se nao for espaco ou \0, copia os carateres 1 a 1
            divideStr[counter][j] = b->resposta[i];
            j++;
        }
    }
    strcpy(c->especialidade,divideStr[0]);
    c->prioridade = atoi(divideStr[1]);
}

int procuraCliente(Medico m, Balcao b) {
    int aux = 0;
    if (b.nClientes > 0) {
        for (int i = 0; i < b.nClientes; i++)
            if (strcmp(m.especialidade, b.clientes[i].especialidade)==0
                && b.clientes[aux].prioridade >= b.clientes[i].prioridade && b.clientes[i].emEspera)
                aux = i;
        printf("\nBalcão encontrou o utente[%d] na fila de espera para a especialidade[%s] com prioridade[%d]\n\n",
               b.clientes[aux].cliente_pid, b.clientes[aux].especialidade, b.clientes[aux].prioridade);
        return b.clientes[aux].cliente_pid;
    }
    return 0;
}

void iniciaConsulta(Balcao b, Medico m) {
    /* responder ao meu cliente */
    sprintf(CLIENT_FIFO_FINAL,CLIENT_FIFO,b.comunicaMedPID);
    int fdEnvio = open(CLIENT_FIFO_FINAL,O_WRONLY);
    if (fdEnvio == -1)
        perror("\n Erro no open - Ninguem quis a resposta");
    write(fdEnvio, &b, sizeof(b));
    close (fdEnvio);

    /* responder ao meu medico */
    sprintf(MEDICO_FIFO_FINAL, MEDICO_FIFO, m.medico_pid);
    int fd_envio = open(MEDICO_FIFO_FINAL, O_WRONLY);
    write(fd_envio, &b, sizeof(b));
    close(fd_envio);

    printf("\nEspecialista[%d] vai iniciar a consulta com o Utente[%d].\n\n",m.medico_pid,b.comunicaMedPID);
}

void verificaCapacidaClientes(Balcao *b, Cliente c) {
    bool flg = false;
    for (int i = 0; i < b->nClientes; i++) {
        if (c.cliente_pid == b->clientes[i].cliente_pid)
            flg = true;
    } // para o caso de o cliente constar da lista mas querer alterar os sintomas

    if (!flg && b->nClientes == b->MAXCLIENTES) {
        fprintf(stderr, "\nNão há lugares para novos utentes: Utentes[%d], MAX_UTENTES[%d]\n", b->nClientes, b->MAXCLIENTES);
        b->cheioClientes = true;
    }
}

void verificaCapacidaMedicos(Balcao *b, Medico m) {
    bool flg = false;
    for (int i = 0; i < b->nMedicos; i++) {
        if (m.medico_pid == b->medicos[i].medico_pid)
            flg = true;
    } // para o caso de o medico constar da lista mas querer alterar os sintomas

    if (!flg && b->nMedicos == b->MAXMEDICOS) {
        fprintf(stderr, "\nNão lugares para novos especialistas: Especialistas[%d], MAX_ESPECIALISTAS[%d]\n", b->nMedicos, b->MAXMEDICOS);
        b->cheioMedicos = true;
    }
}

bool qualEspecialidade(Balcao *b, char especialidade[], int op) {
    if (op == 0) {  // adiciona o utente a fila de espera
        if (b->filaEstomatologia < 5 && strcmp(especialidade,"estomatologia") == 0) {
            (b->filaEstomatologia)++;
            return true;
        } else if (b->filaGeral < 5 && strcmp(especialidade,"geral") == 0) {
            (b->filaGeral)++;
            return true;
        } else if (b->filaGeral < 5 && strcmp(especialidade,"neurologia") == 0) {
            (b->filaNeurologia)++;
            return true;
        } else if (b->filaOftalmologia < 5 && strcmp(especialidade,"oftalmologia") == 0) {
            (b->filaOftalmologia)++;
            return true;
        } else if (b->filaOrtopedia < 5 && strcmp(especialidade,"ortopedia") == 0) {
            (b->filaOrtopedia)++;
            return true;
        }
        printf("\nFila de espera cheia para a especialidade[%s]\n\n",especialidade);
    } else if (op == 1) {   // remove o utente da fila de espera
        if (strcmp(especialidade,"estomatologia") == 0) {
            (b->filaEstomatologia)--;
            return true;
        } else if (strcmp(especialidade,"geral") == 0) {
            (b->filaGeral)--;
            return true;
        } else if (strcmp(especialidade,"neurologia") == 0) {
            (b->filaNeurologia)--;
            return true;
        } else if (strcmp(especialidade,"oftalmologia") == 0) {
            (b->filaOftalmologia)--;
            return true;
        } else if (strcmp(especialidade,"ortopedia") == 0) {
            (b->filaOrtopedia)--;
            return true;
        }
    }
    return false;
}

void listaFilaEspera(Balcao b) {
    if (b.filaEstomatologia > 0) {
        printf("Estomatologia[%d]\n",b.filaEstomatologia);
        for (int i = 0; i < b.nClientes; i++) {
            if (strcmp(b.clientes[i].especialidade,"estomatologia")==0 && b.clientes[i].emEspera)
                printf("\tutente[%d]\tsintomas[%s]\tprioridade[%d]\n",b.clientes[i].cliente_pid, b.clientes[i].sintomas, b.clientes[i].prioridade);
        }
    } else
        printf("\nEstomatologia: lista vazia\n");

    if (b.filaGeral > 0) {
        printf("Geral[%d]\n",b.filaGeral);
        for (int i = 0; i < b.nClientes; i++) {
            if (strcmp(b.clientes[i].especialidade,"geral")==0 && b.clientes[i].emEspera)
                printf("\tutente[%d]\tsintomas[%s]\tprioridade[%d]\n",b.clientes[i].cliente_pid, b.clientes[i].sintomas, b.clientes[i].prioridade);
        }
    } else
        printf("Geral: lista vazia\n");

    if (b.filaNeurologia > 0) {
        printf("Neurologia[%d]\n",b.filaNeurologia);
        for (int i = 0; i < b.nClientes; i++) {
            if (strcmp(b.clientes[i].especialidade,"neurologia")==0 && b.clientes[i].emEspera)
                printf("\tutente[%d]\tsintomas[%s]\tprioridade[%d]\n",b.clientes[i].cliente_pid, b.clientes[i].sintomas, b.clientes[i].prioridade);
        }
    } else
        printf("Neurologia: lista vazia\n");

    if (b.filaOftalmologia > 0) {
        printf("Oftalmologia[%d]\n",b.filaOftalmologia);
        for (int i = 0; i < b.nClientes; i++) {
            if (strcmp(b.clientes[i].especialidade,"oftalmologia")==0 && b.clientes[i].emEspera)
                printf("\tutente[%d]\tsintomas[%s]\tprioridade[%d]\n",b.clientes[i].cliente_pid, b.clientes[i].sintomas, b.clientes[i].prioridade);
        }
    } else
        printf("Oftalmologia: lista vazia\n");

    if (b.filaOrtopedia > 0) {
        printf("Ortopedia[%d]\n", b.filaOrtopedia);
        for (int i = 0; i < b.nClientes; i++) {
            if (strcmp(b.clientes[i].especialidade,"ortopedia")==0)
                printf("\tutente[%d]\tsintomas[%s]\tprioridade[%d]\n",b.clientes[i].cliente_pid, b.clientes[i].sintomas, b.clientes[i].prioridade);
        }
    } else
        printf("Ortopedia: lista vazia\n");
}

void setFreqFila(Balcao *b, int tempo) {
    if (tempo > 0) {
        b->freqFila = tempo;
        printf("\nFrequencia da listagem da fila altera para [%d] segundos\n\n", b->freqFila);
    }
    else
        printf("\nValor introduzido tem de ser maior que zero.\n\n");
}

int getFreqFila(Balcao *b) { return b->freqFila; }

void setThreadMedico(Balcao *b, int pid, pthread_t *timer) {
    for (int i = 0; i < b->nMedicos; i++)     {
        if (b->medicos[i].medico_pid == pid) {
            b->medicos[i].timer = *timer;
            b->medicos[i].thread = true;
        }
    }
}

pthread_t delThreadMedico(Balcao b, int pid) {
    for (int i = 0; i < b.nMedicos; i++)
        if (b.medicos[i].medico_pid == pid)
            return b.medicos[i].timer;
    return NULL;
}

void *sinalVida(void *dados) {
    Temporizador *pdados = (Temporizador *)dados;
    while(1) {
        //printf("\nESP[%d] => [%d]\n", pdados->pid,pdados->tempo);
        pdados->tempo--;
        fflush(stdout);
        sleep(1);

        if (pdados->tempo == 0) {
            //printf("\nESP[%d] => [%d]\n", pdados->pid,pdados->tempo);
            //printf("Sem sinal de vida do especialista[%d]!",pdados->pid);
            pdados->expirou = true;
            fflush(stdout);
            break;
        }
    }
    pthread_exit(NULL);
}