
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dados disc, *pdisc;
typedef struct pessoa aluno, *paluno;

struct dados {
    char nome[50];
    int ano, semestre, n_alunos;
    paluno lista;
    pdisc prox;
};

struct pessoa {
    char nome[100];
    char numero[15];
    paluno prox;
};


void libertaAlunos(paluno p){
    paluno auxA;
    
    while(p!=NULL){
        auxA = p;
        p = p->prox;
        free(auxA);
    }
}

void libertaTudo(pdisc p){
    pdisc auxD;
    
    while(p != NULL){
        libertaAlunos(p->lista);
        auxD = p;
        p = p->prox;
        free(auxD);
    }
}

pdisc criaLista(){
    disc a[3] = {{"SD", 1,1,2,NULL,NULL}, {"TAC", 1,2,0,NULL,NULL}, {"Prog", 1,2,3,NULL,NULL}};
    aluno b[5] = {{"Diogo", "12345"},{"Carlos", "345444"},{"Sofia", "123432"},{"Ana", "954483"},{"Joao", "336892"}};
    
    pdisc lista = NULL, novoD;
    paluno novoA;
    int i, j, k=0;
    
    for(i=0; i<3; i++){
        novoD = malloc(sizeof(disc));
        if(novoD == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoD = a[i];
        for(j=0; j<novoD->n_alunos; j++){
            novoA = malloc(sizeof(aluno));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k++];
            novoA->prox = novoD->lista;
            novoD->lista = novoA;
        }
        novoD->prox = lista;
        lista = novoD;
    }
    return lista;
}


void mostraCurso(pdisc p){
    paluno aux;
    
    while(p != NULL){
        printf("%s - (%d, %d) com %d alunos inscritos\n",
                p->nome, p->ano, p->semestre, p->n_alunos);  
        aux = p->lista;      
        while(aux != NULL){
            printf("%s\n", aux->nome);
            aux = aux->prox;
        }    
        p = p->prox;
    }
}

pdisc adicionaD(pdisc p, char *nomeD, int a, int s){
    
    pdisc novo;
    
    novo = malloc(sizeof(disc));
    if(novo == NULL) return p;
    strcpy(novo->nome, nomeD);
    novo->ano = a;
    novo->semestre = s;
    novo->n_alunos = 0;
    novo->lista = NULL;
    
    novo->prox = p;
    p = novo;
    
    return p;
}

void inscreveA(pdisc p, char *nomeD, char *nomeA, char *numA){
    paluno novo;
    
    while(p != NULL && strcmp(p->nome, nomeD) != 0)
        p = p->prox;
    
    if(p == NULL)
        return;
    
    novo = malloc(sizeof(aluno));
    if(novo == NULL) return;
    
    strcpy(novo->nome, nomeA);
    strcpy(novo->numero, numA);
    
    novo->prox = p->lista;
    p->lista = novo;
    
    p->n_alunos++;
}

pdisc eliminaD(pdisc p, char *nomeD){
    pdisc atual = p, ant = NULL;
    
    while(atual!= NULL && strcmp(atual->nome, nomeD) != 0){
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual == NULL)
        return p;
    
    if(atual == p)
        p = p->prox;
    else
        ant->prox = atual->prox;
    
    libertaAlunos(atual->lista);
    free(atual);
    return p; 
}


pdisc insereDiscFinal(pdisc p, pdisc nova){
    pdisc aux;
    
    if(p==NULL)
        p = nova;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = nova;
    }
    return p;
}

paluno insereAlunoFinal(paluno p, paluno novo){
    paluno aux;
    
    if(p==NULL)
        p = novo;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}



pdisc recuperaCurso(char *nomeF){
    pdisc p = NULL, novaD;
    paluno novoA;
    FILE *f;
    int total, i, j;
    
    f = fopen(nomeF, "rb");
    if (f == NULL) return p;
    
    fread(&total, sizeof(int), 1, f);
    for(i=0; i<total; i++){
        novaD = malloc(sizeof(disc));
        if(novaD == NULL){
            libertaTudo(p);
            fclose(f);
            return NULL;
        }
        fread(novaD, sizeof(disc), 1, f);
        novaD->prox = NULL;
        novaD->lista = NULL;
        p = insereDiscFinal(p, novaD);
        for(j=0; j<novaD->n_alunos; j++){
            novoA = malloc(sizeof(aluno));
            if(novoA == NULL){
                libertaTudo(p);
                fclose(f);
                return NULL;
            }
            fread(novoA->nome, sizeof(char), 100, f);
            fread(novoA->numero, sizeof(char), 15, f);
            novoA->prox = NULL;
            novaD->lista = insereAlunoFinal(novaD->lista, novoA);
        }
    }
    fclose(f);
    return p;
}

int contaD(pdisc p){
    int total=0;
    
    while(p!= NULL){
        total++;
        p = p->prox;
    }
    return total;
}

void gravaCurso(pdisc p, char *nomeF){
    FILE *f;
    int total;
    paluno aux;
    
    f = fopen(nomeF, "wb");
    if(f == NULL) return;
    
    total = contaD(p);
    fwrite(&total, sizeof(int), 1, f);
    
    while(p!=NULL){
        fwrite(p, sizeof(disc), 1, f);
        aux = p->lista;
        while(aux != NULL){
            fwrite(aux->nome, sizeof(char), 100, f);
            fwrite(aux->numero, sizeof(char), 15, f);
            aux = aux->prox;
        }
        p = p->prox;
    }
    fclose(f);
}


int main(){
    
    pdisc curso = NULL;     // Criar a ED
    
    //curso = criaLista();
    
    curso = recuperaCurso("curso.bin");
    
    mostraCurso(curso);
    return 0;
    

    curso = adicionaD(curso, "FCG", 1, 2); 
    inscreveA(curso, "FCG", "Ana", "12344556");
    inscreveA(curso, "SD", "Antonio", "123444444556");
    
    mostraCurso(curso);
    
    gravaCurso(curso, "curso.bin");
          
    libertaTudo(curso);
   
    return 0;
}
