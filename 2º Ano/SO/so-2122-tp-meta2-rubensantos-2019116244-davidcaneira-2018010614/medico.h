#ifndef TP_SO_RUBENSANTOS_2019116244_MEDICO_H
#define TP_SO_RUBENSANTOS_2019116244_MEDICO_H

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

typedef struct {
    int medico_pid; // id do processo medico
    char nome[E];
    char especialidade[E];
    char respondeCli[RES];
    int comunicaPid;    // pid do medico que comunica com o cliente
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
} Balcao;

void trataSig(int i);
bool verificaArgs(int argc);
Medico setInfoMedico(char nome[], char especialidade[], int pid);
void getInfoMedico(Medico m);
Medico trataTeclado(Medico medico);
void comunicacaoMedicoCliente(Medico medico, Cliente cliente);

#endif //TP_SO_RUBENSANTOS_2019116244_MEDICO_H
