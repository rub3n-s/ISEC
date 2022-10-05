#include <stdio.h>
#include <string.h>

#define N 4

void verifica(char *s, int *a){
    int i;
	
    printf("\nNome: %s\nNumeros: ", s);
    for(i=0; i<5; i++)
	printf("%d\t", a[i]);
    printf("\nEstrelas: ");
    for(i=5; i<7; i++)
	printf("%d\t", a[i]);
}

void euro(){
    FILE *f;
    int i, a[7];
    char st[100];
	
    f = fopen("dados.txt", "r");
    if(f == NULL)
	printf("Erro no acesso ao ficheiro\n");
    else{
	while(fscanf(f, " %99[^\n]", st) != EOF){	
            
            
            for(i=0; i<7; i++)
                fscanf(f, "%d", &a[i]);
            verifica(st, a);
	}
        fclose(f);
    }
}

int mainTT(){
 
    
    euro();
    
    return 0;
}


void printMatQuad(int dim, float a[][dim]){
    int i, j;
    
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++)
            printf("%.3f\t", a[i][j]);
        printf("\n");
    }          
}

void leMatTxt(char *nome, int dim, float a[][dim]){
    FILE *f;
    int x, y;
    float v;
    
    f = fopen(nome, "r");
    if(f == NULL){
        printf("erro");
        return;
    }
    while(fscanf(f, "%d %d %f", &x, &y, &v) != EOF){
        if(x>=0 && x<dim && y>=0 && y<dim)
            a[x][y] = v;
    }
    fclose(f);
}


int main(){
    float mat[N][N] = {0.0};
    
    leMatTxt("mat.txt", N, mat);
    printMatQuad(N, mat);
    
    return 0;
}

