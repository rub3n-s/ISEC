#include <stdio.h>
#include <winsock.h>
#include "..\\util\\util.h"

void processClient(LPVOID param);

void main(int argc, char **argv)
{
	SOCKET s, cliSocket;
	WSADATA wsaData;
	int iResult, len;
	struct sockaddr_in serv_addr, cli_addr;
	SECURITY_ATTRIBUTES sa;
	DWORD thread_id;

	if(argc != 2){
		printf("Usage: %s  <server_port>\n", argv[0]);
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

	if((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR){
		printf("Unable to create socket (error: %d)!\n", WSAGetLastError());
		getchar();
		exit(1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr))==SOCKET_ERROR){
		printf("Unable to bind socket to port %s (error: %d)!\n", argv[1], WSAGetLastError());
		closesocket(s);
		getchar();
		exit(1);
	}

	listen(s, 5);

	while(1){

		printf("Waiting for file download request...\n");

		len = sizeof(cli_addr);

		if((cliSocket = accept(s, (struct sockaddr *)&cli_addr, &len))==SOCKET_ERROR){
			printf("Unable to accept new connection (error: %d)!\n", WSAGetLastError());
			closesocket(s);
			getchar();
			exit(1);
		}

		printf("Connection from %s:%d accepted.\n", inet_ntoa(cli_addr.sin_addr),
					ntohs(cli_addr.sin_port));

		
		sa.nLength=sizeof(sa);
		sa.lpSecurityDescriptor=NULL;

		if(CreateThread(&sa,0 ,(LPTHREAD_START_ROUTINE)processClient, (LPVOID)cliSocket, (DWORD)0, &thread_id)==NULL){
			printf("Cannot start new slave thread (error: %d)!\n", GetLastError());			
			closesocket(cliSocket);
		}

		printf("New slave thread started (id: %d).\n", thread_id);			
	}
}

void processClient(LPVOID param)
{
	SOCKET s;
	int nbytes, chunkCount;
	unsigned currentThreadId;
	char request[MAX_MSG_SIZE];
	char opCode[MAX_MSG_SIZE], fileName[MAX_MSG_SIZE];
	char buffer[CHUNK_SIZE];
	FILE *f;

	s = (SOCKET)param;
	currentThreadId = GetCurrentThreadId();

	if((nbytes = readLine(s, request, MAX_MSG_SIZE)) == SOCKET_ERROR){
		printf("<%d> Unable to receive request (error: %d)!\n", currentThreadId, WSAGetLastError());
		closesocket(s);
		return;
	}

	request[nbytes] = 0;

	if(sscanf(request, "%s %s", opCode, fileName)!=2){
		printf("<%d> Request \"%s\" with wrong format!\n", currentThreadId, request);
		closesocket(s);
		return;
	}

	if(strcmp(opCode, GET_FILE)!=0){
		printf("<%d> Unexpected request \"%s\"!\n", currentThreadId, opCode);
		closesocket(s);
		return;
	}

	if((f=fopen(fileName, "rb"))==NULL){
		printf("<%d> Unable to open file \"%s\"!\n", currentThreadId, fileName);
		perror("System error");
		closesocket(s);
		return;
	}

	chunkCount=0;

	while(!feof(f)){

		chunkCount++;

		nbytes = fread_s(buffer, CHUNK_SIZE, 1, CHUNK_SIZE, f);

		if(!ferror(f)){
			if(writeN(s, buffer, nbytes) != nbytes){
				printf("<%d> Unable to transmit file chunk n. %d (error: %d)!\n", currentThreadId, chunkCount, WSAGetLastError());
				fclose(f);
				closesocket(s);
				return;
			}

			//printf("<%d> File chunk n. %d transmitted with %d bytes.\n", currentThreadId, chunkCount, nbytes);
		}else{
			printf("<%d> Error reading chunk n. %d of file \"%s\"!\n", currentThreadId, chunkCount, fileName);
			perror("System error");
			fclose(f);
			closesocket(s);
			return;
		}

	} //while

	fclose(f);
	closesocket(s);
}

