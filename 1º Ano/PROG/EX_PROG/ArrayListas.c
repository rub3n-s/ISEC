
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 27

typedef struct palavra no, *pno;

struct palavra{
    char pal[50];
    int conta;
    pno prox;
}; 

void libertaTXT(pno texto[]){
    int i;
    pno aux;
    
    for(i=0; i<N; i++)
        while(texto[i] != NULL){
            aux = texto[i];
            texto[i] = texto[i]->prox;
            free(aux);
        }
}

void criaED(pno texto[]){
    char pal[9][20] = {"avestruz", "ave",  "bote", "bilhete", "barco", "banana", "coimbra", "coelho", "carro"};
    pno novo;
    int i;
    
    for(i=0; i<9; i++){
        novo = malloc(sizeof(no));
        if (novo == NULL){
            libertaTXT(texto);
            return;
        }        
        strcpy(novo->pal, pal[i]);
        novo->conta = 1 + rand()%4;
        novo->prox = texto[pal[i][0]-'a'];
        texto[pal[i][0]-'a'] = novo;     
    }   
}


pno cria_preenche(char *pal)
{
	pno novo;
	
	novo = malloc(sizeof(no));
	if(novo == NULL)
		return NULL;

	novo->conta = 1;
	strcpy(novo->pal, pal);
	novo->prox = NULL;
	return novo;
} 

void mostraTudo(pno t[]){
    int i;
    pno aux;
    
    for(i=0; i<N; i++){
        aux = t[i];
        while(aux!=NULL){
            printf("%s\t%d\n", aux->pal, aux->conta);
            aux = aux->prox;
        }
    }
}

int consulta(pno t[], char *st){
    pno aux;
    int index = N-1;
    
    if(*st>='a' && *st<='z')
        index = *st -'a';
    
    aux = t[index];
   
    while(aux != NULL && strcmp(aux->pal, st) < 0){
        printf("*%s*\n", aux->pal);
        aux = aux->prox;
    }
    if(aux == NULL || strcmp(aux->pal, st)>0)
        return 0;
    else
        return aux->conta; 
}


void converte(){
    char c;
    
    for(c='a'; c<='z'; c++)
        printf("%c - %d - %d\n", c, c, c - 'a');
}

int main(){
    
    pno texto[N] = {NULL};      // Criar ED
   
    
    criaED(texto);
    
    mostraTudo(texto);
    
    printf("%d\n", consulta(texto, "carta"));
       
    
    
  
    
    return 0;
}
