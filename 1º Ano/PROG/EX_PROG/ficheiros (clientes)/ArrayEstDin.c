#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dados cliente;

struct dados{
	char nome[100];
	char nconta[15];
	int montante;
};

void escreve_info(cliente a){
	printf("Nome: %s\tNº conta: %s\tSaldo: %d\n",
		   a.nome, a.nconta, a.montante);
}


cliente obtem_info(){
    cliente t;
    
    printf("Nome: "); scanf(" %[^\n]", t.nome);
    printf("Conta: "); scanf(" %s", t.nconta);
    printf("Montante: "); scanf("%d", &(t.montante));
    return t;  
}

void escreve_todos(cliente tab[], int n){
	int i;
	for(i=0; i<n; i++)
		escreve_info(tab[i]);
}


void procura_mais_rico(cliente tab[], int n){
	int i, index=0;

	for(i=1; i<n; i++)
		if(tab[i].montante > tab[index].montante)
			index = i;
	printf("Cliente com saldo mais elevado:\n");
	escreve_info(tab[index]);
}

cliente* adiciona_cliente(cliente *tab, int* n){
	cliente *aux;

	aux = realloc(tab, sizeof(cliente) * (*n+1));
	if(aux != NULL){
		tab = aux;
		tab[*n] = obtem_info();
		(*n)++;
	}
	return tab;
}

cliente* elimina_cliente(cliente *tab, int *n){
	char st[100];
	int i;
	cliente *aux, t;

	printf("Nº de conta do cliente a eliminar: ");
	scanf(" %s", st);

	for(i=0; i<*n && strcmp(st, tab[i].nconta)!=0; i++);

	if(i==*n){
 		printf("Cliente não existe\n");
		return tab;
	}
	else if(*n==1){
		free(tab);
		*n=0;
		return NULL;
	}
	else{
		t = tab[i];
		tab[i] = tab[*n-1];
		aux = realloc(tab, sizeof(cliente) * (*n-1));
		if(aux!=NULL){
			tab = aux;
			(*n)--;
		}
		else
			tab[i] = t;
		return tab;
	}
}

int menu(){
	int i;

	puts("1 - Adiciona Cliente");
	puts("2 - Elimina Cliente");
	puts("3 - Lista Clientes");
	puts("4 - Mostra Mais Rico");
	puts("5 - Terminar");
	puts("Escolha uma opção: ");

	do{
		scanf("%d", &i);
	}while(i<1 || i>5);
	return i;
}

void guardaDadosDin(cliente *b, int total){
	FILE *f;
	int i;

	f = fopen("bancoD.dat", "wb");
        
	if(f==NULL){
		printf("Erro no acesso ao ficheiro\n");
		return;
	}
        
	fwrite(&total, sizeof(int), 1, f);
	fwrite(b, sizeof(cliente), total, f);
	fclose(f);
}

cliente* lerDadosDin(int *total){
    FILE *f;
    cliente *p;
    
    f = fopen("bancoD.dat", "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n");
        *total = 0;
        return NULL;
    }
    fread(total, sizeof(int), 1, f);
    
    p = malloc(sizeof(cliente) * *total);
    if(p == NULL){
        printf("Erro na Alocacao\n");
        fclose(f);
        *total = 0;
        return NULL;
    }
    
    fread(p, sizeof(cliente), *total, f);
    
    fclose(f);
    return p;
}

int main(){
	cliente *banco = NULL;
	int i, total=0;
        
        banco = lerDadosDin(&total);
                
	do {
		i = menu();
		switch(i){
			case 1: banco = adiciona_cliente(banco,&total); break;
			case 2: banco = elimina_cliente(banco,&total); break;
			case 3: escreve_todos(banco,total); break;
			case 4: procura_mais_rico(banco, total); break;
		}
	}while(i != 5);
        
        guardaDadosDin(banco, total);
        
        free(banco);
	return 0;
}
