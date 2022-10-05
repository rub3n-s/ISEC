#include <stdio.h>
#include <string.h>

typedef struct dados cliente;

struct dados{
    char nome[100];
    char nconta[15];
    int montante;
};

void escreve_info(cliente a);

void listarFicheiro(char *nome){
    FILE *f;
    cliente c;

    f = fopen(nome, "rb");
    if(f==NULL)
        return;

    while(fread(&c, sizeof(cliente), 1, f) == 1)
        escreve_info(c);		
    fclose(f);
}



int atualizaSaldoV1(char *nome, char *conta, int valor){
    FILE *f, *g;
    cliente c;
    int flag = 0;
    
    f = fopen(nome, "rb");
    if(f == NULL) return 0;
    g = fopen("temp.dat", "wb"); 
    if(g == NULL){fclose(f); return 0;}
    
    while(fread(&c, sizeof(cliente), 1, f) == 1){
        if(strcmp(conta, c.nconta) == 0){
            c.montante += valor;
            flag = 1;
        }
        fwrite(&c, sizeof(cliente), 1, g);
    } 
    fclose(f);
    fclose(g);
    remove(nome);
    rename("temp.dat", nome);
    return flag;
}


int main(){

    FILE *f;
    cliente c;
    
    listarFicheiro("bancoX.dat");


    f = fopen("bancoX.dat", "rb");
    
    fseek(f, 0, SEEK_END);
    
    printf("Tamanho do Ficheiro: %d\n", ftell(f));
    printf("Tamanho de um cliente: %d\n", sizeof(cliente));
    
    printf("Numero de clientes: %d\n", ftell(f)/sizeof(cliente));
    
    /*
    fseek(f, 3*sizeof(cliente), SEEK_SET);
    fread(&c, sizeof(cliente), 1, f);
    fseek(f, -2*sizeof(cliente), SEEK_CUR);
   
    fread(&c, sizeof(cliente), 1, f);
    printf("Nome: %s\n", c.nome);
    */
    
    fclose(f);


}
    
    





int mainXX(){

    listarFicheiro("bancoX.dat");

    printf("Res: %d\n", atualizaSaldoV1("bancoX.dat", "C", -20));
    
    printf("\nDepois: \n");
    listarFicheiro("bancoX.dat");
       
    return 0;
}
