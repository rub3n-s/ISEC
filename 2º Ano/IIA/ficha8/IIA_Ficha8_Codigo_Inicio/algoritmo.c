#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "utils.h"
#define PROB 0.0005

// Preenche uma estrutura com os progenitores da pr�xima gera��o, de acordo com o resultados do torneio binario (tamanho de torneio: 2)
// Par�metros de entrada: popula��o actual (pop), estrutura com par�metros (d) e popula��o de pais a encher
void tournament(pchrom pop, struct info d, pchrom parents)
{
	int i, x1, x2;

	// Realiza popsize torneios
	for(i=0; i<d.popsize;i++)
	{
		x1 = random_l_h(0, d.popsize-1);
		do
			x2 = random_l_h(0, d.popsize-1);
		while(x1==x2);
		if(pop[x1].fitness > pop[x2].fitness)		// Problema de maximizacao
			parents[i]=pop[x1];
		else
			parents[i]=pop[x2];
	}


    //--------------------- selecao com diferente tamanho de torneio
//    int i, temp, x1, x2;
//
//    // Realiza popsize torneios
//    for(i=0; i<d.popsize;i++)
//    {
//        x1 = random_l_h(0, d.popsize-1);
//        do
//            x2 = random_l_h(0, d.popsize-1);
//        while(x1==x2);
//        if(pop[x1].fitness > pop[x2].fitness)		// Problema de maximizacao
//            parents[i]=pop[x1];
//        else
//            parents[i]=pop[x2];
//    }
}

// Operadores geneticos a usar na gera��o dos filhos
// Par�metros de entrada: estrutura com os pais (parents), estrutura com par�metros (d), estrutura que guardar� os descendentes (offspring)
void genetic_operators(pchrom parents, struct info d, pchrom offspring)
{
    // Recombina��o com um ponto de corte
	crossover(parents, d, offspring);
	// Muta��o bin�ria
	mutation(offspring, d);
}

// Preenche o vector descendentes com o resultado das opera��es de recombina��o
// Par�metros de entrada: estrutura com os pais (parents), estrutura com par�metros (d), estrutura que guardar� os descendentes (offspring)
void crossover(pchrom parents, struct info d, pchrom offspring)
{
//	int i, j, point;
//
//	for (i=0; i<d.popsize; i+=2)
//	{
//		if (rand_01() < d.pr)
//		{
//			point = random_l_h(0, d.numGenes-1);
//			for (j=0; j<point; j++)
//			{
//				offspring[i].p[j] = parents[i].p[j];
//				offspring[i+1].p[j] = parents[i+1].p[j];
//			}
//			for (j=point; j<d.numGenes; j++)
//			{
//				offspring[i].p[j]= parents[i+1].p[j];
//				offspring[i+1].p[j] = parents[i].p[j];
//			}
//		}
//		else
//		{
//			offspring[i] = parents[i];
//			offspring[i+1] = parents[i+1];
//		}
//	}
//      A = 000000, B = 111111   =>  AB1 = 000111, AB2 = 111000

    //---------- com dois pontos de corte ----------
//    int i, j, point, point2;
//
//    for (i=0; i<d.popsize; i+=2)
//    {
//        if (rand_01() < d.pr)
//        {
//            point = random_l_h(0, d.numGenes-2);        // d.numGenes - 2
//            point2 = random_l_h(0, d.numGenes-1);
//            for (j=0; j<point; j++)
//            {
//                offspring[i].p[j] = parents[i].p[j];
//                offspring[i+1].p[j] = parents[i+1].p[j];
//            }
//            for ( ; j < point2; j++) { // copiar genes do ponto 1 ao ponto 2
//                offspring[i].p[j] = parents[i+1].p[j];
//                offspring[i+1].p[j] = parents[i].p[j];
//            }
//            for (j=point; j<d.numGenes; j++)
//            {
//                offspring[i].p[j]= parents[i+1].p[j];
//                offspring[i+1].p[j] = parents[i].p[j];
//            }
//
//            // A=000000, B=111111   =>    AB1 = 001100, AB2 = 110011
//        }
//        else
//        {
//            offspring[i] = parents[i];
//            offspring[i+1] = parents[i+1];
//        }
//    }


    //---------- recombinação uniforme ----------

    int i, j, point, point2;

    for (i=0; i<d.popsize; i+=2)
    {
        if (rand_01() < d.pr) {
            for (j = 0; j < d.numGenes; j++) {
                if (rand_01() < 0.5)    // Escolher se gene vem do pai ou da mãe
                {
                    offspring[i].p[j] = parents[i].p[j];
                    offspring[i+1].p[j] = parents[i+1].p[j];
                }
                else
                {
                    offspring[i].p[j] = parents[i+1].p[j];
                    offspring[i+1].p[j] = parents[i].p[j];
                }
            }
        } else {
            offspring[i] = parents[i];
            offspring[i+1] = parents[i+1];
        }
    }
}

// Muta��o bin�ria com v�rios pontos de muta��o
// Par�metros de entrada: estrutura com os descendentes (offspring) e estrutura com par�metros (d)
void mutation(pchrom offspring, struct info d)
{
	int i, j;

	for (i=0; i<d.popsize; i++)
		for (j=0; j<d.numGenes; j++)
			if (rand_01() < d.pm)
				offspring[i].p[j] = !(offspring[i].p[j]);   // aleatoriamente nega um gene e troca
}

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

int calcula_fit(int a[], int *mat, int vert)
{
    int total=0;
    int i, j;

    for(i=0; i<vert; i++)
        if(a[i]==0)
        {
            for(j=0; j<vert;j++)
                if(a[j]==1 && *(mat+i*vert+j)==1)
                    total++;
        }
    return total;
}