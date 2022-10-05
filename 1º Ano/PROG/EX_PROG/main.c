#include <stdio.h>
#include <stdlib.h>

typedef struct tipoA cliente, *pCliente;
typedef struct tipoB acesso, *pAcesso;

typedef struct {int h, m;} hora;

struct tipoA{
    int id;         // Identificador único
    int contador;   // Número de utilizações nesse dia
    pAcesso lista;  // Ponteiro para a lista de acessos
    pCliente prox;  // Ponteiro para o próximo cliente
};

struct tipoB{
    hora in, out;   // Horas de entrada e saída
    pAcesso prox;
};

void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso auxA;

    while(p != NULL){
        while(p->lista != NULL){
            auxA = p->lista;
            p->lista = p->lista->prox;
            free(auxA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);
    }
}

void escreve_tudo(pCliente p)
{
    pAcesso aux;
    while(p != NULL)
    {
        printf("ID: %d\tAcessos: %d\n",
               p->id, p->contador);
        aux = p->lista;
        while(aux != NULL)
        {
            printf("In: %d\t%d\tOut: %d\t%d\n", aux->in.h, aux->in.m, aux->out.h, aux->out.m);
            aux = aux->prox;
        }
        p = p->prox;
    }
}

int Conta_Clientes(pCliente p)
{
    int contador=0;
    pAcesso aux;

     while(p != NULL){
        aux = p->lista;
        while(aux != NULL){
            if (aux->out.h==-1 && aux->out.m==-1)
                contador++;
            aux = aux->prox;
        }
        p = p->prox;

    }
    return contador;

}
int Melhor_Cliente(pCliente p)
{
    pAcesso aux;
    int melhor_cliente_id;
    int minutos_total_max=0, minutos_total = 0;

     while(p != NULL){
        aux = p->lista;

        while(aux != NULL){

            if (!(aux->out.h==-1 && aux->out.m==-1))
                minutos_total += (aux->out.h*60+aux->out.m)-(aux->in.h*60+aux->in.m);
            aux = aux->prox;
        }
        if(minutos_total > minutos_total_max)
        {
            melhor_cliente_id = p->id;
            minutos_total_max = minutos_total;
        }

        minutos_total = 0;
        p = p->prox;

    }
    if (minutos_total_max==0)
        return -1;
    return melhor_cliente_id;

}


pCliente criaExemploED(){
    int totC = 3, i, j, k=-1;
    cliente a[] = {{17,1, NULL, NULL},{22,3,NULL,NULL},{13, 2,NULL,NULL}};
    acesso b[] = {{{10,50},{-1,-1},NULL}, {{9,11},{9,12},NULL},{{10,5},{12,0},NULL},{{14,33},{-1,-1},NULL},{{10,20},{11,52},NULL}, {{14,30},{17,2},NULL}};

    pCliente lista = NULL, novoC;
    pAcesso novoA;

    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }
    }
    return lista;
}

pCliente elimina_cliente(pCliente p)
{
    pCliente auxC, auxCant;
    pAcesso auxA, auxAant;

    auxC = p;
    auxCant = NULL;

    while(auxC != NULL)
    {
        //Para cada elemento da lista principal avalia os elementos da lista secundária
        auxA = auxC->lista;
        auxAant = NULL;
        while(auxA!= NULL && !(auxA->out.h==-1 && auxA->out.m==-1))
        {
            auxAant = auxA;
            auxA = auxA->prox;
        }
        if(auxA == NULL) //Não encontrou nenhum elemento em aberto na lista secundária
        {
            auxCant = auxC;
            auxC = auxC->prox;
        }
        else if(auxAant == NULL) //a lista secundária só tem um acesso e está em aberto - por isso não chega a entrar no while
        {
            auxC->contador--;
            auxC->lista=NULL;
            free(auxA);
            //tenho também de eliminar o nó da lista principal porque não tem acessos
            if(auxCant == NULL) //se o elemento da lista principal for o primeiro da lista
                p = auxC->prox;
            else//senão for o primeiro da lista
                auxCant->prox = auxC->prox;
            free(auxC);
        }
        else //caso geral
        {
            auxAant->prox = auxA->prox;
            free(auxA);
            auxC->contador--;//atualiza contador
            auxCant = auxC;//passa para o próximo elemento da lista principal
            auxC = auxC->prox;
        }
    }
    return p;
}

pCliente acessoParque(pCliente p, int id, hora x)
{
    pAcesso auxA, novoA;
    pCliente auxC = p;

     while(auxC != NULL && auxC->id != id)
        auxC = auxC->prox;

        if(auxC==NULL)
        {
            printf("\nEsse cliente nao existe");
            return p;
        }
        auxA = auxC->lista;
        while(auxA->prox != NULL)//vou até ao último elemento da lista
            auxA = auxA->prox;

        if(auxA->out.h != -1 && auxA->out.m != -1)
        {
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL)
                {
                    libertaTudo(p);
                    return NULL;
                }
            novoA->in.h = x.h;
            novoA->in.m = x.m;
            novoA->out.h = -1;
            novoA->out.m = -1;
            novoA->prox = NULL;
            auxA->prox = novoA;
            auxC->contador++;
        }
        else
        {
            auxA->out.h = x.h;
            auxA->out.m = x.m;
        }
        return p;
}



int main(){

    pCliente lista = criaExemploED();
    hora x;

    x.h=18;
    x.m=00;
    escreve_tudo(lista);
    printf("\n");


    printf("\nO numero de clientes que se sencontra no parque e: %d", Conta_Clientes(lista));
    printf("\n");
    printf("\nO cliente que esteve mais tempo no parque tem o ID: %d", Melhor_Cliente(lista));
    printf("\n");


    lista = acessoParque(lista, 13, x);
    escreve_tudo(lista);
    printf("\n");
    lista = elimina_cliente(lista);
    escreve_tudo(lista);
    libertaTudo(lista);

    return 0;
}
