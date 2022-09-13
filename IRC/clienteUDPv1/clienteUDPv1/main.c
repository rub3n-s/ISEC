//
//  main.c
//  clienteUDPv1
//
//  Created by rsantos on 28/10/2020.
//  Copyright © 2020 Rúben Santos. All rights reserved.
//

#include <stdio.h>

#define SERV_UDP_PORT 6000

#define BUFFERSIZE 4096

void Abort (char * msg);
int main(int argc, const char * argv[]) {
    SOCKET sockfd;
    int msg_len, iResult;
    struct sockaddr_in serv_addr;
    char buffer[BUFFERSIZE];
    WSADATA wsaData;
    
    
    //=============================== TESTA A SINTAXE ===============================
    if (argc != 2) {
        fprintf(stderr,"Sintaxe: %s frase_a_enviar\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        
    }
    return 0;
}
