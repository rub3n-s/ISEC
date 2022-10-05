#include <stdio.h>
#include <stdlib.h>

typedef struct med_sum{
    float media;
    int soma;
} MedSum;

void mostra_numeros(char * nomefich) {
    int num;

    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;
    }

    while (fread(&num,sizeof(int),1,f)==1)
        printf("%3d\n",num);

    fclose(f);
}



MedSum calcula_soma_media(char * nomefich)
{
    MedSum t;
    int num,i=0;
    t.soma=0;
    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;}
    fread(&num, sizeof(int), 1, f);
    while (feof(f) == 0)
    {   t.soma+=num;
        i++;
        fread(&num, sizeof(num), 1, f);}
        t.media=t.soma/(float)i;
    fclose(f);
    return t;

}

int* criaVetor(char *nomeFich, int *tam)
{
    FILE *f;
    int *b = NULL,num, *aux;
    f = fopen(nomeFich,"rb");
    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro\n");
        (*tam)=0;
        return b;
    }
    /*b = malloc(sizeof(int)*(*tam+1));
    if(b == NULL)
    {
        fclose(f);
        (*tam)=0;
        return b;
    }*/
    //fread(&num, sizeof(int), 1, f);
    //b[(*tam)] = num;
    //(*tam)++;
    while (fread(&num,sizeof(int),1,f)==1)
    {
        if(num%2==0)
        {
            aux = realloc(b,sizeof(int) * (*tam+1));
            //If pointer passed to realloc is null, then it will behave exactly like malloc
            if(aux == NULL)
            {       // realocação falhou
                printf("Falhou realocacao. Mantem tamanho\n");
                (*tam)=0;
                return NULL;
            }
            else
            {
                b = aux;
                b[(*tam)] = num;
            }
            (*tam)++;
        }

    }
    fclose(f);
    return b;
}

void cria_ficheiro(char *fich,char *fichmedsup, char *fichmedinf)
{
    FILE *f, *g, *t;
    float media;
    int num;
    if ((f=fopen(fich,"rb"))==NULL) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",fich);
        return 0;
    }
    if ((g=fopen(fichmedsup,"wb"))==NULL) {
        fclose(f);
        fprintf(stderr,"Erro a criar o ficheiro %s\n",fichmedsup);
        return;
    }

    if ((t=fopen(fichmedinf,"wb"))==NULL) {
        fclose(f);
        fclose(g);
        fprintf(stderr,"Erro a criar o ficheiro %s\n",fichmedinf);
        return;
    }
    media = calcula_soma_media(fich).media;
    while (fread(&num,sizeof(int),1,f)==1)
    {
        if (num >=media)
            fwrite(&num,sizeof(int),1,g);
        else
            fwrite(&num,sizeof(int),1,t);
    }
    fclose(f);
    fclose(g);
    fclose(t);
}
int main(int argc, char** argv) {

    char *fich = "valoresEx2.bin";
    char *fichsupmed = "valEx2SupMed.bin";
    char *fichinfmed = "valEx2InfMed.bin";
    MedSum t;
    int* b = NULL;
    int tam=0,i;

    t = calcula_soma_media(fich);

    mostra_numeros(fich);

    printf("\nA soma dos valores e %d ",t.soma);
    printf("\nA media dos valores e %.2f ",t.media);

    b=criaVetor(fich,&tam);
    printf("\nO vetor criado tem %d valores ",tam);
    for(int i=0;i<tam;i++)
        printf("\n%3d",b[i]);

    cria_ficheiro(fich,fichsupmed,fichinfmed);

    printf("\nValores superiores ou iguais a media: \n");
    mostra_numeros(fichsupmed);

    printf("\nValores inferiores a media: \n");
    mostra_numeros(fichinfmed);

    free(b);

    return (EXIT_SUCCESS);
}
