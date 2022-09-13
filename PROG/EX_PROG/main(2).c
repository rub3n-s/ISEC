#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//1. livro é sinónimo de struct objeto
// 2. plivro é sinónimo de struct objeto* ou livro*

typedef struct objeto livro, *plivro;

struct objeto{
    char titulo[100], autor[100];
    int cota;  
    
    plivro prox;
};


void mostraLivros(plivro p){
    
    if(p == NULL)
        printf("Lista Vazia\n");
    else{
    while(p != NULL){
        printf("%s\t%s\t%d\n", p->titulo, p->autor, p->cota);
        p = p->prox;
    }
    }
}

void preenche(plivro p)
{
	printf("Titulo: ");
	scanf(" %99[^\n]", p->titulo);
	printf("Autor: ");
	scanf(" %99[^\n]", p->autor);
	printf("Cota: ");
	scanf("%d", &p->cota);
	p->prox = NULL;
}

plivro insereOrd(plivro p){
    plivro novo, aux;
    
    //1. Alocar espaco
    novo = malloc(sizeof(livro));
    if(novo == NULL)
        return p;  
    // 2. Preencher
    preenche(novo);   
    
    // 3. Inserir na Lista
    if(p == NULL || p->cota > novo->cota){ // Lista vazia ou novo livro com cota menor
        novo->prox=p;
        p = novo;    
    }
    else{
        aux = p;
        while(aux->prox != NULL && aux->prox->cota < novo->cota)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    } 
    return p;
}


void guardaLivros(plivro p, char *nomeF){
    FILE *f;
    int total=0;
    
    f = fopen(nomeF, "wb");
    if(f == NULL)
        return;
    
    while(p != NULL){
        fwrite(p, sizeof(livro), 1, f);
        total++;
        p = p->prox;
    }
    fwrite(&total, sizeof(int), 1, f); 
    fclose(f);
}


plivro recuperaLista(char *nomeF){
    plivro p = NULL, novo, aux;
    FILE *f;
    int total, i;
    
    f = fopen(nomeF, "rb");
    if(f == NULL) return NULL;
    
    fseek(f, -sizeof(int), SEEK_END);
    fread(&total, sizeof(int), 1, f);
    rewind(f);
    
    for(i=0; i<total; i++){
        novo = malloc(sizeof(livro));
        if(novo == NULL){
            fclose(f);
            return p;
        }
    
        fread(novo, sizeof(livro), 1, f);
        novo->prox = NULL;
        
        if(p == NULL)
            p = novo;
        else{
            aux = p;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    fclose(f);
    return p;
}

int main(){
    
    plivro lista = NULL;        // Criar uma lista
    int i;
    
    lista = recuperaLista("bib.dat");
 
    mostraLivros(lista);
    
    return 0;
    
    // Adicionar alguns livros - 4 livros  
    for(i=0; i<4; i++)
        lista = insereOrd(lista);
    mostraLivros(lista);
    
    
    guardaLivros(lista, "bib.dat");
    
    // Chamar a função que iberta toda a lista ligada 
     
    return 0;
}
