
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa no, *pno; 

struct pessoa{
    char nome[100]; 
    int idade;
    pno prox;
};

// FALTA VALIDAR AS ALOCACOES DE MEMORIA
pno* criaED(pno* lista, int *total){
    int n = 5, i;
    int pos[5] = {2,0,3,4,1};
    no a[] = {{"Beatriz", 29, NULL}, {"Carlos", 36, NULL},{"Hugo", 51, NULL},
              {"Nuno", 18, NULL}, {"Sara", 22, NULL}};
    
    *total = n;
    pno novo;
    pno *v;
    
    *lista = NULL;
    v = malloc(sizeof(pno)*n);
    
    for(i=n-1; i>=0; i--){
        novo = malloc(sizeof(no));
        *novo = a[i];
        novo->prox = *lista;
        *lista = novo;
        v[pos[i]]=novo;
    }
    return v;
}


void mostraTudo(pno p, pno v[], int total){
    
    int i;
    
    printf("Ordem Alfabetica\n");
    while(p != NULL){
        printf("%s\n", p->nome);
        p = p->prox;
    }
    
    printf("Classificacao na Corrida:\n");
    for(i=0; i<total; i++)
        printf("%d: %s\n", i+1, v[i]->nome);
}

pno* adicionaChegada(char *nome, int idade, pno v[], int *total, pno *lista){
    pno novo, aux;
    pno *nv;
    
    // Alocacao no novo no
    novo = malloc(sizeof(no));
    if(novo == NULL)
        return v;
    
    // Realocacao do vetor
    nv = realloc(v, sizeof(pno)*(*total+1));
    if(nv == NULL){
        free(novo);
        return v;
    }
    
    // Atualizacao do vetor e do contador
    v = nv;
    v[*total] = novo;
    (*total)++;
    
    // Preencher o novo no
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->prox = NULL;
    
    // Inserir ordenadamente na lista
    
    if(*lista==NULL || strcmp((*lista)->nome, novo->nome)>0){
        novo->prox = *lista;
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux->prox!=NULL && strcmp(aux->prox->nome, novo->nome) < 0)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return v;
}

int main(){
    pno lista = NULL;  
    pno* v = NULL;
    int total = 0;
    
   
    v = criaED(&lista, &total);
    
    //mostraTudo(lista, v, total);
    
    v = adicionaChegada("Maria", 32, v, &total, &lista);
    v = adicionaChegada("Ana", 22, v, &total, &lista);
    v = adicionaChegada("Tiago", 47, v, &total, &lista);
    
    mostraTudo(lista, v, total);
   

    return 0;
}