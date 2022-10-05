#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paragem{
    char nome[50];
    int minutos;
} Paragem;

void mostra_percurso(char* nomefich) {
    Paragem par;

    FILE *f = fopen(nomefich,"rb");

    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return;
    }

    while (fread(&par, sizeof(Paragem), 1, f) == 1)
        printf("%-25s %3d\n", par.nome, par.minutos);

    fclose(f);
}

int percurso_completo(char* nomefich) {
    Paragem par;
    int duracao_total = 0;

    FILE *f = fopen(nomefich,"rb");

    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return 0;
    }

    while (fread(&par, sizeof(Paragem), 1, f) == 1)
        duracao_total += par.minutos;

    fclose(f);
    
    return duracao_total;
}

int viagem(char* nomefich, char *localA, char *localB) {
    Paragem par;
    int estado = 0, minutos = 0;

    FILE *f = fopen(nomefich,"rb");

    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return 0;
    }

    while (estado != 2 &&fread(&par, sizeof(Paragem), 1, f) == 1) {
        switch(estado) {
            case 0:
                if (!strcmp(par.nome,localA))
                    estado = 1;
                break;
            case 1:
                minutos += par.minutos;
                if (!strcmp(par.nome, localB))
                estado = 2;
                break;
        }
    }

    fclose(f);
    
    if(estado == 2)
        return minutos;
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    char *fich = "cp01.dat";
    char *cidadeA = "Aveiro";
    char *cidadeB = "Porto";
    
    mostra_percurso(fich);

    printf("Duração: %d\n", percurso_completo(fich));
    
    int minutos = viagem(fich, cidadeA, cidadeB);
    
//    if(minutos > 0)
//        printf("")
//    else
        
    return 0;
}
