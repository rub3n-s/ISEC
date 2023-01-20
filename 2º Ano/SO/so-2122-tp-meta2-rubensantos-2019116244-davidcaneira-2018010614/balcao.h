#ifndef TP_SO_RUBENSANTOS_2019116244_BALCAO_H
#define TP_SO_RUBENSANTOS_2019116244_BALCAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>

#define E 50
#define S 150
#define cmd_len 50
#define RES 150

#define BALCAO_FIFO "BALCAO"
#define BALCAO_FIFO_MED "BALCAO_MED"
#define CLIENT_FIFO "CLIENTE[%d]" // cliente[123]
#define MEDICO_FIFO "MEDICO[%d]" // medico[123]

char CLIENT_FIFO_FINAL[100];    // cliente[123] -> nome do cliente_fifo fica nesta variavel global
char MEDICO_FIFO_FINAL[100];    // medico[123] -> nome do medico_fifo fica nesta variavel global

// definir as variaveis de ambiente
static const char *EV_MAXCLIENTES = "MAXCLIENTES";
static const char *EV_MAXMEDICOS = "MAXMEDICOS";

typedef struct  {
    int pid;
    int tempo;
    bool expirou;
} Temporizador;

typedef struct {
    int medico_pid; // id do processo medico
    char nome[E];
    char especialidade[E];
    char respondeCli[RES];
    int comunicaPid;    // pid do cliente que comunica com o medico
    char medicoEncerrou[E];
    bool thread;
    pthread_t timer;
    bool sinalVida;
} Medico;

typedef struct {
    int cliente_pid;    // id do processo cliente
    char nome[E];     // nome do cliente
    char sintomas[S];   // sintomas do cliente
    char especialidade[E];  // atribuida pelo balcao, balcao recebe do classificador
    int prioridade; // atribuida pelo balcao, balcao recebe do classificador
    int comunicaPid;    // pid do medico que comunica com o cliente
    char respondeMed[RES];
    bool emEspera;
} Cliente;

typedef struct {
    int MAXCLIENTES;    // num max de clientes, obtido da var ambiente
    int MAXMEDICOS;   // num max de medicos, obtido da var ambiente
    int nClientes;  // contadorer para utentes
    int nMedicos; // contadorer para medicos
    Cliente * clientes;    // array para guardar todos os clientes
    Medico * medicos;    // array para guardar todos os medicos
    char resposta[RES]; // devolve ao cliente a resposta vinda do classificador
    int comunicaMedPID;    // pid do cliente que comunica com o medico
    int comunicaCliPID;    // pid do medico que comunica com o cliente
    bool cheioClientes;
    bool cheioMedicos;
    int freqFila;
    int filaEstomatologia;
    int filaNeurologia;
    int filaGeral;
    int filaOftalmologia;
    int filaOrtopedia;
    bool avisa;
    bool medicoExpulso;
} Balcao;

static const char *cmd[] = {
        "utentes",  // lista os utentes
        "especialistas",    // lista os especialistas
        "delut",    // elimina utente em espera
        "delesp",    // elimina especialista em espera
        "freq", // apresenta ocupacao das filas de espera de N em N seg.
        "encerra"   //  termina o programa avisando utentes, medicos e classif.
};

int max(int a, int b);
void trataSig(int i);
void trataSigAlrm(int i);
bool verificaCmd(char *str);
void listaCmd();
int getEnvVars(Balcao *balcao);
void inicializa(Balcao *b);
void infoBalcao(Balcao b);
char* enviaClassificador(char string[]);
void listaUtentes(Balcao *b);
void listaEspecialistas(Balcao *b);
void trataTeclado(Balcao *b);
void divideComando(char cmd[], char *cmd_ret, int *pid_ret);
void executaCmd(Balcao *b,char cmd[],int pid);
void setCliente(Balcao *b, Cliente c);
void setMedico(Balcao *b, Medico m);
void eliminaUtente(Balcao *b, int pid);
void eliminaEspecialista(Balcao *b, int pid);
Balcao pipeCliente(int fdRecebeCliente, Cliente c, Balcao b);
Balcao pipeMedico(int fdRecebeMedico, Medico m, Balcao b, int *med_pid);
void setDadosCliente(Cliente *c, Balcao *b);
int procuraCliente(Medico m, Balcao b);
void iniciaConsulta(Balcao b, Medico m);
void verificaCapacidaClientes(Balcao *b, Cliente c);
void verificaCapacidaMedicos(Balcao *b, Medico m);
bool qualEspecialidade(Balcao *b, char especialidade[], int op);
void listaFilaEspera(Balcao b);
void setFreqFila(Balcao *b, int tempo);
void informaTodos(Balcao b);
void setThreadMedico(Balcao *b, int pid, pthread_t *timer);
pthread_t delThreadMedico(Balcao b, int pid);
void *sinalVida(void *dados);

#endif //TP_SO_RUBENSANTOS_2019116244_BALCAO_H
