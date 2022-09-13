#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"
#include "math.h"
#include "utils.h"

// Calcula a qualidade de uma solu��o
// Par�metros de entrada: solu��o (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Par�metros de sa�da: qualidade da solu��o (se a capacidade for excedida devolve 0)
float eval_individual(int sol[], struct info d, int mat[][2], int *v)
{
	int     i, min;
	float   sum_weight, sum_profit, ro;

//	sum_weight = sum_profit = 0;
//	// Percorre todos os objectos
//	for (i=0; i < d.numGenes; i++)
//	{
//        // Verifica se o objecto i esta na mochila
//		if (sol[i] == 1)
//		{
//            // Actualiza o peso total
//			sum_weight += mat[i][0];
//            // Actualiza o lucro total
//			sum_profit += mat[i][1];
//		}
//	}
//	if (sum_weight > d.capacity)
//	{
//        // Solucao invalida
//		//*v = 0;
//		//return 0;
//
//        //penalizacao - em vez de devolver zero, devolve o profit penalizado
//        *v = 1;
//        ro = ceil(sum_profit/sum_weight);   //calcular penalização
//        return sum_profit - ro * (sum_weight - d.capacity); // penalizar
//	}
//	else
//	{
//        // Solucao valida
//		*v = 1;
//		return sum_profit;
//	}


    //=====================  reparação 1 -> aleatoria =====================
    do {
        sum_weight = sum_profit = 0;
        // Percorre todos os objectos
        for (i=0; i < d.numGenes; i++)
        {
            // Verifica se o objecto i esta na mochila
            if (sol[i] == 1)
            {
                // Actualiza o peso total
                sum_weight += mat[i][0];
                // Actualiza o lucro total
                sum_profit += mat[i][1];
            }
        }
        if (sum_weight > d.capacity)    // solução invalida
        {
            do {
                i = random_l_h(0,d.numGenes - 1);   // escolher o objeto
            } while(sol[i] == 0);
            sol[i] = 0; // retira lo
        }
    } while(sum_weight > d.capacity);

    *v = 1;
    return sum_profit;
    //===================== fim reparação 1 -> aleatoria =====================


    //=====================  reparação 2 -> aleatoria =====================
//    do {
//        sum_weight = sum_profit = 0;
//        // Percorre todos os objectos
//        for (i=0; i < d.numGenes; i++)
//        {
//            // Verifica se o objecto i esta na mochila
//            if (sol[i] == 1)
//            {
//                // Actualiza o peso total
//                sum_weight += mat[i][0];
//                // Actualiza o lucro total
//                sum_profit += mat[i][1];
//            }
//        }
//
//        if (sum_weight > d.capacity)    // solução invalida
//        {
//            for (i = 0; sol[i] == 0 && i < d.numGenes; i++) // procurar primeiro objeto na mochila
//                min = i;
//
//            for (; d.numGenes; i++) // procurar objeto menos valiaso na mochila
//                if (sol[i] == 1 && mat[i][1] < mat[min][1])
//                    min = i;
//            sol[min] = 0;   // retira lo
//        }
//    } while(sum_weight > d.capacity);
//
//    *v = 1;
//    return sum_profit;
    //===================== fim reparação 2 -> aleatoria =====================
}

// Avaliacao da popula��o
// Par�metros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Par�metros de sa�da: Preenche pop com os valores de fitness e de validade para cada solu��o
void evaluate(pchrom pop, struct info d, int mat[][2])
{
	int i;

	for (i=0; i<d.popsize; i++)
		pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
}