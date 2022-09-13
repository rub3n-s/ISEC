#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define PROB 0.0005

// Gera um vizinho
// Parametros: solucao actual, vizinho, numero de vertices
//swap two vertices
void gera_vizinho(int a[], int b[], int n)
{
    int i, p1, p2;

    for(i=0; i<n; i++)
        b[i]=a[i];
	// Encontra posicao com valor 0
    do
        p1=random_l_h(0, n-1);
    while(b[p1] != 0);
	// Encontra posicao com valor 0
    do
        p2=random_l_h(0, n-1);
    while(b[p2] != 1);
	// Troca
    b[p1] = 1;
    b[p2] = 0;
}

// Trepa colinas first-choice
// Parametros: solucao, matriz de adjacencias, numero de vertices e numero de iteracoes
// Devolve o custo da melhor solucao encontrada
int trepa_colinas(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;
    //int *nova_sol, *nova_sol2, custo, custo_viz, custo_viz2, i; //4.3 - novas vizinhanças (steepest-ascent, melhor primeiro)

	nova_sol = malloc(sizeof(int)*vert);
    //nova_sol2 = malloc(sizeof(int)*vert); /* 4.3 */
    if(nova_sol == NULL /*|| nova_sol2 == NULL*/)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);
    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		gera_vizinho(sol, nova_sol, vert);
        //gera_vizinho(sol, nova_sol2, vert); /* 4.3 */

        // Avalia vizinho
		custo_viz = calcula_fit(nova_sol, mat, vert);
        //custo_viz2 = calcula_fit(nova_sol2, mat, vert); /* 4.3 */

        // Aceita vizinho se o custo diminuir (problema de minimizacao)
        //if(custo_viz < custo) //  com vizinhança 1
        /*if(custo_viz <= custo)  //  vizinhança 1 e aceitando soluções de custo igual
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }*/

        /*if (custo_viz < custo_viz2) {     // 4.3
            if (custo_viz < custo) {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        } else {
            if (custo_viz2 < custo) {
                substitui(sol, nova_sol2, vert);
                custo = custo_viz2;
            }
        } */

        if (custo_viz <= custo) {       // probabilistico   -   4.4
            //solução melhor ou igual e sempre aceite
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        } else {    // solução pior tambem pode ser aceite
            if (rand_01() < PROB) {   // isto ajuda a fugir a maximos locais
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
    }

    free(nova_sol);
    //free(nova_sol2); //   4.3
    return custo;
}

// recristalização
// Parametros: solucao, matriz de adjacencias, numero de vertices e numero de iteracoes
// Devolve o custo da melhor solucao encontrada
int esfriamento(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, *nova_sol2, custo, custo_viz, custo_viz2, i;
    float temp, erro, prob_aceitar, max = 1, min = 0.05; // temperaturas inicial e final

    nova_sol = malloc(sizeof(int)*vert);
    nova_sol2 = malloc(sizeof(int)*vert); /* vizinhança 2 */
    if(nova_sol == NULL || nova_sol2 == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);

    temp = max;

    while(temp > min) {     // printf("Temperatura: num=%i, %f\n", num_iter,temp);
        temp -= (max-min) / (float)num_iter; // descer a temperatura

        // Gera vizinho
        gera_vizinho(sol, nova_sol, vert);
        gera_vizinho(sol, nova_sol2, vert); /* vizinhança 2 */

        // Avalia vizinho
        custo_viz = calcula_fit(nova_sol, mat, vert);
        custo_viz2 = calcula_fit(nova_sol2, mat, vert); /* vizinhança 2 */

        if (custo_viz <= custo_viz2) {     /* vizinhança 2 */
           if (custo_viz < custo) {
               substitui(sol, nova_sol, vert);
               custo = custo_viz;
           }
       } else {
           if (custo_viz2 <= custo) {
               substitui(sol, nova_sol2, vert);
               custo = custo_viz2;
           }
       }

        /*if (custo_viz <= custo) {
            substitui(sol, nova_sol,vert);
            custo = custo_viz;
        } else {
            erro = custo-custo_viz;
            // aceitar com determinada probabilidade - calcular probabilidade usando a funcao exp()s
            //prob_aceitar =  exp(erro/temp);
            if (rand_01() < exp(erro/temp)) {   // isto ajuda a fugir a maximos locais
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }*/
    }

    free(nova_sol);
    free(nova_sol2);    /* vizinhança 2 */
    return custo;
}