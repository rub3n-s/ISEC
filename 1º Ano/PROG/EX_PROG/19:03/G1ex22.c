#include <stdio.h>
#include <string.h>
#include<locale.h>

#define N	7


void escreve_sin(char *sin[][2], int tot_lin)
{
	int i;
	for (i=0; i<tot_lin; i++){
        printf("%s->%s",sin[i][0],sin[i][1]);
        printf("\n");
    }
}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{
	int i;
	for(i=0; i<tot_lin; i++)
    {

        if(stricmp(sin[i][0],p)==0)
        {
            //puts(sin[i][1]);
            return sin[i][1];
        }
    }
	return NULL;
}

void pesquisa_sinonimo_frase(char *sin[][2], int tot_lin)
{
	int i=0;
	char frase[50];
	int flag=0;
	printf("Introduza uma frase: ");
	gets(frase);
	for(i=0; i<tot_lin; i++)
    {
        if(strstr(frase,sin[i][0])!=NULL)
        {
            printf("%s->%s",sin[i][0],sin[i][1]);
            printf("\n");
            flag=1;
        }
    }
    if (!flag)
        printf("\nEsta frase não tem nenhuma palavra na lista de sinónimos");
}

int conta_palavras_repetidas(char *sin[][2], int tot_lin)
{
    int contador_palavras=0;
    int i, ii;
    for (i=0;i<tot_lin; i++)
    {
       for(ii=0; ii<tot_lin; ii++)
        if(strcmp(sin[i][0],sin[ii][1])==0)
        {
            contador_palavras++;
            break;
        }
    }
    return contador_palavras;
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	char palavra[50], *p;
	char *s[N][2] = {{"estranho", "bizarro"},
					 {"desconfiar", "suspeitar"},
				     {"vermelho", "encarnado"},
					 {"duvidar", "desconfiar"},
					 {"carro", "automovel"},
					 {"bizarro", "diferente"},
					 {"questionar", "desconfiar"}};


	escreve_sin(s, N);		// alinea 22.1

	printf("Palavra a pesquisar: ");
	scanf(" %s", palavra);

	p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2

	if(p == NULL)
		printf("A palavra %s não tem sinónimo conhecido\n", palavra);
	else
		printf("A palavra %s é sinónimo de %s\n", p, palavra);

    fflush(stdin);

	pesquisa_sinonimo_frase(s, N);
	printf("\n O número de palavras repetidas na lista de sinónimos é: %d", conta_palavras_repetidas(s,N));


	return 0;
}
