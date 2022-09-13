#include <stdio.h>
#include <winsock.h>
#include "..\\util\\util.h"

#define TIMEOUT 60000 //mseconds

void main(int argc, char **argv)
{
	SOCKET s;
	WSADATA wsaData;

	int iResult, nbytes;
	struct sockaddr_in serv_addr;
	struct hostent *serverName;
	char request[MAX_MSG_SIZE], buffer[CHUNK_SIZE];
	DWORD timeout;
	FILE *f;

	if(argc != 5){
		printf("Usage: %s <file_server_addr> <file_server_port> <file_to_download> <file_saving_name>\n", argv[0]);
		getchar();
		exit(1);
	}

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d!\n", iResult);
		getchar();
		exit(1);
	}
		
	if((f=fopen(argv[4], "wb"))==NULL){
		printf("Unable to create file \"%s\"!\n", argv[4]);
		perror("System error");
		exit(1);
	}

	if((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR){
		printf("Unable to create socket (error: %d)!\n", WSAGetLastError());
		getchar();
		fclose(f);
		exit(1);
	}

	timeout = TIMEOUT;
	
	if(setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, 
						sizeof(timeout))==SOCKET_ERROR){
		printf("Unable to set timeout (error: %d)!\n", WSAGetLastError());
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(serv_addr.sin_addr.s_addr == INADDR_NONE &&
							strcmp(argv[1], "255.255.255.255")!=0){
		if((serverName = gethostbyname(argv[1])) == NULL){
			printf("Unknown %s host (error: %d)\n", argv[1], WSAGetLastError());
			closesocket(s);
			getchar();
			exit(1);
		}

		memcpy(&serv_addr.sin_addr, serverName->h_addr_list[0], serverName->h_length);
		printf("Host %s has ip address %s \n", argv[1], inet_ntoa(serv_addr.sin_addr));
	}

	if(connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR){
			printf("Unable to connect to server (error: %d)!\n", WSAGetLastError());
			fclose(f);
			closesocket(s);
			getchar();
			exit(1);
	}

	sprintf(request, "%s %s\n", GET_FILE, argv[3]);
	nbytes = strlen(request);

	if(writeN(s, request, nbytes) != nbytes){
		printf("Unable to send file request \"%s\" (error: %d)\n", request, WSAGetLastError());
		fclose(f);
		closesocket(s);
		getchar();
		exit(1);
	}
	
	while((nbytes = recv(s, buffer, CHUNK_SIZE, 0)) > 0){

		nbytes = fwrite(buffer, 1, nbytes, f);

		if(ferror(f)){
			printf("Unable to write current file chunk!\n");
			perror("System error");
			fclose(f);
			closesocket(s);
			exit(1);
		}
			
	}

	if(nbytes == SOCKET_ERROR){		
		
		if(WSAGetLastError()==WSAETIMEDOUT){
			printf("Timeout while waiting for next file chunk!\n");
		}else{
			printf("Error on socket while waiting for next file chunk (error: %d)!\n", WSAGetLastError());
		}

		printf("Local file \"%s\" is probably incomplete...\n", argv[4]);
	
	}else{

		printf("Download of remote file \"%s\" to local file \"%s\" is complete.\n", argv[3], argv[4]);
	
	}

	fclose(f);
	closesocket(s);
	getchar();
	exit(0);
}