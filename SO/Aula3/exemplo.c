#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(int argc, char ** argv, char ** envp) { 
int main(int argc, char ** argv) { // com o environ/getenv, não é preciso receber por argumento envp
        //argv é um vetor de string que contem os argumentos de entrada
        //exemplo ./teste abc dev ---> argv[0]-teste    argv[1]-abc     argv[2]-dev
        //argc é o numero de elementos -> 3
        // envp contem as variaveis ambiente -> vector de strings


        //exemplo com envp
        /*int i = 0;
        char *p=envp[0];
        while(p != NULL) { 
                if(strstr(envp[i],argv[1])) // apenas para apresentar a variavel
                        printf("%s\n", envp[i]);
                p=envp[++i];
        }*/

	//exemplo com environ
	int i = 0;
	extern char ** environ;

	while(environ[i] != NULL) {
		if (strstr(environ[i], argv[1]))
			printf("%s\n", environ[i]); 
		++i;
	}


	//exemplo com getenv
        //printf("[%s = %s]\n", argv[1], getenv(argv[1])); 
        
	return 0;
}
