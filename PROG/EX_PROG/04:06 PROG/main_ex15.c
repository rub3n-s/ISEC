#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct concorrente no, *pno;

struct concorrente{
	char nome[200];		/* nome do concorrente */
	int id;				/* n.� de aluno: identificador �nico */
	float analise;		/* n�vel de �lcool no sangue */
	pno prox;
};


// Funcao para criar a estrutura dinamica com base na informacao do ficheiro de texto
void cria_listas(pno tab[], char *n1)
{
	FILE *f;
	pno novo;
	int i, x, y;

	f = fopen(n1, "r");
	if(f==NULL)
	{
		printf("Erro no acesso ao ficheiro\n");
		return NULL;
	}
	while(fscanf(f, " %d %d", &x, &y) == 2)
	{
		for(i=0; i<y; i++)
		{
			novo = malloc(sizeof(no));
			if(novo == NULL)
			{
				printf("Erro na alocacao de memoria\n");
				fclose(f);
				return;
			}
			fscanf(f, " %d %f %[^\n]", &novo->id, &novo->analise, novo->nome);
			novo->prox = tab[x];
			tab[x] = novo;
		}
	}
	fclose(f);
}

void mostra_listas(pno tab[])
{

	pno aux;
	int i = 0, classificado=0;

	for(i=0; i<N; i++)
    {
        aux = tab[i];
        classificado=0;
        printf("\nProva %d: ", i+1);
        while(aux!=NULL)
        {
            classificado++;
            printf("\nClassificacao: %d Lugar\tId Atleta: %d\tNome Atleta: %s",classificado, aux->id,aux->nome);
            aux=aux->prox;

        }
    }

}

pno cria_prenche(pno dados)
{
    pno novo = malloc(sizeof(no));
    if(novo == NULL)
        return NULL;
    *novo = *dados;
    novo->prox = NULL;
    return novo;
}

pno Cria_Lista_Final(pno tab[])
{
    pno p = NULL;
    pno novo, aux1, aux2;
    int pertence_a_todas =1;
    int i=0;
    aux1 = tab[0];
    while(aux1!=NULL)
    {
        pertence_a_todas =1;
        for(i=1;i<N;i++)
        {
            aux2=tab[i];
            while(aux2!=NULL && aux2->id != aux1->id)
                aux2 = aux2->prox;
            if (aux2==NULL)//Não está nesta lista pode passar ao próximo elemento;
            {
                pertence_a_todas=0;
                break;
            }
        }
        if(pertence_a_todas)
        {
            novo = cria_prenche(aux1);
            novo->prox = p;
            p = novo;
        }
        aux1 = aux1->prox;
     }
return p;
}

void mostra_lista_todas_as_provas(pno p)
{
    while(p!=NULL)
    {

        printf("\nId Atleta: %d\tNome Atleta: %s",p->id,p->nome);
        p=p->prox;
    }
}

int Procura_ID_alcoolico(pno tab[])
{
    pno aux;
    int i;
    for(i=0;i<N;i++)
    {
        aux = tab[i];
        while(aux!=NULL)
        {
            if (aux->analise >=0.5)
                return aux->id;
            aux = aux->prox;
        }
    }
    return 0;
}


void elimina_alcool(pno tab[])
{
    pno aux, auxAnt;
    int i, id;

    id = Procura_ID_alcoolico(tab);
    printf("\n%ID = %d", id);
    while(id!=0)
    {
        for(i=0; i<N; i++)
        {
            aux = tab[i];
            auxAnt = NULL;

            while(aux!=NULL)
            {
                if(aux->id==id)
                {
                if(auxAnt==NULL)
                {
                    tab[i]=aux->prox;
                    free(aux);
                }
                else
                {
                    auxAnt-> prox= aux->prox;
                    free(aux);
                    aux = auxAnt;

                }
                }
                auxAnt = aux;//passa para o próximo elemento da lista principal
                aux = aux->prox;

            }
        }
        id = Procura_ID_alcoolico(tab);
        printf("\n%ID2 = %d", id);
    }


}

void liberta_listas(pno tab[])
{
    pno aux;
    for(int i=0;i<N;i++)
    {
        aux = tab[i];
        while(aux!=NULL)
        {
            tab[i] = aux->prox;
            free(aux);
            aux=tab[i];

        }
    }
}

int main()
{
	// Declaracao do array de ponteiros
	pno tab[N] = {NULL};
	pno Atletastp = NULL;


	// Criar ED
	cria_listas(tab, "dados_15.txt");
	mostra_listas(tab);

	Atletastp = Cria_Lista_Final(tab);

	printf("\n\n\n----Lista de Atletas que participaram em todas as Provas: ");
	mostra_lista_todas_as_provas(Atletastp);

	elimina_alcool(tab);
	mostra_listas(tab);

    liberta_listas(tab);

    mostra_listas(tab);

        //mostra_listas(tab);
	// Continuar a partir daqui ...

	return 0;
}
