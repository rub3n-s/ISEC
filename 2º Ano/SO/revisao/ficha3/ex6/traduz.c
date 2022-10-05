#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char palavra[20];
    char op;
    
    
    do {
        fflush(stdin);
        printf("traduzir: ");
        scanf("%s", palavra);
        printf("opcao: ");
        scanf("%s",&op);
        
        int id = fork();
        if (id == 0) {
            if (op == 'i')
                execl("./ding","./ding",palavra);
            else if (op == 'f')  
                execl("./dfran","./dfran",palavra);
        }
        sleep(1);
    } while(op != 'x');
    
    return 0;
}