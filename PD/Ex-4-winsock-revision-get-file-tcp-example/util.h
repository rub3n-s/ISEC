#include <winsock.h>

#define GET_FILE "get"
#define MAX_MSG_SIZE 100
#define CHUNK_SIZE 1000

int writeN(SOCKET sock,char * buffer,int nbytes);
int readLine(SOCKET sock,char * buffer,int nbytes);