//
//  main.c
//  ex2
//
//  Created by rsantos on 23/04/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#include <stdio.h>

typedef struct med_sum {
    float media;
    int soma;
} MedSum;

void mostra_numeros(char *nomefich) {
    int num;
    
    FILE *f = fopen(nomefich, "rb");
    
    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        return;
    }
        
    while(fread(&num,sizeof(int),1,f) == 1)
        printf("%3d\n",num);
    
    fclose(f);
}

MedSum calcula_media(char *nomefich) {
    int num, i = 0;
    MedSum t;
    t.soma = 0;
    
    FILE *f = fopen(nomefich, "rb");
    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomefich);
        //return 0;
    }
        
    fread(&num,sizeof(int),1,f);
    while(feof(f) == 0) {
        t.soma += num;
        i++;
        fread(&num, sizeof(num),1,f);
        t.media = t.soma/(float)i;
    }
    
    fclose(f);
    
    return t;
}

int criaVetor(char* nomeFich, int* tam) {
    FILE *f;
    int *b = NULL, num, *aux;
    
    f = fopen(nomeFich, "rb");;
    
    if(!f) {
        fprintf(stderr, "Erro a abrir o ficheiro: %s\n", nomeFich);
        (*tam) = 0;
        return NULL;
    }
    
    while (fread(&num,sizeof(int),1,f) == 1) {
        if (num % 2 == 0) {
            aux = realloc(b, sizeof(int) * (*tam + 1));
            
            if(aux == NULL) {
                printf("Falhou a realocação. Mantem tamanho\n");
                (*tam) = 0;
                return NULL;
            } else {
                b = aux;
                b[(*tam)] = num;
            }
            (*tam)++;
        }
    }
    
    fclose(f);
    return b;
}

void cria_ficheiro(char* fich, char* fichmedsup, char* fichmedinf) {
    FILE *f, *g, *t;
    
    float media;
    int num;
    
    if ((f=fopen(fichmedsup, "rb")) == NULL) {
        fprintf(stderr, "Erro a abrir o ficheiro %s\n", fich);
        return;
    }
    
    if((g=fopen(fichmedsup,"wb")) == NULL) {
        fclose(f);
        fprintf(stderr, "Erro a abrir o ficheiro %s\n", fichmedsup);
        return;
    }
    
    if((g=fopen(fichmedsup,"wb")) == NULL) {
        fclose(f);
        fclose(g);
        fprintf(stderr, "Erro a abrir o ficheiro %s\n", fichmedinf);
        return;
    }
    
    media = calcula_media(fich).media;
    
    while (fread(&num,sizeof(int),1,f) == 1) {
        if (num >= media)
            fwrite(&num,sizeof(int),1,g);
        else
            fwrite(&num,sizeof(int),1,t);
    }
}
int main(int argc, const char * argv[]) {
    char* fich = "valoresEx2.bin";
    MedSum t;
    int *b = NULL;
    int tam = 0;
    mostra_numeros(fich);
    
    t = calcula_media(fich);
    
    printf("\nA soma dos valores é %d\n", t.soma);
    printf("A media dos valores é %.2f\n", t.media);
    
    b = criaVetor(fich, &tam);
    pritnf("\nO vetor criado tem %d valores", tam);
    for (int i = 0; i < tam; i++) {
        printf("\n%3d", b[i]);
    }
    return 0;
}


